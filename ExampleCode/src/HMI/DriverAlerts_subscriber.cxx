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

class Alerts_DriverAlertsListener : public DDSDataReaderListener {
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
static int subscriber_shutdown(
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
    DDSTopic *topic = NULL;
    Alerts_DriverAlertsListener *reader_listener = NULL; 
    DDSDataReader *reader = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int count = 0;
    int status = 0;
    int domainId = 0;
    DDSWaitSet *waitset = NULL;
    Alerts_DriverAlertsDataReader *Alerts_DriverAlerts_reader = NULL;
    DDS_Duration_t timeout = { 10, 0 };

    /* Read the properties and configure */
    PropertyUtil* prop = new PropertyUtil("hmi.properties");
    domainId = prop->getLongProperty("config.domainId");
    
    std::string topicName = prop->getStringProperty("topic.Alerts");
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

    /* Create the participant */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), qosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* Create the subscriber */
    subscriber = participant->create_subscriber_with_profile(
        qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        printf("create_subscriber error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* Register the type before creating the topic */
    type_name = Alerts_DriverAlertsTypeSupport::get_type_name();
    retcode = Alerts_DriverAlertsTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        subscriber_shutdown(participant);
        return -1;
    }

    /* Create the alert topic */
    topic = participant->create_topic_with_profile(
        topicName.c_str(),
        type_name, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* Create a data reader listener */
    reader_listener = new Alerts_DriverAlertsListener();

    /* The listener is used for any events other than on data
       available. Since the alerts will pop up a message box
       it is handled as waitset in the main loop using on data 
       available listener would block the receive which we 
       don't want 
     */
    reader = subscriber->create_datareader_with_profile(
        topic, qosLibrary.c_str(), qosProfile.c_str(), reader_listener,
        DDS_STATUS_MASK_ALL & ~DDS_DATA_AVAILABLE_STATUS);
    if (reader == NULL) {
        printf("create_datareader error\n");
        subscriber_shutdown(participant);
        delete reader_listener;
        return -1;
    }

    /* Create status condition
    * ---------------------
    */
    DDSStatusCondition* status_condition = reader->get_statuscondition();
    if (status_condition == NULL) {
        printf("get_statuscondition error\n");
        subscriber_shutdown(participant);
        return -1;
    }
    /* All we are interessted is the on data available*/
    retcode = status_condition->set_enabled_statuses(
        DDS_DATA_AVAILABLE_STATUS);
    if (retcode != DDS_RETCODE_OK) {
        printf("set_enabled_statuses error\n");
        subscriber_shutdown(participant);
        return -1;
    }


    /* Attach condition to waitset
    * ---------------------------
    */
    waitset = new DDSWaitSet();
    if (waitset == NULL) {
        printf("waitset error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* attach status condition to waitset */
    retcode = waitset->attach_condition(status_condition);
    if (retcode != DDS_RETCODE_OK) {
        printf("attach_condition error\n");
        subscriber_shutdown(participant);
        delete waitset;
        return -1;
    }

    /* Narrow data reader to specific type */
    Alerts_DriverAlerts_reader = Alerts_DriverAlertsDataReader::narrow(reader);
    if (Alerts_DriverAlerts_reader == NULL) {
        printf("DataReader narrow error\n");
        subscriber_shutdown(participant);
        delete waitset;
        return -1;
    }

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        Alerts_DriverAlertsSeq data_seq;
        DDS_SampleInfoSeq info_seq;
        DDSConditionSeq active_conditions_seq;

        /* wait() blocks executione until condition becomes ture or timeout */
        retcode = waitset->wait(active_conditions_seq, timeout);

        if (retcode == DDS_RETCODE_TIMEOUT) {
            continue;
        }
        else if (retcode != DDS_RETCODE_OK) {
            printf("wait returned error: %d", retcode);
            break;
        }
        /* Check what caused the wait to return. It can really
           on be the on data available for the alert topic
         */
        int active_conditions = active_conditions_seq.length();

        for (int i = 0; i < active_conditions; i++) {
            if (active_conditions_seq[i] == status_condition) {
                /* Take the data */
                retcode = Alerts_DriverAlerts_reader->take(
                    data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

                if (retcode == DDS_RETCODE_NO_DATA) {
                    continue;
                }
                else if (retcode != DDS_RETCODE_OK) {
                    printf("take error %d\n", retcode);
                }

                /* If we have valid data process it */
                for (i = 0; i < data_seq.length(); ++i) {
                    if (info_seq[i].valid_data) {
                        /* Print the sample for information purpose*/
                        Alerts_DriverAlertsTypeSupport::print_data(&data_seq[i]);

                        /* Pop-up the right message box. On Linux we use SDL2 */
                        if (data_seq[i].backCollision) {
                            MessageBoxUtil::PopUp((char *)"Back Collision Warning", MSGBOX_WARNING);
                        }
                        if (data_seq[i].blindSpotDriver) {
                            MessageBoxUtil::PopUp((char *)"Car in blind spot on driver side", MSGBOX_INFO);
                        }
                        if (data_seq[i].blindSpotPassenger) {
                            MessageBoxUtil::PopUp((char *)"Car in blind spot on passanger side", MSGBOX_INFO);
                        }
                        if (data_seq[i].driverAttention) {
                            MessageBoxUtil::PopUp((char *)"Driver Attention", MSGBOX_ATTENTION);
                        }
                        if (data_seq[i].frontCollision) {
                            MessageBoxUtil::PopUp((char *)"Front Collision Warning", MSGBOX_ATTENTION);
                        }
                        if (data_seq[i].parkingCollision) {
                            MessageBoxUtil::PopUp((char *)"Parking Collision Warning", MSGBOX_WARNING);
                        }
                    }
                }
            }

            retcode = Alerts_DriverAlerts_reader->return_loan(data_seq, info_seq);
            if (retcode != DDS_RETCODE_OK) {
                printf("return loan error %d\n", retcode);
            }

        }
    }

    /* Delete all entities */
    status = subscriber_shutdown(participant);
    delete reader_listener;
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

