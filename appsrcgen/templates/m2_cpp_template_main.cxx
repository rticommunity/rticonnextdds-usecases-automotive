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
* This skeleton file is generated, but is intended to be used
* as a starting point example: modified by the user
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif
{{Loop:Start:Topic:Pub:1}}
#include "wh_sm/wh_sm_history.h"
{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:Sub:1}}
#include "rh_sm/rh_sm_history.h"
{{Loop:End:Topic:Sub:1}}

#include "{{Loop:Line:Topic:True:HeaderFileNameBase}}Support.h"
#include "{{Repl:AppName}}_dp.h"

{{Loop:Start:Topic:DWListener:all}}
class {{Repl:DataTypePathAndNameUnderscored}}DataWriterListener : public DDSDataWriterListener
{
  public:
    {{Repl:DataTypePathAndNameUnderscored}}DataWriterListener() : DDSDataWriterListener() { }
    ~{{Repl:DataTypePathAndNameUnderscored}}DataWriterListener() { }

    virtual void on_publication_matched(
        DDSDataWriter *writer,
        const DDS_PublicationMatchedStatus &status)
    {
        if (status.current_count_change > 0)
        {
            printf("Matched a subscriber\n");
        }
        else if (status.current_count_change < 0)
        {
            printf("Unmatched a subscriber\n");
        }
    }
};

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}
class {{Repl:DataTypePathAndNameUnderscored}}ReaderListener : public DDSDataReaderListener
{
  public:
    DDS_Long total_samples;
    {{Repl:DataTypePathAndNameUnderscored}}ReaderListener()
    {
        total_samples = 0;
    }

    virtual void on_data_available(DDSDataReader *reader);

    virtual void on_subscription_matched(
        DDSDataReader *writer,
        const DDS_SubscriptionMatchedStatus& status)
    {
        if (status.current_count_change > 0)
        {
            printf("Matched a publisher\n");
        }
        else if (status.current_count_change < 0)
        {
            printf("Unmatched a publisher\n");
        }
    }
};

template <typename T>
void {{Repl:DataTypePathAndNameUnderscored}}_take_and_print(typename T::DataReader *reader, DDS_Long *total_samples)
{
    {{Repl:DataTypePathAndNameUnderscored}}Seq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    retcode = reader->take(
        data_seq,
        info_seq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to take data, retcode(%d)\n", retcode);
        goto done;
    }

    for (i = 0; i < data_seq.length(); ++i)
    {
        if (!info_seq[i].valid_data)
        {
            printf("Got metadata. Instance State: %d.\n",
                info_seq[i].instance_state);
        }
        else
        {
            {{Repl:DataTypePathAndNameUnderscored}} *sample;

            sample = data_seq.get_reference(i);
            printf("Data received.\n");
            (*total_samples)++;
        }
    }

    /* Return the loaned data */
    reader->return_loan(data_seq, info_seq);

done:
    {{Repl:DataTypePathAndNameUnderscored}}Seq_finalize(&data_seq);
}

void
{{Repl:DataTypePathAndNameUnderscored}}ReaderListener::on_data_available(DDSDataReader *reader)
{
    {{Repl:DataTypePathAndNameUnderscored}}DataReader *hw_reader = {{Repl:DataTypePathAndNameUnderscored}}DataReader::narrow(reader);
    {{Repl:DataTypePathAndNameUnderscored}}_take_and_print<{{Repl:DataTypePathAndNameUnderscored}}>(hw_reader, &total_samples);
}

{{Loop:End:Topic:DRListener:all}}

