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
* as a starting point example and modified by the user
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rti_me_c.h"
{{Loop:Start:Topic:Pub:1}}
#include "wh_sm/wh_sm_history.h"
{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:Sub:1}}
#include "rh_sm/rh_sm_history.h"
{{Loop:End:Topic:Sub:1}}
/* include the type support headers for the needed data types */
#include "{{Loop:Line:Topic:True:HeaderFileNameBase}}Support.h"
#include "{{Repl:AppName}}_dp.h"

{{Loop:Start:Topic:Pub:1}}
/* DATA WRITER LISTENERS: called when pub is matched to a subscriber */
{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:DWListener:all}}
void
{{Repl:DataTypePathAndNameUnderscored}}Publisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a {{Repl:DataTopicName}}({{Repl:DataTypeName}}) subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a {{Repl:DataTopicName}}({{Repl:DataTypeName}}) subscriber\n");
    }
}

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:Sub:1}}
/* DATA READER LISTENERS: callbacks when sub is matched to a publisher,
    and when data is received */
{{Loop:End:Topic:Sub:1}}
{{Loop:Start:Topic:DRListener:all}}
#ifdef USE_SAMPLE_FILTER
#ifdef FILTER_ON_DESERIALIZE

/* See Wire Protocol Specification on http://www.omg.org/spec/DDSI-RTPS/2.2/
* for more details about CDR encapsulation.
*/


/*i
* \brief Helper function to deserialize an unsigned long
*
* \param[in]  src_buffer      Pointer to CDR stream buffer
* \param[in]  need_byte_swap  Indicates whether it is needed to swap bytes
* \param[out] instance        Deserialized unsigned long
*/
void
{{Repl:DataTypePathAndNameUnderscored}}Subscriber_deserialize_unsigned_long(
    char **src_buffer,
    RTI_BOOL need_byte_swap,
    DDS_UnsignedLong *instance)
{
    RTI_INT32 i;
    if (need_byte_swap)
    {
        for (i = 3; i >= 0; --i)
        {
            *((RTI_INT8*)instance + i) = *((*src_buffer)++);
        }
    }
    else
    {
        *instance = *(RTI_UINT32*)(*src_buffer);
        (*src_buffer) += CDR_LONG_SIZE;
    }
}

