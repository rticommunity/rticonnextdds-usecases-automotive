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
#include "Utils.h"
#include "automotive.h"
#include "automotiveSupport.h"
#include "ndds/ndds_cpp.h"

/* Vision sensor listener to print any status information received
   on data available is handled in the main loop */
class Vision_VisionSensorListener : public DDSDataReaderListener {
public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {
        printf("on_requested_deadline_missed\n");
    }

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {
        printf("on_requested_incompatible_qos\n");
    }

    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {
        printf("on_sample_rejected\n");
    }

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {
        printf("on_liveliness_changed\n");
    }

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {
        printf("on_sample_lost\n");
    }

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {
        printf("on_subscription_matched\n");
    }

    virtual void on_data_available(DDSDataReader* reader) {}
};

/* Lidar listener. The on data available call back will print
   the timestamp for each received data. The rest of the data
   is ignored
 */
class sensor_msgs_msg_dds__PointCloud2_Listener : public DDSDataReaderListener {
public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {
        printf("on_requested_deadline_missed\n");
    }

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {
        printf("on_requested_incompatible_qos\n");
    }

    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {
        printf("on_sample_rejected\n");
    }

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {
        printf("on_liveliness_changed\n");
    }

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {
        printf("on_sample_lost\n");
    }

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {
        printf("on_subscription_matched\n");
    }

    virtual void on_data_available(DDSDataReader* reader);
};

void sensor_msgs_msg_dds__PointCloud2_Listener::on_data_available(DDSDataReader* reader)
{
    sensor_msgs_msg_dds__PointCloud2_DataReader *sensor_msgs_msg_dds__PointCloud2__reader = NULL;
    sensor_msgs_msg_dds__PointCloud2_Seq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    sensor_msgs_msg_dds__PointCloud2__reader = sensor_msgs_msg_dds__PointCloud2_DataReader::narrow(reader);
    if (sensor_msgs_msg_dds__PointCloud2__reader == NULL) {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }

    retcode = sensor_msgs_msg_dds__PointCloud2__reader->take(
        data_seq, info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    }
    else if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }

    int dsLen = data_seq.length();
    for (i = 0; i < dsLen; ++i) {
        if (info_seq[i].valid_data) {
            printf("Received %d dds sample with %d points; t = %d.%d\n",
                dsLen, 
                data_seq[i].data_.length(),
                data_seq[i].header_.stamp_.sec_,
                data_seq[i].header_.stamp_.nanosec_
            );
            // sensor_msgs_msg_dds__PointCloud2_TypeSupport::print_data(&data_seq[i]);
            
        }
    }

    retcode = sensor_msgs_msg_dds__PointCloud2__reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}


