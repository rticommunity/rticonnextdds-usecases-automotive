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


#include "dataObject.h"
#include "Utils.h"

#include "automotive.h"
#include "automotiveSupport.h"
#include "ndds/ndds_cpp.h"

/* Storage for values we need to copy from the control to 
   the status message
 */
static float _vehicle_steer_angle = 0;
static IndicatorStatusEnum _blinker_status = INDICATOR_OFF;

/* Listener */
class Platform_PlatformControlListener : public DDSDataReaderListener {
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

/* On data available processes the incoming samples */
void Platform_PlatformControlListener::on_data_available(DDSDataReader* reader)
{
    Platform_PlatformControlDataReader *Platform_PlatformControl_reader = NULL;
    Platform_PlatformControlSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    Platform_PlatformControl_reader = Platform_PlatformControlDataReader::narrow(reader);
    if (Platform_PlatformControl_reader == NULL) {
        printf("DataReader narrow error\n");
        return;
    }

    /* Read all samples */
    retcode = Platform_PlatformControl_reader->take(
        data_seq, info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    }
    else if (retcode != DDS_RETCODE_OK) {
        printf("take error %d\n", retcode);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) {
        if (info_seq[i].valid_data) {
            /* Print the data and store some data for use in the status message*/
            Platform_PlatformControlTypeSupport::print_data(&data_seq[i]);
            _vehicle_steer_angle = data_seq[i].vehicleSteerAngle;
            _blinker_status = data_seq[i].blinkerStatus;
        }
    }

    retcode = Platform_PlatformControl_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        printf("return loan error %d\n", retcode);
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
    DDSSubscriber *subscriber = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    DDSDataReader *reader = NULL;
    Platform_PlatformControlListener *reader_listener = NULL;
    Platform_PlatformStatusDataWriter * Platform_PlatformStatus_writer = NULL;
    Platform_PlatformStatus *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;  
    int domainId = 0;
    DDS_Duration_t send_period = {4,0};

    /* get the configuration properties */
    PropertyUtil* prop = new PropertyUtil("platform.properties");

    long time = prop->getLongProperty("config.pubInterval");
    send_period.sec = time / 1000;
    send_period.nanosec = (time % 1000) * 1000 * 1000;

    domainId = prop->getLongProperty("config.domainId");

    std::string platformTopicName = prop->getStringProperty("topic.Platform");
    if (platformTopicName == "") {
        printf("No platform topic name specified\n");
        return -1;
    }
    std::string planningTopicName = prop->getStringProperty("topic.Planning");
    if (planningTopicName == "") {
        printf("No planning topic name specified\n");
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
    std::string planningQosProfile = prop->getStringProperty("qos.Planning.Profile");
    if (planningQosProfile == "") {
        printf("No Planning QoS Profile specified\n");
        return -1;
    }
    std::string platformQosProfile = prop->getStringProperty("qos.Platform.Profile");
    if (platformQosProfile == "") {
        printf("No Platform QoS Profile specified\n");
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
        domainId, qosLibrary.c_str(), platformQosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the publisher */
    publisher = participant->create_publisher_with_profile(
        qosLibrary.c_str(), platformQosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        shutdown(participant);
        return -1;
    }

    /* Register the platform status type before creating topic */
    type_name = Platform_PlatformStatusTypeSupport::get_type_name();
    retcode = Platform_PlatformStatusTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        shutdown(participant);
        return -1;
    }

    /* Create the platform status topic */
    topic = participant->create_topic_with_profile(
        platformTopicName.c_str(),
        type_name, qosLibrary.c_str(), platformQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        shutdown(participant);
        return -1;
    }

    /* create the data writer */
    writer = publisher->create_datawriter_with_profile(
        topic, qosLibrary.c_str(), platformQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        shutdown(participant);
        return -1;
    }
    Platform_PlatformStatus_writer = Platform_PlatformStatusDataWriter::narrow(writer);
    if (Platform_PlatformStatus_writer == NULL) {
        printf("DataWriter narrow error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the subscriber */
    subscriber = participant->create_subscriber_with_profile(
        qosLibrary.c_str(), planningQosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        printf("create_subscriber error\n");
        shutdown(participant);
        return -1;
    }

    /* Register the platform control type before creating the topic */
    type_name = Platform_PlatformControlTypeSupport::get_type_name();
    retcode = Platform_PlatformControlTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        shutdown(participant);
        return -1;
    }

    /* Create the platform control topic */
    topic = participant->create_topic_with_profile(
        planningTopicName.c_str(),
        type_name, qosLibrary.c_str(), planningQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the platform control listener
       The listener will process the received samples
     */
    reader_listener = new Platform_PlatformControlListener();

    /* Create the data reader */
    reader = subscriber->create_datareader_with_profile(
        topic, qosLibrary.c_str(), planningQosProfile.c_str(), reader_listener,
        DDS_STATUS_MASK_ALL);
    if (reader == NULL) {
        printf("create_datareader error\n");
        shutdown(participant);
        delete reader_listener;
        return -1;
    }

    /* Create the platform control sample for writing */
    instance = Platform_PlatformStatusTypeSupport::create_data();
    if (instance == NULL) {
        printf("Platform_PlatformStatusTypeSupport::create_data error\n");
        shutdown(participant);
        return -1;
    }


    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        /* Set the timestamp */
		TimestampUtil::getTimestamp(&(instance->timestamp.s), &(instance->timestamp.ns));

        /* set the data. The blinker status and steer angle will 
           be copies of what has been received in the platform 
           control topic. The rest of the data will be filled from 
           the data file. Each time the line will be advanced. If 
           the end of the file is reached the line counter will be 
           set back to the beginning 
         */
        instance->blinkerStatus = _blinker_status;
        instance->vehicleSteerAngle = _vehicle_steer_angle;
        data->get(2, instance->velocity);
        data->get(3, instance->yawRate);
        data->get(4, instance->vehSpd);
        data->get(5, instance->posGasPedal);

        /* send the sample */
        retcode = Platform_PlatformStatus_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }
        /* Advance the data file to the next line*/
        data->nextLine();

        /* Sleep till it is time to send the next status */
        NDDSUtility::sleep(send_period);
    }

  

    /* Delete data sample */
    retcode = Platform_PlatformStatusTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        printf("Platform_PlatformStatusTypeSupport::delete_data error %d\n", retcode);
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