int
application_main_w_args(
    DDS_Long domain_id,
    char* udp_intf,
    char* peer,
    DDS_Long sleep_time,
    DDS_Long count)
{
    Application* application;
{{Loop:Start:Topic:Pub:1}}
    DDSPublisher * publisher = NULL;
{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:DWListener:all}}
    DDSDataWriter * {{Repl:DataTypeName}}_datawriter = NULL;
    {{Repl:DataTypePathAndNameUnderscored}}DataWriter *{{Repl:DataTypeName}}_hw_writer = NULL;
    DDS_DataWriterQos {{Repl:DataTypeName}}_dw_qos;
    {{Repl:DataTypePathAndNameUnderscored}} *{{Repl:DataTypeName}}_sample = NULL;
    {{Repl:DataTypePathAndNameUnderscored}}DataWriterListener {{Repl:DataTypeName}}_dw_listener;
{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:Sub:1}}
    DDSSubscriber *subscriber = NULL;
{{Loop:End:Topic:Sub:1}}
{{Loop:Start:Topic:DRListener:all}}
    DDSDataReader *{{Repl:DataTypeName}}_datareader = NULL;
    DDS_DataReaderQos {{Repl:DataTypeName}}_dr_qos;
    {{Repl:DataTypePathAndNameUnderscored}}ReaderListener {{Repl:DataTypeName}}_listener;
{{Loop:End:Topic:DRListener:all}}
{{Loop:Start:Topic:True:all}}
    DDSTopic *{{Repl:DataTypeName}}_topic = NULL;
{{Loop:End:Topic:True:all}}
{{Loop:Start:Topic:True:1}}
    char type_name_tmp[255];
    char topic_name_tmp[255];
    DDS_Long i = 0;
{{Loop:End:Topic:True:1}}
    DDS_ReturnCode_t retcode;
    int ret_value = -1;
{{Loop:Start:Topic:DWListener:all}}
    {{Repl:DataTypeName}}_sample = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport::create_data();
    if ({{Repl:DataTypeName}}_sample == NULL)
    {
        printf("failed {{Repl:DataTypePathAndNameUnderscored}}::create_data()\n");
        goto done;
    }
{{Loop:End:Topic:DWListener:all}}

    application = new Application();
    if (application == NULL)
    {
        printf("failed Application new\n");
        goto done;
    }

    retcode = application->initialize(domain_id, udp_intf, peer);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed Application initialize\n");
        goto done;
    }
    application->sleep_time = sleep_time;
    application->count = count;

    /* register & create topics for each pub|sub */
{{Loop:Start:Topic:True:all}}
    strcpy(type_name_tmp, {{Repl:DataTypePathAndNameUnderscored}}TypeSupport::get_type_name());
    retcode = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport::register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "{{Repl:DataTopicName}}");
    {{Repl:DataTypeName}}_topic = application->participant->create_topic(
        topic_name_tmp,
        type_name_tmp,
        DDS_TOPIC_QOS_DEFAULT,
        NULL,
        DDS_STATUS_MASK_NONE);
    if ({{Repl:DataTypeName}}_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

{{Loop:End:Topic:True:all}}
{{Loop:Start:Topic:Pub:1}}
    publisher = application->participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT,
        NULL,
        DDS_STATUS_MASK_NONE);
    if (publisher == NULL)
    {
        printf("publisher == NULL\n");
        goto done;
    }
{{Loop:End:Topic:Pub:1}}

{{Loop:Start:Topic:DWListener:all}}
    retcode = publisher->get_default_datawriter_qos({{Repl:DataTypeName}}_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed get_default_datawriter_qos\n");
        goto done;
    }

#ifdef USE_RELIABLE_QOS
    {{Repl:DataTypeName}}_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    {{Repl:DataTypeName}}_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif
    {{Repl:DataTypeName}}_dw_qos.resource_limits.max_samples = 32;
    {{Repl:DataTypeName}}_dw_qos.resource_limits.max_samples_per_instance = 32;
    {{Repl:DataTypeName}}_dw_qos.resource_limits.max_instances = 1;
    {{Repl:DataTypeName}}_dw_qos.history.depth = 32;

    {{Repl:DataTypeName}}_datawriter = publisher->create_datawriter(
        {{Repl:DataTypeName}}_topic,
        {{Repl:DataTypeName}}_dw_qos,
        &{{Repl:DataTypeName}}_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);
    if ({{Repl:DataTypeName}}_datawriter == NULL)
    {
        printf("{{Repl:DataTypeName}}_datawriter == NULL\n");
        goto done;
    }

    {{Repl:DataTypeName}}_hw_writer = {{Repl:DataTypePathAndNameUnderscored}}DataWriter::narrow({{Repl:DataTypeName}}_datawriter);
    if ({{Repl:DataTypeName}}_hw_writer == NULL)
    {
        printf("failed datawriter narrow\n");
        goto done;
    }
{{Loop:End:Topic:DWListener:all}}

