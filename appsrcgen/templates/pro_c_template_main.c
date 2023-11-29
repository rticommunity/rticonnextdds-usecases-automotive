/*
* (c) Copyright, Real-Time Innovations, 2022.  All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/
/* {{Repl:AppName}}_main.c
* An application skeleton using the following DDS data types:
*   {{Loop:Line:Topic:True:DataTypePathAndName}}
* This skeleton file is generated, but intended to be used 
* as a starting point example: modified by the user
*/

#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"
#include "{{Loop:Line:Topic:True:HeaderFileNameBase}}Support.h"

{{Loop:Start:Topic:DRListener:all}}
void {{Repl:DataTypePathAndNameUnderscored}}Listener_on_requested_deadline_missed(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_RequestedDeadlineMissedStatus *status)
{
}

void {{Repl:DataTypePathAndNameUnderscored}}Listener_on_requested_incompatible_qos(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_RequestedIncompatibleQosStatus *status)
{
}

void {{Repl:DataTypePathAndNameUnderscored}}Listener_on_sample_rejected(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_SampleRejectedStatus *status)
{
}

void {{Repl:DataTypePathAndNameUnderscored}}Listener_on_liveliness_changed(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_LivelinessChangedStatus *status)
{
}

void {{Repl:DataTypePathAndNameUnderscored}}Listener_on_sample_lost(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_SampleLostStatus *status)
{
}

void {{Repl:DataTypePathAndNameUnderscored}}Listener_on_subscription_matched(
    void* listener_data,
    DDS_DataReader* reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
}

void {{Repl:DataTypePathAndNameUnderscored}}Listener_on_data_available(
    void* listener_data,
    DDS_DataReader* reader)
{
    {{Repl:DataTypePathAndNameUnderscored}}DataReader *{{Repl:DataTypePathAndNameUnderscored}}_reader = NULL;
    struct {{Repl:DataTypePathAndNameUnderscored}}Seq data_seq = DDS_SEQUENCE_INITIALIZER;
    struct DDS_SampleInfoSeq info_seq = DDS_SEQUENCE_INITIALIZER;
    DDS_ReturnCode_t retcode;
    int i;

    {{Repl:DataTypePathAndNameUnderscored}}_reader = {{Repl:DataTypePathAndNameUnderscored}}DataReader_narrow(reader);
    if ({{Repl:DataTypePathAndNameUnderscored}}_reader == NULL) {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }

    retcode = {{Repl:DataTypePathAndNameUnderscored}}DataReader_take(
        {{Repl:DataTypePathAndNameUnderscored}}_reader,
        &data_seq, &info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);
    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    } else if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }

    for (i = 0; i < {{Repl:DataTypePathAndNameUnderscored}}Seq_get_length(&data_seq); ++i) {
        if (DDS_SampleInfoSeq_get_reference(&info_seq, i)->valid_data) {
            printf("Received data\n");
            {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_print_data(
                {{Repl:DataTypePathAndNameUnderscored}}Seq_get_reference(&data_seq, i));
        }
    }

    retcode = {{Repl:DataTypePathAndNameUnderscored}}DataReader_return_loan(
        {{Repl:DataTypePathAndNameUnderscored}}_reader,
        &data_seq, &info_seq);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}
{{Loop:End:Topic:DRListener:all}}

/* Delete all entities */
static int app_dds_shutdown(
    DDS_DomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = DDS_DomainParticipant_delete_contained_entities(participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDS_DomainParticipantFactory_delete_participant(
            DDS_TheParticipantFactory, participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Data Distribution Service provides the finalize_instance() method on
    domain participant factory for users who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*
    retcode = DDS_DomainParticipantFactory_finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode);
        status = -1;
    }
    */

    return status;
}

