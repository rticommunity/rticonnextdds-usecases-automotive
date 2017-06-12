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
#include <cstdlib>
#include <time.h>


#include "Utils.h"

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

    return status;
}

extern "C" int publisher_main(int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    Lidar_LidarSensorDataWriter * Lidar_LidarSensor_writer = NULL;
    Lidar_LidarSensor *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0; 
    int domainId = 0;
    DDS_Duration_t send_period = {4,0};


    /* Get the properties and configure it */
    PropertyUtil* prop = new PropertyUtil("lidar.properties");

    long period = prop->getLongProperty("config.pubInterval");
    send_period.sec = period / 1000;
    send_period.nanosec = (period % 1000) * 1000 * 1000;

    domainId = prop->getLongProperty("config.domainId");
    std::string topicName = prop->getStringProperty("topic.Sensor");
    if (topicName == "") {
        printf("No topic name specified\n");
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

    /* Initialize the random number generator */
    srand(time(NULL));

    /* Create the participant */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), qosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create the publisher. Since the topic is larger the 
       QoS has to be set to use asynchronous publisher
     */
    publisher = participant->create_publisher_with_profile(
        qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = Lidar_LidarSensorTypeSupport::get_type_name();
    retcode = Lidar_LidarSensorTypeSupport::register_type(
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

    /* Create the data writer */
    writer = publisher->create_datawriter_with_profile(
        topic, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }
    Lidar_LidarSensor_writer = Lidar_LidarSensorDataWriter::narrow(writer);
    if (Lidar_LidarSensor_writer == NULL) {
        printf("DataWriter narrow error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    instance = Lidar_LidarSensorTypeSupport::create_data();
    if (instance == NULL) {
        printf("Lidar_LidarSensorTypeSupport::create_data error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Fill the sample with random data. We fill it to the maximum */
    instance->ptCloud.Location.length(Lidar_MAX_POINTS);
    instance->ptCloud.Location.maximum(Lidar_MAX_POINTS);
    for (int p = 0; p < Lidar_MAX_POINTS; p++) {
        instance->ptCloud.Location[p].point[0] = (float) rand() / 10;
        instance->ptCloud.Location[p].point[1] = (float) rand() / 10;
        instance->ptCloud.Location[p].point[2] = (float) rand() / 10;
    }

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        /* Set the timestamp */
        TimestampUtil::getTimestamp(&(instance->timestamp.s), &(instance->timestamp.ns));

        /* create random data */
        instance->ptCloud.color = count % 255;
        instance->ptCloud.count = Lidar_MAX_POINTS;
        instance->ptCloud.intensity = (float) rand() / 1000;
        instance->ptCloud.normal = (float) rand() / 1000;
        instance->ptCloud.xLimits[0] = (float) rand();
        instance->ptCloud.xLimits[1] = (float) rand();
        instance->ptCloud.yLimits[0] = (float) rand();
        instance->ptCloud.yLimits[1] = (float) rand();
        instance->ptCloud.zLimits[0] = (float) rand();
        instance->ptCloud.zLimits[1] = (float) rand();

        /* And send it */
        retcode = Lidar_LidarSensor_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }

        NDDSUtility::sleep(send_period);
    }



    /* Delete data sample */
    retcode = Lidar_LidarSensorTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        printf("Lidar_LidarSensorTypeSupport::delete_data error %d\n", retcode);
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