{{Loop:Start:Topic:Sub:1}}
    subscriber = application->participant->create_subscriber(
        DDS_SUBSCRIBER_QOS_DEFAULT, NULL,
        DDS_STATUS_MASK_NONE);
    if (subscriber == NULL)
    {
        printf("subscriber == NULL\n");
        goto done;
    }
{{Loop:End:Topic:Sub:1}}

{{Loop:Start:Topic:DRListener:all}}
    retcode = subscriber->get_default_datareader_qos({{Repl:DataTypeName}}_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed get_default_datareader_qos\n");
        goto done;
    }

    {{Repl:DataTypeName}}_dr_qos.resource_limits.max_samples = 32;
    {{Repl:DataTypeName}}_dr_qos.resource_limits.max_instances = 1;
    {{Repl:DataTypeName}}_dr_qos.resource_limits.max_samples_per_instance = 32;
    /* if there are more remote writers, you need to increase these limits */
    {{Repl:DataTypeName}}_dr_qos.reader_resource_limits.max_remote_writers = 10;
    {{Repl:DataTypeName}}_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    {{Repl:DataTypeName}}_dr_qos.history.depth = 32;

    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    {{Repl:DataTypeName}}_dr_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    {{Repl:DataTypeName}}_dr_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    {{Repl:DataTypeName}}_datareader = subscriber->create_datareader(
        {{Repl:DataTypeName}}_topic,
        {{Repl:DataTypeName}}_dr_qos,
        &{{Repl:DataTypeName}}_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if ({{Repl:DataTypeName}}_datareader == NULL)
    {
        printf("{{Repl:DataTypeName}}_datareader == NULL\n");
        goto done;
    }
{{Loop:End:Topic:DRListener:all}}

    for (int i = 0; (application->count <= 0) || (i < application->count); ++i)
    {
{{Loop:Start:Topic:DWListener:all}}
        retcode = {{Repl:DataTypeName}}_hw_writer->write(*{{Repl:DataTypeName}}_sample, DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write sample\n");
        }
        else
        {
            printf("Written sample %d\n", (i + 1));
        }
 {{Loop:End:Topic:DWListener:all}}
        printf("Subscriber sleeping for %d msec...\n", application->sleep_time);
        OSAPI_Thread_sleep(application->sleep_time);
    }
    ret_value = 0;

done:

    if (application != NULL)
    {
        delete application;
    }

{{Loop:Start:Topic:DWListener:all}}
    if ({{Repl:DataTypeName}}_sample != NULL)
    {
        {{Repl:DataTypePathAndNameUnderscored}}TypeSupport::delete_data({{Repl:DataTypeName}}_sample);
    }

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}
    if (ret_value == 0)
    {
        printf("Samples received %d\n", {{Repl:DataTypeName}}_listener.total_samples);
        if ({{Repl:DataTypeName}}_listener.total_samples == 0)
        {
            return -1;
        }
    }
{{Loop:End:Topic:DRListener:all}}
    return ret_value;
}

#if !(defined(RTI_VXWORKS) && !defined(__RTP__))
int
main(int argc, char **argv)
{
    DDS_Long i = 0;
    DDS_Long domain_id = 0;
    char *peer = NULL;
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    for (i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-domain"))
        {
            ++i;
            if (i == argc)
            {
                printf("-domain <domain_id>\n");
                return -1;
            }
            domain_id = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-udp_intf"))
        {
            ++i;
            if (i == argc)
            {
                printf("-udp_intf <interface>\n");
                return -1;
            }
            udp_intf = argv[i];
        }
        else if (!strcmp(argv[i], "-peer"))
        {
            ++i;
            if (i == argc)
            {
                printf("-peer <address>\n");
                return -1;
            }
            peer = argv[i];
        }
        else if (!strcmp(argv[i], "-sleep"))
        {
            ++i;
            if (i == argc)
            {
                printf("-sleep_time <sleep_time>\n");
                return -1;
            }
            sleep_time = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-count"))
        {
            ++i;
            if (i == argc)
            {
                printf("-count <count>\n");
                return -1;
            }
            count = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-h"))
        {
            Application::help(argv[0]);
            return 0;
        }
        else
        {
            printf("unknown option: %s\n", argv[i]);
            return -1;
        }
    }

    return application_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#elif defined(RTI_VXWORKS)
int
application_main(void)
{
    /* Explicitly configure args below */
    DDS_Long domain_id = 0;
    char *peer = "127.0.0.1";
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    return application_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif