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


/* Generic listener class which will print a message if any of the 
   status events like deadline missed occur. The listener will be 
   used for the sensor data as well as platform status
 */
class Generic_Listener : public DDSDataReaderListener {
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

extern "C" int subscriber_main(int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSSubscriber *subscriber = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    //Platform_PlatformControlListener *reader_listener = NULL; 
    DDSDataReader *sensor_reader = NULL;
    DDSDataReader *platform_reader = NULL;
    Platform_PlatformStatusDataReader *platformStatus_reader = NULL;
    Sensor_SensorObjectListDataReader *sensorObjects_reader = NULL;
    DDSDataWriter *writer = NULL;
    Platform_PlatformControlDataWriter *platformControl_writer = NULL;
    Alerts_DriverAlertsDataWriter *alerts_writer = NULL;
    Alerts_DriverAlerts *alerts_instance = NULL;
    Platform_PlatformControl *control_instance = NULL;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    Generic_Listener *listener = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int count = 0;
    DDS_Duration_t period = {4,0};
    int status = 0;
    int domainId = 0;
    int seq = 0;
    DDSWaitSet *waitset = NULL;

    /* Open the properties file and read the configuration */ 
    /* The domain will default to zero and the send interval 
       to 4 seconds if they are not specified. If the topic name 
       or profiles are not specified the application will exit
     */
    PropertyUtil* prop = new PropertyUtil("collision_avoidance.properties");

    long time = prop->getLongProperty("config.pubInterval");
    period.sec = time / 1000;
    period.nanosec = (time % 1000) * 1000 * 1000;

    domainId = prop->getLongProperty("config.domainId");

    std::string sensorTopicName = prop->getStringProperty("topic.Sensor");
    if (sensorTopicName == "") {
        printf("No Sensor topic name specified\n");
        return -1;
    }
    std::string platformTopicName = prop->getStringProperty("topic.Platform");
    if (platformTopicName == "") {
        printf("No platform topic name specified\n");
        return -1;
    }
    std::string controlTopicName = prop->getStringProperty("topic.Control");
    if (controlTopicName == "") {
        printf("No control output topic name specified\n");
        return -1;
    }
    std::string alertTopicName = prop->getStringProperty("topic.Alert");
    if (alertTopicName == "") {
        printf("No driver alert topic name specified\n");
        return -1;
    }
    std::string qosLibrary = prop->getStringProperty("qos.Library");
    if (qosLibrary == "") {
        printf("No QoS Library specified\n");
        return -1;
    }
    std::string sensorQosProfile = prop->getStringProperty("qos.Sensor.Profile");
    if (sensorQosProfile == "") {
        printf("No QoS Profile for sensor subscriber specified\n");
        return -1;
    }
    std::string platformQosProfile = prop->getStringProperty("qos.Platform.Profile");
    if (platformQosProfile == "") {
        printf("No QoS Profile for platform subscriber specified\n");
        return -1;
    }
    std::string controlQosProfile = prop->getStringProperty("qos.Control.Profile");
    if (controlQosProfile == "") {
        printf("No QoS Profile for platform control publisher specified\n");
        return -1;
    }
    std::string alertQosProfile = prop->getStringProperty("qos.Alert.Profile");
    if (alertQosProfile == "") {
        printf("No QoS Profile for driver alert control publisher specified\n");
        return -1;
    }

    /* Create the participant with the specified profile */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), controlQosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        shutdown(participant);
        return -1;
    }

    /* Create a subscriber */
    subscriber = participant->create_subscriber_with_profile(
        qosLibrary.c_str(), platformQosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        printf("create_subscriber error\n");
        shutdown(participant);
        return -1;
    }

    /* Register the type before creating the topic */
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
        printf("create platform Status topic error\n");
        shutdown(participant);
        return -1;
    }

    /* Create a data reader listener which will be used for the 
       sensor data and platform status listener
     */
    listener = new Generic_Listener();

    /* Create the data reader. Since we are using waitsets to receive
       samples the listener will only be enabled for status. On data 
       available will handeled by the waitset in the main loop
     */
    platform_reader = subscriber->create_datareader_with_profile(
        topic, qosLibrary.c_str(), platformQosProfile.c_str(), listener,
        DDS_STATUS_MASK_NONE & ~DDS_DATA_AVAILABLE_STATUS);
    if (platform_reader == NULL) {
        printf("create_datareader error\n");
        shutdown(participant);
        return -1;
    }

    platformStatus_reader = Platform_PlatformStatusDataReader::narrow(platform_reader);
    if (platformStatus_reader == NULL) {
        printf("DataReader narrow error\n");
        shutdown(participant);
        return -1;
    }

    /* Register the sensor object type */
    type_name = Sensor_SensorObjectListTypeSupport::get_type_name();
    retcode = Sensor_SensorObjectListTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        shutdown(participant);
        return -1;
    }

    /* Create the Sensor Object topic */
    topic = participant->create_topic_with_profile(
        sensorTopicName.c_str(),
        type_name, qosLibrary.c_str(), sensorQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create Sensor Object Topic topic error\n");
        shutdown(participant);
        return -1;
    }


    /* Create the data reader. Since we are using waitsets to receive
       samples the listener will only be enabled for status. On data 
       available will handeled by the waitset in the main loop
     */
    sensor_reader = subscriber->create_datareader_with_profile(
        topic, qosLibrary.c_str(), sensorQosProfile.c_str(), listener,
        DDS_STATUS_MASK_NONE & ~DDS_DATA_AVAILABLE_STATUS);
    if (sensor_reader == NULL) {
        printf("create_datareader error\n");
        shutdown(participant);
        return -1;
    }
    sensorObjects_reader = Sensor_SensorObjectListDataReader::narrow(sensor_reader);
    if (sensorObjects_reader == NULL) {
        printf("DataReader narrow error\n");
        shutdown(participant);
        return -1;
    }

    /* Now we create the publisher */
    publisher = participant->create_publisher_with_profile(
        qosLibrary.c_str(), controlQosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        shutdown(participant);
        return -1;
    }

    /* Register platform control type before creating topic */
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
        controlTopicName.c_str(),
        type_name, qosLibrary.c_str(), platformQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create platform control topic error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the platform control data writer */
    writer = publisher->create_datawriter_with_profile(
        topic, qosLibrary.c_str(), platformQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        shutdown(participant);
        return -1;
    }
    platformControl_writer = Platform_PlatformControlDataWriter::narrow(writer);
    if (platformControl_writer == NULL) {
        printf("DataWriter narrow error\n");
        shutdown(participant);
        return -1;
    }

    /* Register the driver alert type */
    type_name = Alerts_DriverAlertsTypeSupport::get_type_name();
    retcode = Alerts_DriverAlertsTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        shutdown(participant);
        return -1;
    }

    /* Now that the type is registered create the alert topic */
    topic = participant->create_topic_with_profile(
        alertTopicName.c_str(),
        type_name, qosLibrary.c_str(), alertQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create driver alert topic error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the alert data writer */
    writer = publisher->create_datawriter_with_profile(
        topic, qosLibrary.c_str(), alertQosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        shutdown(participant);
        return -1;
    }
    alerts_writer = Alerts_DriverAlertsDataWriter::narrow(writer);
    if (alerts_writer == NULL) {
        printf("DataWriter narrow error\n");
        shutdown(participant);
        return -1;
    }

    /* Create status condition
    * ---------------------
    */
    /* Create the platform control status condition */
    DDSStatusCondition* platform_status_condition = platform_reader->get_statuscondition();
    if (platform_status_condition == NULL) {
        printf("get_statuscondition error\n");
        shutdown(participant);
        return -1;
    }

    /* Enable on data available for the platform status */
    retcode = platform_status_condition->set_enabled_statuses(
        DDS_DATA_AVAILABLE_STATUS);
    if (retcode != DDS_RETCODE_OK) {
        printf("set_enabled_statuses error\n");
        shutdown(participant);
        return -1;
    }

    /* Create the sensor objects status condition */
    DDSStatusCondition* sensor_status_condition = sensor_reader->get_statuscondition();
    if (sensor_status_condition == NULL) {
        printf("get_statuscondition error\n");
        shutdown(participant);
        return -1;
    }

    /*Enable on data available for the Sensor objects */
    retcode = sensor_status_condition->set_enabled_statuses(
        DDS_DATA_AVAILABLE_STATUS);
    if (retcode != DDS_RETCODE_OK) {
        printf("set_enabled_statuses error\n");
        shutdown(participant);
        return -1;
    }

    /* Attach condition to waitset
    * ---------------------------
    */
    waitset = new DDSWaitSet();
    if (waitset == NULL) {
        printf("waitset error\n");
        shutdown(participant);
        return -1;
    }

    /* attach status condition to waitset */
    retcode = waitset->attach_condition(platform_status_condition);
    if (retcode != DDS_RETCODE_OK) {
        printf("attach_condition error\n");
        shutdown(participant);
        delete waitset;
        return -1;
    }

    /* attach status condition to waitset */
    retcode = waitset->attach_condition(sensor_status_condition);
    if (retcode != DDS_RETCODE_OK) {
        printf("attach_condition error\n");
        shutdown(participant);
        delete waitset;
        return -1;
    }

    /* Create data sample for writing */
    control_instance = Platform_PlatformControlTypeSupport::create_data();
    if (control_instance == NULL) {
        printf("Platform_PlatformControlTypeSupport::create_data error\n");
        shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    alerts_instance = Alerts_DriverAlertsTypeSupport::create_data();
    if (alerts_instance == NULL) {
        printf("Alerts_DriverAlertsTypeSupport::create_data error\n");
        shutdown(participant);
        return -1;
    }


    /* Main loop */
    bool alert_sent = false; /* Flag if alert has been sent or not*/

    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        Platform_PlatformStatusSeq platform_data_seq;
        Sensor_SensorObjectListSeq sensor_data_seq;
        DDS_SampleInfoSeq info_seq;
        DDSConditionSeq active_conditions_seq;

        /* wait() blocks executione until condition becomes true or timeout */
        retcode = waitset->wait(active_conditions_seq, period);

        /* If the waitset returns with status timeout we go back and wait again*/
        if (retcode == DDS_RETCODE_TIMEOUT) {
            continue;
        }
        else if (retcode != DDS_RETCODE_OK) {
            printf("wait returned error: %d", retcode);
            break;
        }

        /* Get the active conditions which will tell which on data
           available triggered the wait to return
          */
        int active_conditions = active_conditions_seq.length();

        /* Set the timestamp */
		TimestampUtil::getTimestamp(&(control_instance->timestamp.s), &(control_instance->timestamp.ns));


        /* Process the active conditions */
        for (int i = 0; i < active_conditions; i++) {
            /* We received an on data available for the platform status */
            if (active_conditions_seq[i] == platform_status_condition) {

                /* Let's take the data and process it */
                retcode = platformStatus_reader->take(platform_data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

                if (retcode == DDS_RETCODE_NO_DATA) {
                    continue;
                }
                else if (retcode != DDS_RETCODE_OK) {
                    printf("take error %d\n", retcode);
                }

                for (int i = 0; i < platform_data_seq.length(); ++i) {
                    if (info_seq[i].valid_data) {
                        /* We don't do anything with the platform status */
                    }
                }
                /* Return the memory loan */
                retcode = platformStatus_reader->return_loan(platform_data_seq, info_seq);
                if (retcode != DDS_RETCODE_OK) {
                    printf("return loan error %d\n", retcode);
                }

            }

            /* Check for sensor data objects */
            if (active_conditions_seq[i] == sensor_status_condition) {

                /* Read the sensor objects */
                retcode = sensorObjects_reader->take(sensor_data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

                if (retcode == DDS_RETCODE_NO_DATA) {
                    continue;
                }
                else if (retcode != DDS_RETCODE_OK) {
                    printf("take error %d\n", retcode);
                }

                /* Process all the sensor objects */
                for (int i = 0; i < sensor_data_seq.length(); ++i) {
                    if (info_seq[i].valid_data) {
                        for (int j = 0; j < sensor_data_seq[i].objects.length(); j++) {

                            /* As an example if size[1] of an object is greater than
                               2 we issue a driver alert*/
                            if (sensor_data_seq[i].objects[j].size[1] > 2.0) {
                                alerts_instance->backCollision = 0;
                                alerts_instance->blindSpotDriver = 0;
                                alerts_instance->blindSpotPassenger = 0;
                                alerts_instance->driverAttention = 1;
                                alerts_instance->frontCollision = 0;
                                alerts_instance->parkingCollision = 0;
                                /* Write the alert and set the flag to true */
                                retcode = alerts_writer->write(*alerts_instance, instance_handle);
                                if (retcode != DDS_RETCODE_OK) {
                                    printf("write error %d\n", retcode);
                                }
                                alert_sent = true;
                            }
                            else if (alert_sent == true) {
                                /* if we issued an alert and the size value is less than 2
                                   clear the alert */
                                alerts_instance->backCollision = 0;
                                alerts_instance->blindSpotDriver = 0;
                                alerts_instance->blindSpotPassenger = 0;
                                alerts_instance->driverAttention = 0;
                                alerts_instance->frontCollision = 0;
                                alerts_instance->parkingCollision = 0;

                                retcode = alerts_writer->write(*alerts_instance, instance_handle);
                                if (retcode != DDS_RETCODE_OK) {
                                    printf("write error %d\n", retcode);
                                }
                                alert_sent = false;
                            }
                        }
                        /* Some random data copy into the platform control. No real algorithm 
                           just to get data changing 
                         */
                        control_instance->sample_id = seq++;
                        if (sensor_data_seq[i].objects.length() > 0) {
                        control_instance->blinkerStatus = IndicatorStatusEnum(sensor_data_seq[i].objects[0].classification % 4);
                            control_instance->speed = sensor_data_seq[i].objects[0].velocity[0];
                            control_instance->vehicleSteerAngle = sensor_data_seq[i].objects[0].position[0];
                        }
                        /* Send the platform control */
                        retcode = platformControl_writer->write(*control_instance, instance_handle);
                        if (retcode != DDS_RETCODE_OK) {
                            printf("write error %d\n", retcode);
                        }

                    }
                }
                retcode = sensorObjects_reader->return_loan(sensor_data_seq, info_seq);
                if (retcode != DDS_RETCODE_OK) {
                    printf("return loan error %d\n", retcode);
                }
            }
        }
    }

    /* Delete all entities */
    status = shutdown(participant);
    delete waitset;

    return status;
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

    return subscriber_main(sample_count);
}