int application_main(int domainId, int sample_count)
{
    DDS_DomainParticipant *participant = NULL;
{{Loop:Start:Topic:Pub:1}}	
    DDS_Publisher *publisher = NULL;
{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:Sub:1}}
    DDS_Subscriber *subscriber = NULL;
{{Loop:End:Topic:Sub:1}}
{{Loop:Start:Topic:Pub:all}}
    DDS_Topic *{{Repl:DataTopicName}}_topic = NULL;
    DDS_DataWriter *{{Repl:DataTypePathAndNameUnderscored}}_datawriter = NULL;
    {{Repl:DataTypePathAndNameUnderscored}}DataWriter *{{Repl:DataTypePathAndNameUnderscored}}_writer = NULL;
    {{Repl:DataTypePathAndNameUnderscored}} *{{Repl:DataTypePathAndNameUnderscored}}_instance = NULL;
    DDS_InstanceHandle_t {{Repl:DataTypePathAndNameUnderscored}}_instance_handle = DDS_HANDLE_NIL;
{{Loop:End:Topic:Pub:all}}
{{Loop:Start:Topic:Sub:all}}
    struct DDS_DataReaderListener {{Repl:DataTypePathAndNameUnderscored}}_reader_listener = DDS_DataReaderListener_INITIALIZER;
    DDS_DataReader *{{Repl:DataTypePathAndNameUnderscored}}_reader = NULL;
    DDS_Topic *{{Repl:DataTopicName}}_topic = NULL;
{{Loop:End:Topic:Sub:all}}
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int count = 0;
    struct DDS_Duration_t loop_period = {1,0};

    /* To customize participant QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    participant = DDS_DomainParticipantFactory_create_participant(
        DDS_TheParticipantFactory, domainId, &DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error\n");
        app_dds_shutdown(participant);
        return -1;
    }

{{Loop:Start:Topic:Pub:1}}	
    /* To customize publisher QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    publisher = DDS_DomainParticipant_create_publisher(
        participant, &DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        fprintf(stderr, "create_publisher error\n");
        app_dds_shutdown(participant);
        return -1;
    }
{{Loop:End:Topic:Pub:1}}	
{{Loop:Start:Topic:Sub:1}}	
    /* To customize subscriber QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    subscriber = DDS_DomainParticipant_create_subscriber(
        participant, &DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        fprintf(stderr, "create_subscriber error\n");
        app_dds_shutdown(participant);
        return -1;
    }
{{Loop:End:Topic:Sub:1}}	

{{Loop:Start:Topic:True:all}}	
    /* Register the type before creating the topic */
    type_name = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_get_type_name();
    retcode = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_register_type(participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d\n", retcode);
        app_dds_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    {{Repl:DataTopicName}}_topic = DDS_DomainParticipant_create_topic(
        participant, "Example_{{Repl:DataTypePathAndNameUnderscored}}",
        type_name, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if ({{Repl:DataTopicName}}_topic == NULL) {
        fprintf(stderr, "create_topic error\n");
        app_dds_shutdown(participant);
        return -1;
    }

{{Loop:End:Topic:True:all}}	
{{Loop:Start:Topic:Pub:all}}	
    /* To customize data writer QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    {{Repl:DataTypePathAndNameUnderscored}}_datawriter = DDS_Publisher_create_datawriter(
        publisher, {{Repl:DataTopicName}}_topic,
        &DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if ({{Repl:DataTypePathAndNameUnderscored}}_datawriter == NULL) {
        fprintf(stderr, "create_datawriter error\n");
        app_dds_shutdown(participant);
        return -1;
    }
    {{Repl:DataTypePathAndNameUnderscored}}_writer = {{Repl:DataTypePathAndNameUnderscored}}DataWriter_narrow({{Repl:DataTypePathAndNameUnderscored}}_datawriter);
    if ({{Repl:DataTypePathAndNameUnderscored}}_writer == NULL) {
        fprintf(stderr, "DataWriter narrow error\n");
        app_dds_shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    {{Repl:DataTypePathAndNameUnderscored}}_instance = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_create_data_ex(DDS_BOOLEAN_TRUE);
    if ({{Repl:DataTypePathAndNameUnderscored}}_instance == NULL) {
        fprintf(stderr, "{{Repl:DataTypePathAndNameUnderscored}}TypeSupport_create_data error\n");
        app_dds_shutdown(participant);
        return -1;
    }

    /* For a data type that has a key, if the same instance is going to be
    written multiple times, initialize the key here
    and register the keyed instance prior to writing */
    /*
    {{Repl:DataTypePathAndNameUnderscored}}_instance_handle = {{Repl:DataTypePathAndNameUnderscored}}DataWriter_register_instance(
        {{Repl:DataTypePathAndNameUnderscored}}_writer, {{Repl:DataTypePathAndNameUnderscored}}_instance);
    */

{{Loop:End:Topic:Pub:all}}	

{{Loop:Start:Topic:Sub:all}}	
    /* Set up a data reader listener */
    {{Repl:DataTypePathAndNameUnderscored}}_reader_listener.on_requested_deadline_missed  =
        {{Repl:DataTypePathAndNameUnderscored}}Listener_on_requested_deadline_missed;
    {{Repl:DataTypePathAndNameUnderscored}}_reader_listener.on_requested_incompatible_qos =
        {{Repl:DataTypePathAndNameUnderscored}}Listener_on_requested_incompatible_qos;
    {{Repl:DataTypePathAndNameUnderscored}}_reader_listener.on_sample_rejected =
        {{Repl:DataTypePathAndNameUnderscored}}Listener_on_sample_rejected;
    {{Repl:DataTypePathAndNameUnderscored}}_reader_listener.on_liveliness_changed =
        {{Repl:DataTypePathAndNameUnderscored}}Listener_on_liveliness_changed;
    {{Repl:DataTypePathAndNameUnderscored}}_reader_listener.on_sample_lost =
        {{Repl:DataTypePathAndNameUnderscored}}Listener_on_sample_lost;
    {{Repl:DataTypePathAndNameUnderscored}}_reader_listener.on_subscription_matched =
        {{Repl:DataTypePathAndNameUnderscored}}Listener_on_subscription_matched;
    {{Repl:DataTypePathAndNameUnderscored}}_reader_listener.on_data_available =
        {{Repl:DataTypePathAndNameUnderscored}}Listener_on_data_available;

    /* To customize data reader QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    {{Repl:DataTypePathAndNameUnderscored}}_reader = DDS_Subscriber_create_datareader(
        subscriber, DDS_Topic_as_topicdescription({{Repl:DataTopicName}}_topic),
        &DDS_DATAREADER_QOS_DEFAULT, &{{Repl:DataTypePathAndNameUnderscored}}_reader_listener, DDS_STATUS_MASK_ALL);
    if ({{Repl:DataTypePathAndNameUnderscored}}_reader == NULL) {
        fprintf(stderr, "create_datareader error\n");
        app_dds_shutdown(participant);
        return -1;
    }
{{Loop:End:Topic:Sub:all}}	

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {
{{Loop:Start:Topic:Pub:all}}	
        /* Modify the data to be written here */

        /* Write data */
        retcode = {{Repl:DataTypePathAndNameUnderscored}}DataWriter_write(
            {{Repl:DataTypePathAndNameUnderscored}}_writer, {{Repl:DataTypePathAndNameUnderscored}}_instance, &{{Repl:DataTypePathAndNameUnderscored}}_instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "write error %d\n", retcode);
        }
{{Loop:End:Topic:Pub:all}}	
        printf("{{Repl:AppName}} sleeping for %d sec...\n", loop_period.sec);

        NDDS_Utility_sleep(&loop_period);
    }