/* Delete all entities */
static int shutdown(
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
    Sensor_SensorObjectListDataWriter * Sensor_SensorObjectList_writer = NULL;
    Sensor_SensorObjectList *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;  
    int domainId = 0;
    DDS_Duration_t send_period = {4,0};
    DDSSubscriber *subscriber = NULL;
    sensor_msgs_msg_dds__PointCloud2_Listener *lidar_listener = NULL;
    Vision_VisionSensorListener *vision_listener = NULL;
    DDSDataReader *reader = NULL;
    Vision_VisionSensorDataReader *Vision_VisionSensor_reader = NULL;
    Vision_VisionSensorSeq vision_data_seq;
    DDS_SampleInfoSeq info_seq;
    int numObjects = 0;

    /* get the configuration parameters */
    PropertyUtil* prop = new PropertyUtil("sensor_fusion.properties");

    long time = prop->getLongProperty("config.pubInterval");
    send_period.sec = time / 1000;
    send_period.nanosec = (time % 1000) * 1000 * 1000;

    domainId = prop->getLongProperty("config.domainId");

    std::string visionTopicName = prop->getStringProperty("topic.VisionSensor");
    if (visionTopicName == "") {
        printf("No vision sensor topic name specified\n");
        return -1;
    }
    std::string lidarTopicName = prop->getStringProperty("topic.Lidar");
    if (lidarTopicName == "") {
        printf("No lidar sensor topic name specified\n");
        return -1;
    }
    std::string sensorTopicName = prop->getStringProperty("topic.out");
    if (sensorTopicName == "") {
        printf("No sensor fusion output topic name specified\n");
        return -1;
    }

    std::string qosLibrary = prop->getStringProperty("qos.Library");
    if (qosLibrary == "") {
        printf("No QoS Library specified\n");
        return -1;
    }
    std::string visionQosProfile = prop->getStringProperty("qos.vision.Profile");
    if (visionQosProfile == "") {
        printf("No QoS Profile for vision sensor subscriber specified\n");
        return -1;
    }
    std::string lidarQosProfile = prop->getStringProperty("qos.lidar.Profile");
    if (lidarQosProfile == "") {
        printf("No QoS Profile for lidar subscriber specified\n");
        return -1;
    }
    std::string sensorQosProfile = prop->getStringProperty("qos.out.Profile");
    if (sensorQosProfile == "") {
        printf("No QoS Profile for sensor fusion publisher specified\n");
        return -1;
    }

    /* Create the participant */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), sensorQosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        shutdown(participant);
        return -1;
    }


    /* Create the publisher */
    publisher = participant->create_publisher_with_profile(
        qosLibrary.c_str(), sensorQosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = Sensor_SensorObjectListTypeSupport::get_type_name();
    retcode = Sensor_SensorObjectListTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        shutdown(participant);
        return -1;
    }

    /* Create the sensor object topic */
    topic = participant->create_topic_with_profile(
        sensorTopicName.c_str(),
        type_name, qosLibrary.c_str(), sensorQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the sensor object writer */
    writer = publisher->create_datawriter_with_profile(
        topic, qosLibrary.c_str(), sensorQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        shutdown(participant);
        return -1;
    }
    Sensor_SensorObjectList_writer = Sensor_SensorObjectListDataWriter::narrow(writer);
    if (Sensor_SensorObjectList_writer == NULL) {
        printf("DataWriter narrow error\n");
        shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    instance = Sensor_SensorObjectListTypeSupport::create_data();
    if (instance == NULL) {
        printf("Sensor_SensorObjectListTypeSupport::create_data error\n");
        shutdown(participant);
        return -1;
    }

    /* Vision Sensor Subscriber */
    subscriber = participant->create_subscriber_with_profile(
        qosLibrary.c_str(), visionQosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        printf("create_subscriber error\n");
        shutdown(participant);
        return -1;
    }

    /* Register the Vision Sensor type*/
    type_name = Vision_VisionSensorTypeSupport::get_type_name();
    retcode = Vision_VisionSensorTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        shutdown(participant);
        return -1;
    }

    /* Create the Vision Sensor topic */
    topic = participant->create_topic_with_profile(
        visionTopicName.c_str(),
        type_name, qosLibrary.c_str(), visionQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the vison sensor reader listener */
    vision_listener = new Vision_VisionSensorListener();

    /* Create the reader. The listener will only subscribe to 
       status events other than on data available. The main loop 
       will poll for data from the sensor and collect them into
       the sensor object list
     */
    reader = subscriber->create_datareader_with_profile(
        topic, qosLibrary.c_str(), visionQosProfile.c_str(), vision_listener,
        DDS_STATUS_MASK_ALL & ~~DDS_DATA_AVAILABLE_STATUS);
    if (reader == NULL) {
        printf("create_datareader error\n");
        shutdown(participant);
        return -1;
    }

    Vision_VisionSensor_reader = Vision_VisionSensorDataReader::narrow(reader);
    if (Vision_VisionSensor_reader == NULL) {
        printf("Vision DataReader narrow error\n");
        return -1;
    }

    /* Register the Lidar data type */
    type_name = sensor_msgs_msg_dds__PointCloud2_TypeSupport::get_type_name();
    retcode = sensor_msgs_msg_dds__PointCloud2_TypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        shutdown(participant);
        return -1;
    }

    /* Create the lidar topic */
    topic = participant->create_topic_with_profile(
        lidarTopicName.c_str(),
        type_name, qosLibrary.c_str(), lidarQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        shutdown(participant);
        return -1;
    }

    /* Create LiDAR listener */
    lidar_listener = new sensor_msgs_msg_dds__PointCloud2_Listener();

    /* Create the lidar reader. The listener will handle the 
       received samples so no processing of lidar samples
       needed in the main loop. 
     */
    reader = subscriber->create_datareader_with_profile(
        topic, qosLibrary.c_str(), lidarQosProfile.c_str(), lidar_listener,
        DDS_STATUS_MASK_ALL);
    if (reader == NULL) {
        printf("create_datareader error\n");
        shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    instance = Sensor_SensorObjectListTypeSupport::create_data();
    if (instance == NULL) {
        printf("Sensor_SensorObjectListTypeSupport::create_data error\n");
        shutdown(participant);
        return -1;
    }

    /* Set the sequence maximum to the maximum so we can fill the list */
    instance->objects.maximum(Sensor_SENSOR_OBJECT_LIST_MAX_SIZE);


    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {
        /* set the timestamp */
		TimestampUtil::getTimestamp(&(instance->timestamp.s), &(instance->timestamp.ns));


        /* Get all the vision sensor data */
        retcode = Vision_VisionSensor_reader->take(
            vision_data_seq, info_seq, DDS_LENGTH_UNLIMITED,
            DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

        numObjects = 0;
        instance->objects.length(Sensor_SENSOR_OBJECT_LIST_MAX_SIZE);
        for (int i = 0; i < vision_data_seq.length(); i++) {
            if (info_seq[i].valid_data) {
                /* copy all the objects from all received vision sensor samples into the objects list
                   as long as there is space.
                 */  
                for (int j = 0; j < vision_data_seq[i].objects.length(); j++) {
                    if (numObjects < Sensor_SENSOR_OBJECT_LIST_MAX_SIZE) {
                        instance->objects[numObjects].position[0] = vision_data_seq[i].objects[j].position[0];
                        instance->objects[numObjects].position[1] = vision_data_seq[i].objects[j].position[1];
                        instance->objects[numObjects].position[2] = vision_data_seq[i].objects[j].position[2];
                        instance->objects[numObjects].velocity[0] = vision_data_seq[i].objects[j].velocity[0];
                        instance->objects[numObjects].velocity[1] = vision_data_seq[i].objects[j].velocity[0];
                        instance->objects[numObjects].velocity[2] = vision_data_seq[i].objects[j].velocity[0];
                        instance->objects[numObjects].size[0] = vision_data_seq[i].objects[j].size[0];
                        instance->objects[numObjects].size[1] = vision_data_seq[i].objects[j].size[1];
                        instance->objects[numObjects].size[2] = vision_data_seq[i].objects[j].size[2];
                        instance->objects[numObjects].classification = vision_data_seq[i].objects[j].classification;

                        numObjects++;
                    }
                }
            }
            retcode = Vision_VisionSensor_reader->return_loan(vision_data_seq, info_seq);
            if (retcode != DDS_RETCODE_OK) {
                printf("return loan error %d\n", retcode);
            }
            
        }
        /* set the sequence length to as many as we actually have */
        instance->objects.length(numObjects);

        /* And publish it*/
        retcode = Sensor_SensorObjectList_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }

        /* Wait*/
        NDDSUtility::sleep(send_period);
    }


    /* Delete data sample */
    retcode = Sensor_SensorObjectListTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        printf("Sensor_SensorObjectListTypeSupport::delete_data error %d\n", retcode);
    }

    /* Delete all entities */
    return shutdown(participant);
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