/*i
* \brief Implementation of \ref DDS_DataReaderListener::on_before_sample_deserialize
*/
DDS_Boolean
{{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_before_sample_deserialize(
    void *listener_data,
    DDS_DataReader *reader,
    struct NDDS_Type_Plugin *plugin,
    struct CDR_Stream_t *stream,
    DDS_Boolean *dropped)
{
    DDS_Boolean result = DDS_BOOLEAN_FALSE;
    DDS_Long id = 0;
    RTI_BOOL need_byte_swap = DDS_BOOLEAN_FALSE;
    char *src_buffer = NULL;

    need_byte_swap = CDR_Stream_is_byte_swapped(stream);
    src_buffer = CDR_Stream_get_current_position_ptr(stream);

    /* deserialize only field 'id', instead of the whole sample */

    if (!CDR_Stream_check_size(stream, UNSIGNED_LONG_SIZE))
    {
        printf("Failed to deserialize id. The stream is too short, missing data\n");
        goto done;
    }

    /* Note primitive types must be aligned to their length in the CDR stream.
    * For example, a long must start on a 4-byte boundary. The boundaries are
    * counted from the start of the CDR stream.
    * As the sample 'id' is the first data in the stream it is already aligned.
    * Position 0 (beginning of the stream) is aligned to 4 (size of long).
    *
    * NOTE: If you want to use a different field for filtering (e.g. you type does
    * not have a field called id as first field), you will need to reimplement this
    * function and {{Repl:DataTypePathAndNameUnderscored}}Subscriber_deserialize_unsigned_long
    * to match your type.
    */
    {{Repl:DataTypePathAndNameUnderscored}}Subscriber_deserialize_unsigned_long(
        &src_buffer,
        need_byte_swap,
        (DDS_UnsignedLong*)&id);

    /* filter the sample */
    *dropped = (id % 2 == 0) ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;

    if (*dropped)
    {
        printf("\nSample filtered, before deserialize...\n\tDROPPED - id: %d\n", id);
    }

    result = DDS_BOOLEAN_TRUE;
    done:
    return result;
}

#else

/*i
* \brief Helper function to filter an {{Repl:DataTypePathAndNameUnderscored}} sample
*
* \param[in]  sample       A {{Repl:DataTypePathAndNameUnderscored}} data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void 
{{Repl:DataTypePathAndNameUnderscored}}Subscriber_filter_sample(
    {{Repl:DataTypePathAndNameUnderscored}} *sample,
    DDS_Boolean *drop_sample)
{
    /* Example filter: drop samples with even-numbered count in id */
    /* NOTE: If field "id" does not exist in your data type, change "id"
    * by the field you want to use for filtering.
    */
    *drop_sample = (sample->id % 2 == 0) ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;
}

/*i
* \brief Implementation of \ref DDS_DataReaderListener::on_before_sample_commit
*/
DDS_Boolean
{{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    {{Repl:DataTypePathAndNameUnderscored}} *hw_sample = ({{Repl:DataTypePathAndNameUnderscored}} *)sample; 

    {{Repl:DataTypePathAndNameUnderscored}}Subscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}
#endif /* FILTER_ON_DESERIALIZE */
#endif /* USE_SAMPLE_FILTER */

void
{{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_subscription_matched(
    void *listener_data,
    DDS_DataReader *reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a {{Repl:DataTopicName}}({{Repl:DataTypeName}}) publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a {{Repl:DataTopicName}}({{Repl:DataTypeName}}) publisher\n");
    }
}

void
{{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_data_available(
    void *listener_data,
    DDS_DataReader * reader)
{
    {{Repl:DataTypePathAndNameUnderscored}}DataReader *hw_reader = {{Repl:DataTypePathAndNameUnderscored}}DataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    {{Repl:DataTypePathAndNameUnderscored}} *sample = NULL;

    struct DDS_SampleInfoSeq info_seq = 
    DDS_SEQUENCE_INITIALIZER;
    struct {{Repl:DataTypePathAndNameUnderscored}}Seq sample_seq = 
    DDS_SEQUENCE_INITIALIZER;

    DDS_Long i;
    DDS_Long *total_samples = (DDS_Long*) listener_data;

    retcode = {{Repl:DataTypePathAndNameUnderscored}}DataReader_take(
        hw_reader, 
        &sample_seq,
        &info_seq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK)
    {
        printf("  failed to take {{Repl:DataTopicName}}({{Repl:DataTypeName}}) data, retcode(%d)\n", retcode);
        goto done;
    }

    /* Print each valid sample taken */
    for (i = 0; i < {{Repl:DataTypePathAndNameUnderscored}}Seq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = {{Repl:DataTypePathAndNameUnderscored}}Seq_get_reference(&sample_seq, i);
            printf("  Valid {{Repl:DataTopicName}}({{Repl:DataTypeName}}) sample received\n");
            *total_samples += 1;

            /* TODO read and process sample attributes here */ 

        }
        else
        {
            printf("  {{Repl:DataTopicName}}({{Repl:DataTypeName}}) sample received\tINVALID DATA\n");
        }
    }

    {{Repl:DataTypePathAndNameUnderscored}}DataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
#ifndef RTI_CERT
    {{Repl:DataTypePathAndNameUnderscored}}Seq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
#else  /* RTI_CERT */
    return;
#endif  /* RTI_CERT */
}

{{Loop:End:Topic:DRListener:all}}

/* main loop of the application ---------------------------- */
int
application_main_w_args(
    DDS_Long domain_id,
    char *udp_intf,
    char *peer,
    DDS_Long sleep_time,
    DDS_Long count)
{
    struct Application *application = NULL;
{{Loop:Start:Topic:Pub:1}}
    DDS_Publisher *publisher;
{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:DWListener:all}}
    DDS_DataWriter *{{Repl:DataTypeName}}_datawriter;
    {{Repl:DataTypePathAndNameUnderscored}}DataWriter *{{Repl:DataTypeName}}_hw_datawriter;
    struct DDS_DataWriterQos {{Repl:DataTypeName}}_dw_qos = DDS_DataWriterQos_INITIALIZER;
    {{Repl:DataTypePathAndNameUnderscored}} *{{Repl:DataTypeName}}_sample = NULL;

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:Sub:1}}
    DDS_Subscriber *subscriber;
{{Loop:End:Topic:Sub:1}}
{{Loop:Start:Topic:DRListener:all}}
    DDS_DataReader *{{Repl:DataTypeName}}_datareader;
    struct DDS_DataReaderQos {{Repl:DataTypeName}}_dr_qos = DDS_DataReaderQos_INITIALIZER;
{{Loop:End:Topic:DRListener:all}}
{{Loop:Start:Topic:DWListener:all}}

    struct DDS_DataWriterListener {{Repl:DataTypeName}}_dw_listener = DDS_DataWriterListener_INITIALIZER;
    {{Repl:DataTypeName}}_sample = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_create_data();
    if ({{Repl:DataTypeName}}_sample == NULL)
    {
        printf("failed {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_create_data\n");
        return -1;
    }
{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}
    struct DDS_DataReaderListener {{Repl:DataTypeName}}_dr_listener = DDS_DataReaderListener_INITIALIZER;
{{Loop:End:Topic:DRListener:all}}
    DDS_ReturnCode_t retcode;

    int ret_value = -1;
    DDS_Long total_samples = 0;
    DDS_Long i = 0;

    /* create and init the DDS domain participant */
    application = Application_create(domain_id, udp_intf, peer);
    if (application == NULL)
    {
        printf("domain participant creation error\n");
        goto done;
    }
    application->sleep_time = sleep_time;
    application->count = count;

{{Loop:Start:Topic:True:1}}
    /* register & create topics for each pub|sub */
    char type_name_tmp[255];
    char topic_name_tmp[255];
{{Loop:End:Topic:True:1}}
{{Loop:Start:Topic:True:all}}
    /* {{Repl:DataTypeName}} topic */
    DDS_Topic *{{Repl:DataTypeName}}_topic;
    strcpy(type_name_tmp, {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_get_type_name());
    retcode = {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "{{Repl:DataTopicName}}");
    {{Repl:DataTypeName}}_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if ({{Repl:DataTypeName}}_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

{{Loop:End:Topic:True:all}}
{{Loop:Start:Topic:Pub:1}}
    /* create a publisher ---------------------- */
    publisher = DDS_DomainParticipant_create_publisher(
        application->participant,
        &DDS_PUBLISHER_QOS_DEFAULT,
        NULL,
        DDS_STATUS_MASK_NONE);
    if (publisher == NULL)
    {
        printf("publisher == NULL\n");
        goto done;
    }

{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:DWListener:all}}
    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    {{Repl:DataTypeName}}_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    {{Repl:DataTypeName}}_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    {{Repl:DataTypeName}}_dw_qos.resource_limits.max_samples_per_instance = 32;
    {{Repl:DataTypeName}}_dw_qos.resource_limits.max_instances = 2;
    {{Repl:DataTypeName}}_dw_qos.resource_limits.max_samples = {{Repl:DataTypeName}}_dw_qos.resource_limits.max_instances *
        {{Repl:DataTypeName}}_dw_qos.resource_limits.max_samples_per_instance;
    {{Repl:DataTypeName}}_dw_qos.history.depth = 32;
    {{Repl:DataTypeName}}_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    {{Repl:DataTypeName}}_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    {{Repl:DataTypeName}}_dw_listener.on_publication_matched = {{Repl:DataTypePathAndNameUnderscored}}Publisher_on_publication_matched;

    /* create a datawriter for this topic */
    {{Repl:DataTypeName}}_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        {{Repl:DataTypeName}}_topic,
        &{{Repl:DataTypeName}}_dw_qos,
        &{{Repl:DataTypeName}}_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);
    if ({{Repl:DataTypeName}}_datawriter == NULL)
    {
        printf("{{Repl:DataTypeName}}_datawriter == NULL\n");
        goto done;
    }

    {{Repl:DataTypeName}}_hw_datawriter = {{Repl:DataTypePathAndNameUnderscored}}DataWriter_narrow({{Repl:DataTypeName}}_datawriter);
{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:Sub:1}}
    /* create a subscriber ---------------------- */
    subscriber = DDS_DomainParticipant_create_subscriber(
        application->participant,
        &DDS_SUBSCRIBER_QOS_DEFAULT,
        NULL,
        DDS_STATUS_MASK_NONE);
    if (subscriber == NULL)
    {
        printf("subscriber == NULL\n");
        goto done;
    }

{{Loop:End:Topic:Sub:1}}
{{Loop:Start:Topic:DRListener:all}}
    /* Publisher sends samples with id = 0 or id = 1, so 2 instances maximum.
    * But in case filtering is done, all samples with 'id = 0' are
    * filtered so only one instance is needed.
    */
#ifdef USE_SAMPLE_FILTER
    {{Repl:DataTypeName}}_dr_qos.resource_limits.max_instances = 1;
#else  /* USE_SAMPLE_FILTER */
    {{Repl:DataTypeName}}_dr_qos.resource_limits.max_instances = 2;
#endif  /* USE_SAMPLE_FILTER */

    {{Repl:DataTypeName}}_dr_qos.resource_limits.max_samples_per_instance = 32;
    {{Repl:DataTypeName}}_dr_qos.resource_limits.max_samples = {{Repl:DataTypeName}}_dr_qos.resource_limits.max_instances *
        {{Repl:DataTypeName}}_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    {{Repl:DataTypeName}}_dr_qos.reader_resource_limits.max_remote_writers = 10;
    {{Repl:DataTypeName}}_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    {{Repl:DataTypeName}}_dr_qos.history.depth = 32;

{{Loop:End:Topic:DRListener:all}}
{{Loop:Start:Topic:DRListener:all}}
#ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
#ifdef FILTER_ON_DESERIALIZE
    {{Repl:DataTypeName}}_dr_listener.on_before_sample_deserialize =
        {{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_before_sample_deserialize;
#else  /* FILTER_ON_DESERIALIZE */
    {{Repl:DataTypeName}}_dr_listener.on_before_sample_commit =
        {{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_before_sample_commit;
#endif  /* FILTER_ON_DESERIALIZE */
#endif  /* USE_SAMPLE_FILTER */

    {{Repl:DataTypeName}}_dr_listener.on_data_available = {{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_data_available;
    {{Repl:DataTypeName}}_dr_listener.on_subscription_matched =
        {{Repl:DataTypePathAndNameUnderscored}}Subscriber_on_subscription_matched;

    {{Repl:DataTypeName}}_dr_listener.as_listener.listener_data = &total_samples;

    {{Repl:DataTypeName}}_datareader = DDS_Subscriber_create_datareader(
        subscriber,
        DDS_Topic_as_topicdescription({{Repl:DataTypeName}}_topic),
        &{{Repl:DataTypeName}}_dr_qos,
        &{{Repl:DataTypeName}}_dr_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if ({{Repl:DataTypeName}}_datareader == NULL)
    {
        printf("{{Repl:DataTypeName}}_datareader == NULL\n");
        goto done;
    }
	
{{Loop:End:Topic:DRListener:all}}
#ifdef RTI_CERT
#ifdef RTI_VXWORKS
    /** End initialization, disable further dynamic memory allocation ***/
    memAllocDisable();
#endif  /* RTI_VXWORKS */
#endif  /* RTI_CERT */

    /* loop ---------------- */
    for (i = 0; (application->count <= 0) || (i < application->count); ++i)
    {
        /* TODO set *_sample values/attributes here */

{{Loop:Start:Topic:DWListener:all}}
        retcode = {{Repl:DataTypePathAndNameUnderscored}}DataWriter_write(
            {{Repl:DataTypeName}}_hw_datawriter,
            {{Repl:DataTypeName}}_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write {{Repl:DataTopicName}}({{Repl:DataTypeName}}) sample\n");
        } 
        else
        {
            printf("Written {{Repl:DataTopicName}}({{Repl:DataTypeName}}) sample %d\n",(i+1));
        }
		
{{Loop:End:Topic:DWListener:all}}
        printf("Subscriber sleeping for %d msec...\n", sleep_time);

        OSAPI_Thread_sleep(application->sleep_time);
    }

    /* Finished; clean up and exit */
    ret_value = 0;
done:

#ifndef RTI_CERT
    if (application != NULL)
    {
        Application_delete(application);
    }

{{Loop:Start:Topic:DWListener:all}}
    if ({{Repl:DataTypeName}}_sample != NULL)
    {
        {{Repl:DataTypePathAndNameUnderscored}}TypeSupport_delete_data({{Repl:DataTypeName}}_sample);
    }
{{Loop:End:Topic:DWListener:all}}

#endif  /* RTI_CERT */
#ifndef RTI_CERT
{{Loop:Start:Topic:DWListener:all}}
    retcode = DDS_DataWriterQos_finalize(&{{Repl:DataTypeName}}_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize {{Repl:DataTopicName}} DataWriterQos\n");
        return -1;
    }
{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}	
    retcode = DDS_DataReaderQos_finalize(&{{Repl:DataTypeName}}_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize {{Repl:DataTopicName}} DataReaderQos\n");
        return -1;
    }
{{Loop:End:Topic:DRListener:all}}
#endif  /* RTI_CERT */
    if (ret_value == 0)
    {
        printf("Samples received %d\n", total_samples);
        if (total_samples == 0)
        {
            return -1;
        }
    }

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
            Application_help(argv[0]);
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
#endif  /* defined(RTI_VXWORKS) */
