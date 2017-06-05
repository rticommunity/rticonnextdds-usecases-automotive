/****************************************************************************
(c) 2005-2017 Copyright, Real-Time Innovations, Inc.  All rights reserved.    	                             
RTI grants Licensee a license to use, modify, compile, and create derivative 
works of the Software.  Licensee has the right to distribute object form 
only for use with RTI products.  The Software is provided 'as is', with no
arranty of any type, including any warranty for fitness for any purpose. RTI
is under no obligation to maintain or support the Software.  RTI shall not
be liable for any incidental or consequential damages arising out of the 
use or inability to use the software.
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#ifdef RTI_LINUX
#include <sys/time.h>
#endif

#include "dataObject.h"
#include "propertyUtil.h"

#include "automotive.h"
#include "automotiveSupport.h"
#include "ndds/ndds_cpp.h"

/* Delete all entities */
static int publisher_shutdown(
    DDSDomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Connext provides finalize_instance() method on
    domain participant factory for people who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("finalize_instance error %d\n", retcode);
        status = -1;
    }
    */

    return status;
}

extern "C" int publisher_main(int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    Vision_VisionSensorDataWriter * Vision_VisionSensor_writer = NULL;
    Vision_VisionSensor *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;  
    int domainId = 0;
    int sensorId = 0;
    DDS_Duration_t send_period = {4,0};

    /* Get the configurtion properties */
    PropertyUtil* prop = new PropertyUtil("vision.properties");

    long time = prop->getLongProperty("config.pubInterval");
    send_period.sec = time / 1000;
    send_period.nanosec = (time % 1000) * 1000 * 1000;

    domainId = prop->getLongProperty("config.domainId");
    sensorId = prop->getLongProperty("config.sensorId");
    std::string topicName = prop->getStringProperty("topic.Sensor");
    if (topicName == "") {
        printf("No topic name specified\n");
        return -1;
    }
    std::string dataFileName = prop->getStringProperty("dataFile");
    if (dataFileName == "") {
        printf("No data file specified\n");
        return -1;
    }
    std::string qosLibrary = prop->getStringProperty("qos.Library");
    if (qosLibrary == "") {
        printf("No QoS Library specified\n");
        return -1;
    }
    std::string qosProfile = prop->getStringProperty("qos.Profile");
    if (qosProfile == "") {
        printf("No QoS Profile specified\n");
        return -1;
    }

    /* Intialize the data file. The dat afrom the file will be
    filled into the sample */
    DataObject* data = new DataObject(dataFileName);
    if (data->line() == 0) {
        printf("Data file has invalid format. No data found\n");
        return -1;
    }

    /* Create the participant */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), qosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create the publisher */
    publisher = participant->create_publisher_with_profile(
        qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = Vision_VisionSensorTypeSupport::get_type_name();
    retcode = Vision_VisionSensorTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        publisher_shutdown(participant);
        return -1;
    }

    /* Create the topic */
    topic = participant->create_topic_with_profile(
        topicName.c_str(),
        type_name, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create the writer */
    writer = publisher->create_datawriter_with_profile(
        topic, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }
    Vision_VisionSensor_writer = Vision_VisionSensorDataWriter::narrow(writer);
    if (Vision_VisionSensor_writer == NULL) {
        printf("DataWriter narrow error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    instance = Vision_VisionSensorTypeSupport::create_data();
    if (instance == NULL) {
        printf("Vision_VisionSensorTypeSupport::create_data error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* set the sensor instance ID. Each sensor will have a unique
       ID and data from each sensor will be a different instance
     */
    instance->id = sensorId;

    /* For a data type that has a key, if the same instance is going to be
    written multiple times, initialize the key here
    and register the keyed instance prior to writing */
    instance_handle = Vision_VisionSensor_writer->register_instance(*instance);

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        /* Set the timestamp */
#ifdef WIN32
        {
            static const uint64_t EPOCH = ((uint64_t)116444736000000000ULL);

            SYSTEMTIME  system_time;
            FILETIME    file_time;
            uint64_t    time;
            GetSystemTime(&system_time);
            SystemTimeToFileTime(&system_time, &file_time);
            time = ((uint64_t)file_time.dwLowDateTime);
            time += ((uint64_t)file_time.dwHighDateTime) << 32;

            instance->timestamp.s = (long)((time - EPOCH) / 10000000L);
            instance->timestamp.ns = (long)(system_time.wMilliseconds * 1000);
        }
#endif
#ifdef RTI_LINUX
        {
            struct timeval tp;
            gettimeofday(&tp, NULL);
            instance->timestamp.s  = tp.tv_sec;
            instance->timestamp.ns = tp.tv_usec * 1000;
        }
#endif

        int last = data->elements() - 1;
        int len = 0;
        int idx;

        /* The last element in the csv file has the number of objects*/
        data->get(last, len);
        /* set the object sequence length */
        instance->objects.length(len);
        instance->objects.maximum(Vision_VISION_OBJECT_LIST_MAX_SIZE);

        /* Copy the data from the file into the sample */
        for (int i = 0; i < len; i++) {
            idx = i * 11;
            int enum_val = 0;
            data->get(idx + 3, enum_val);
            instance->objects[i].classification = classificationEnum(enum_val);
            data->get(idx + 4, instance->objects[i].position[0]);
            data->get(idx + 5, instance->objects[i].position[1]);
            data->get(idx + 6, instance->objects[i].position[2]);
            data->get(idx + 7, instance->objects[i].velocity[0]);
            data->get(idx + 8, instance->objects[i].velocity[1]);
            data->get(idx + 9, instance->objects[i].velocity[2]);
            data->get(idx + 10, instance->objects[i].size[0]);
            data->get(idx + 11, instance->objects[i].size[1]);
            data->get(idx + 12, instance->objects[i].size[2]);
        }

        /* and send ythe sample */
        retcode = Vision_VisionSensor_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }
        /* Go to the next line on the data file.  If the end of the file
           is reached the line counter will be set back to the beginning
         */
        data->nextLine();

        /* Sleep until it is time to send the next sample*/
        NDDSUtility::sleep(send_period);
    }

    retcode = Vision_VisionSensor_writer->unregister_instance(
        *instance, instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        printf("unregister instance error %d\n", retcode);
    }


    /* Delete data sample */
    retcode = Vision_VisionSensorTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        printf("Vision_VisionSensorTypeSupport::delete_data error %d\n", retcode);
    }

    /* Delete all entities */
    return publisher_shutdown(participant);
}

int main(int argc, char *argv[])
{
    int sample_count = 0; /* infinite loop */

    if (argc >= 2) {
        sample_count = atoi(argv[1]);
    }

    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
    set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
    NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */

    return publisher_main(sample_count);
}