{{Loop:Start:Topic:Pub:all}}	
    /*
    retcode = {{Repl:DataTypePathAndNameUnderscored}}DataWriter_unregister_instance(
        {{Repl:DataTypePathAndNameUnderscored}}_writer, {{Repl:DataTypePathAndNameUnderscored}}_instance, &{{Repl:DataTypePathAndNameUnderscored}}_instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "unregister instance error %d\n", retcode);
    }
    */
    /* Delete data sample */
    retcode = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_delete_data_ex({{Repl:DataTypePathAndNameUnderscored}}_instance, DDS_BOOLEAN_TRUE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "{{Repl:DataTypePathAndNameUnderscored}}TypeSupport_delete_data error %d\n", retcode);
    }
{{Loop:End:Topic:Pub:all}}	
    /* Cleanup and delete all entities */ 	
    return app_dds_shutdown(participant);
}

int main(int argc, char *argv[])
{
    int domain_id = 0;
    int sample_count = 0; /* infinite loop */

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    /* Uncomment this to turn on additional logging
    NDDS_Config_Logger_set_verbosity_by_category(
        NDDS_Config_Logger_get_instance(),
        NDDS_CONFIG_LOG_CATEGORY_API, 
        NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */

    return application_main(domain_id, sample_count);
}

