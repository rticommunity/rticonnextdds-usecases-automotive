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
/* localization_main.c
* An application skeleton using the following DDS data types:
*   dds::perception::ObjectsDetected
*   dds::sensing::gnss::Basic
*   dds::perception::Trajectory
*   dds::physics::Pose3D_real
* This skeleton file is generated, but intended to be used
* as a starting point example: modified by the user
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
/* include the type support headers for the needed data types */
#include "res/types/data/rti/perception/Object_tSupport.h"
#include "res/types/data/rti/sensing/Gnss_tSupport.h"
#include "res/types/data/rti/perception/Trajectory_tSupport.h"
#include "res/types/data/rti/physics/Pose3D_tSupport.h"
#include "localization_dp.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"

/* Helper functions (added in) -------------------------------- */
/* returns random float values within a specified range */
float randFloatInRange(float low, float high)
{
    float rval = ((float) rand() / (float)RAND_MAX);
    float rspan = high-low;
    return low + (rval * rspan);
}
/* end added-in helper functions ------------------------------- */

void
dds_physics_Pose3D_realPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a Pose3D subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a Pose3D subscriber\n");
    }
}

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
dds_perception_ObjectsDetectedSubscriber_deserialize_unsigned_long(
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
dds_perception_ObjectsDetectedSubscriber_on_before_sample_deserialize(
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
    * function and dds_perception_ObjectsDetectedSubscriber_deserialize_unsigned_long
    * to match your type.
    */
    dds_perception_ObjectsDetectedSubscriber_deserialize_unsigned_long(
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
* \brief Helper function to filter an dds_perception_ObjectsDetected sample
*
* \param[in]  sample       A dds_perception_ObjectsDetected data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void
dds_perception_ObjectsDetectedSubscriber_filter_sample(
    dds_perception_ObjectsDetected *sample,
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
dds_perception_ObjectsDetectedSubscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    dds_perception_ObjectsDetected *hw_sample = (dds_perception_ObjectsDetected *)sample;

    dds_perception_ObjectsDetectedSubscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}
#endif /* FILTER_ON_DESERIALIZE */
#endif /* USE_SAMPLE_FILTER */

void
dds_perception_ObjectsDetectedSubscriber_on_subscription_matched(
    void *listener_data,
    DDS_DataReader *reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a ObjectsDetected publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a ObjectsDetected publisher\n");
    }
}

void
dds_perception_ObjectsDetectedSubscriber_on_data_available(
    void *listener_data,
    DDS_DataReader * reader)
{
    dds_perception_ObjectsDetectedDataReader *hw_reader = dds_perception_ObjectsDetectedDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    dds_perception_ObjectsDetected *sample = NULL;

    struct DDS_SampleInfoSeq info_seq =
    DDS_SEQUENCE_INITIALIZER;
    struct dds_perception_ObjectsDetectedSeq sample_seq = DDS_SEQUENCE_INITIALIZER;

    DDS_Long i;
    DDS_Long *total_samples = (DDS_Long*) listener_data;

    retcode = dds_perception_ObjectsDetectedDataReader_take(
        hw_reader,
        &sample_seq,
        &info_seq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to take data, retcode(%d)\n", retcode);
        goto done;
    }

    /* Print each valid sample taken */
    for (i = 0; i < dds_perception_ObjectsDetectedSeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = dds_perception_ObjectsDetectedSeq_get_reference(&sample_seq, i);
            printf("  Valid ObjectsDetected sample received(%u)\n", sample->parent.id[0]);
            *total_samples += 1;

            /* TODO read and process sample attributes here */

        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    dds_perception_ObjectsDetectedDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
#ifndef RTI_CERT
    dds_perception_ObjectsDetectedSeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
#else  /* RTI_CERT */
    return;
#endif  /* RTI_CERT */
}

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
dds_sensing_gnss_BasicSubscriber_deserialize_unsigned_long(
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
dds_sensing_gnss_BasicSubscriber_on_before_sample_deserialize(
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
    * function and dds_sensing_gnss_BasicSubscriber_deserialize_unsigned_long
    * to match your type.
    */
    dds_sensing_gnss_BasicSubscriber_deserialize_unsigned_long(
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
* \brief Helper function to filter an dds_sensing_gnss_Basic sample
*
* \param[in]  sample       A dds_sensing_gnss_Basic data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void
dds_sensing_gnss_BasicSubscriber_filter_sample(
    dds_sensing_gnss_Basic *sample,
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
dds_sensing_gnss_BasicSubscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    dds_sensing_gnss_Basic *hw_sample = (dds_sensing_gnss_Basic *)sample;

    dds_sensing_gnss_BasicSubscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}
#endif /* FILTER_ON_DESERIALIZE */
#endif /* USE_SAMPLE_FILTER */

void
dds_sensing_gnss_BasicSubscriber_on_subscription_matched(
    void *listener_data,
    DDS_DataReader *reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a GNSS publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a GNSS publisher\n");
    }
}

void
dds_sensing_gnss_BasicSubscriber_on_data_available(
    void *listener_data,
    DDS_DataReader * reader)
{
    dds_sensing_gnss_BasicDataReader *hw_reader = dds_sensing_gnss_BasicDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    dds_sensing_gnss_Basic *sample = NULL;

    struct DDS_SampleInfoSeq info_seq =
    DDS_SEQUENCE_INITIALIZER;
    struct dds_sensing_gnss_BasicSeq sample_seq =
    DDS_SEQUENCE_INITIALIZER;

    DDS_Long i;
    DDS_Long *total_samples = (DDS_Long*) listener_data;

    retcode = dds_sensing_gnss_BasicDataReader_take(
        hw_reader,
        &sample_seq,
        &info_seq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to take data, retcode(%d)\n", retcode);
        goto done;
    }

    /* Print each valid sample taken */
    for (i = 0; i < dds_sensing_gnss_BasicSeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = dds_sensing_gnss_BasicSeq_get_reference(&sample_seq, i);
            printf("  Valid gnss sample received (%f)\n", sample->lat);
            *total_samples += 1;

            /* TODO read and process sample attributes here */

        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    dds_sensing_gnss_BasicDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
#ifndef RTI_CERT
    dds_sensing_gnss_BasicSeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
#else  /* RTI_CERT */
    return;
#endif  /* RTI_CERT */
}

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
dds_perception_TrajectorySubscriber_deserialize_unsigned_long(
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
dds_perception_TrajectorySubscriber_on_before_sample_deserialize(
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
    * function and dds_perception_TrajectorySubscriber_deserialize_unsigned_long
    * to match your type.
    */
    dds_perception_TrajectorySubscriber_deserialize_unsigned_long(
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
* \brief Helper function to filter an dds_perception_Trajectory sample
*
* \param[in]  sample       A dds_perception_Trajectory data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void
dds_perception_TrajectorySubscriber_filter_sample(
    dds_perception_Trajectory *sample,
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
dds_perception_TrajectorySubscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    dds_perception_Trajectory *hw_sample = (dds_perception_Trajectory *)sample;

    dds_perception_TrajectorySubscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}
#endif /* FILTER_ON_DESERIALIZE */
#endif /* USE_SAMPLE_FILTER */

void
dds_perception_TrajectorySubscriber_on_subscription_matched(
    void *listener_data,
    DDS_DataReader *reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a Trajectory publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a Trajectory publisher\n");
    }
}

void
dds_perception_TrajectorySubscriber_on_data_available(
    void *listener_data,
    DDS_DataReader * reader)
{
    dds_perception_TrajectoryDataReader *hw_reader = dds_perception_TrajectoryDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    dds_perception_Trajectory *sample = NULL;

    struct DDS_SampleInfoSeq info_seq =
    DDS_SEQUENCE_INITIALIZER;
    struct dds_perception_TrajectorySeq sample_seq =
    DDS_SEQUENCE_INITIALIZER;

    DDS_Long i;
    DDS_Long *total_samples = (DDS_Long*) listener_data;

    retcode = dds_perception_TrajectoryDataReader_take(
        hw_reader,
        &sample_seq,
        &info_seq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to take data, retcode(%d)\n", retcode);
        goto done;
    }

    /* Print each valid sample taken */
    for (i = 0; i < dds_perception_TrajectorySeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = dds_perception_TrajectorySeq_get_reference(&sample_seq, i);
            printf("  Valid Trajectory sample received (%u)\n", sample->parent.id[0]);
            *total_samples += 1;

            /* TODO read and process sample attributes here */

        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    dds_perception_TrajectoryDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
#ifndef RTI_CERT
    dds_perception_TrajectorySeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
#else  /* RTI_CERT */
    return;
#endif  /* RTI_CERT */
}


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
    DDS_Publisher *publisher;
    DDS_DataWriter *Pose3D_real_datawriter;
    dds_physics_Pose3D_realDataWriter *Pose3D_real_hw_datawriter;
    struct DDS_DataWriterQos Pose3D_real_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_physics_Pose3D_real *Pose3D_real_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData Pose3D_real_rem_subscription_data =
        DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    DDS_Subscriber *subscriber;
    DDS_DataReader *ObjectsDetected_datareader;
    struct DDS_DataReaderQos ObjectsDetected_dr_qos = DDS_DataReaderQos_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData ObjectsDetected_rem_publication_data =
        DDS_PublicationBuiltinTopicData_INITIALIZER;
    DDS_DataReader *Basic_datareader;
    struct DDS_DataReaderQos Basic_dr_qos = DDS_DataReaderQos_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData Basic_rem_publication_data =
        DDS_PublicationBuiltinTopicData_INITIALIZER;
    DDS_DataReader *Trajectory_datareader;
    struct DDS_DataReaderQos Trajectory_dr_qos = DDS_DataReaderQos_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData Trajectory_rem_publication_data =
        DDS_PublicationBuiltinTopicData_INITIALIZER;

    struct DDS_DataWriterListener Pose3D_real_dw_listener = DDS_DataWriterListener_INITIALIZER;
    Pose3D_real_sample = dds_physics_Pose3D_realTypeSupport_create_data();
    if (Pose3D_real_sample == NULL)
    {
        printf("failed dds_physics_Pose3D_realTypeSupport_create_data\n");
        return -1;
    }
    struct DDS_DataReaderListener ObjectsDetected_dr_listener = DDS_DataReaderListener_INITIALIZER;
    struct DDS_DataReaderListener Basic_dr_listener = DDS_DataReaderListener_INITIALIZER;
    struct DDS_DataReaderListener Trajectory_dr_listener = DDS_DataReaderListener_INITIALIZER;
    DDS_ReturnCode_t retcode;

    int ret_value = -1;
    DDS_Long total_samples = 0;
    DDS_Long i = 0;

    /* create and init the DDS domain participant */
    application = Application_create("localization_dp", domain_id, udp_intf, peer);
    if (application == NULL)
    {
        printf("domain participant creation error\n");
        goto done;
    }
    application->sleep_time = sleep_time;
    application->count = count;

    /* register & create topics for each pub|sub */
    char type_name_tmp[255];
    char topic_name_tmp[255];
    /* ObjectsDetected topic */
    DDS_Topic *ObjectsDetected_topic;
    strcpy(type_name_tmp, dds_perception_ObjectsDetectedTypeSupport_get_type_name());
    retcode = dds_perception_ObjectsDetectedTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "detectedObjects");
    ObjectsDetected_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (ObjectsDetected_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

    /* Basic topic */
    DDS_Topic *Basic_topic;
    strcpy(type_name_tmp, dds_sensing_gnss_BasicTypeSupport_get_type_name());
    retcode = dds_sensing_gnss_BasicTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "gnssPosition");
    Basic_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (Basic_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

    /* Trajectory topic */
    DDS_Topic *Trajectory_topic;
    strcpy(type_name_tmp, dds_perception_TrajectoryTypeSupport_get_type_name());
    retcode = dds_perception_TrajectoryTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "egoMotion");
    Trajectory_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (Trajectory_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

    /* Pose3D_real topic */
    DDS_Topic *Pose3D_real_topic;
    strcpy(type_name_tmp, dds_physics_Pose3D_realTypeSupport_get_type_name());
    retcode = dds_physics_Pose3D_realTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "egoPose");
    Pose3D_real_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (Pose3D_real_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

    retcode = DPSE_RemoteParticipant_assert(
        application->participant,
        "perception_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant perception_dp\n");
        goto done;
    }
    retcode = DPSE_RemoteParticipant_assert(
        application->participant,
        "egoMotion_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant egoMotion_dp\n");
        goto done;
    }
    retcode = DPSE_RemoteParticipant_assert(
        application->participant,
        "sceneEval_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant sceneEval_dp\n");
        goto done;
    }
    retcode = DPSE_RemoteParticipant_assert(
        application->participant,
        "stimAndPrint_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant stimAndPrint_dp\n");
        goto done;
    }

    // create publisher and dw_qos --------------
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

    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    Pose3D_real_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    Pose3D_real_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    Pose3D_real_dw_qos.resource_limits.max_samples_per_instance = 4;
    Pose3D_real_dw_qos.resource_limits.max_instances = 3;
    Pose3D_real_dw_qos.resource_limits.max_samples = Pose3D_real_dw_qos.resource_limits.max_instances *
        Pose3D_real_dw_qos.resource_limits.max_samples_per_instance;
    Pose3D_real_dw_qos.history.depth = 4;
    Pose3D_real_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    Pose3D_real_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    Pose3D_real_dw_listener.on_publication_matched = dds_physics_Pose3D_realPublisher_on_publication_matched;
	Pose3D_real_dw_qos.protocol.rtps_object_id = 113;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    Pose3D_real_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        Pose3D_real_topic,
        &Pose3D_real_dw_qos,
        &Pose3D_real_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (Pose3D_real_datawriter == NULL)
    {
        printf("Pose3D_real_datawriter == NULL\n");
        goto done;
    }

    Pose3D_real_rem_subscription_data.topic_name = DDS_String_dup("egoPose");
    Pose3D_real_rem_subscription_data.type_name = DDS_String_dup(dds_physics_Pose3D_realTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Pose3D_real_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Pose3D_real_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    Pose3D_real_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 203;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "perception_dp",        /* Note: this string should match the remote participant name */
        &Pose3D_real_rem_subscription_data,
        dds_physics_Pose3D_real_get_key_kind(dds_physics_Pose3D_realTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in perception_dp\n");
        goto done;
    }
    Pose3D_real_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 233;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "sceneEval_dp",        /* Note: this string should match the remote participant name */
        &Pose3D_real_rem_subscription_data,
        dds_physics_Pose3D_real_get_key_kind(dds_physics_Pose3D_realTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in sceneEval_dp\n");
        goto done;
    }

    Pose3D_real_hw_datawriter = dds_physics_Pose3D_realDataWriter_narrow(Pose3D_real_datawriter);
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

    /* Publisher sends samples with id = 0 or id = 1, so 2 instances maximum.
    * But in case filtering is done, all samples with 'id = 0' are
    * filtered so only one instance is needed.
    */
#ifdef USE_SAMPLE_FILTER
    ObjectsDetected_dr_qos.resource_limits.max_instances = 1;
#else  /* USE_SAMPLE_FILTER */
    ObjectsDetected_dr_qos.resource_limits.max_instances = 2;
#endif  /* USE_SAMPLE_FILTER */

    ObjectsDetected_dr_qos.resource_limits.max_samples_per_instance = 8;
    ObjectsDetected_dr_qos.resource_limits.max_samples = ObjectsDetected_dr_qos.resource_limits.max_instances *
        ObjectsDetected_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    ObjectsDetected_dr_qos.reader_resource_limits.max_remote_writers = 1;
    ObjectsDetected_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 1;
    ObjectsDetected_dr_qos.history.depth = 8;

    /* Publisher sends samples with id = 0 or id = 1, so 2 instances maximum.
    * But in case filtering is done, all samples with 'id = 0' are
    * filtered so only one instance is needed.
    */
#ifdef USE_SAMPLE_FILTER
    Basic_dr_qos.resource_limits.max_instances = 1;
#else  /* USE_SAMPLE_FILTER */
    Basic_dr_qos.resource_limits.max_instances = 2;
#endif  /* USE_SAMPLE_FILTER */

    Basic_dr_qos.resource_limits.max_samples_per_instance = 8;
    Basic_dr_qos.resource_limits.max_samples = Basic_dr_qos.resource_limits.max_instances *
        Basic_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    Basic_dr_qos.reader_resource_limits.max_remote_writers = 1;
    Basic_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 1;
    Basic_dr_qos.history.depth = 8;

    /* Publisher sends samples with id = 0 or id = 1, so 2 instances maximum.
    * But in case filtering is done, all samples with 'id = 0' are
    * filtered so only one instance is needed.
    */
#ifdef USE_SAMPLE_FILTER
    Trajectory_dr_qos.resource_limits.max_instances = 1;
#else  /* USE_SAMPLE_FILTER */
    Trajectory_dr_qos.resource_limits.max_instances = 2;
#endif  /* USE_SAMPLE_FILTER */

    Trajectory_dr_qos.resource_limits.max_samples_per_instance = 8;
    Trajectory_dr_qos.resource_limits.max_samples = Trajectory_dr_qos.resource_limits.max_instances *
        Trajectory_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    Trajectory_dr_qos.reader_resource_limits.max_remote_writers = 1;
    Trajectory_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 1;
    Trajectory_dr_qos.history.depth = 8;

#ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
#ifdef FILTER_ON_DESERIALIZE
    ObjectsDetected_dr_listener.on_before_sample_deserialize =
        dds_perception_ObjectsDetectedSubscriber_on_before_sample_deserialize;
#else  /* FILTER_ON_DESERIALIZE */
    ObjectsDetected_dr_listener.on_before_sample_commit =
        dds_perception_ObjectsDetectedSubscriber_on_before_sample_commit;
#endif  /* FILTER_ON_DESERIALIZE */
#endif  /* USE_SAMPLE_FILTER */

    ObjectsDetected_dr_listener.on_data_available = dds_perception_ObjectsDetectedSubscriber_on_data_available;
    ObjectsDetected_dr_listener.on_subscription_matched =
        dds_perception_ObjectsDetectedSubscriber_on_subscription_matched;

    ObjectsDetected_dr_listener.as_listener.listener_data = &total_samples;
    ObjectsDetected_dr_qos.protocol.rtps_object_id = 210;  /* Note: must assign unique numbers to each instance */

    ObjectsDetected_datareader = DDS_Subscriber_create_datareader(
        subscriber,
        DDS_Topic_as_topicdescription(ObjectsDetected_topic),
        &ObjectsDetected_dr_qos,
        &ObjectsDetected_dr_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if (ObjectsDetected_datareader == NULL)
    {
        printf("ObjectsDetected_datareader == NULL\n");
        goto done;
    }

    ObjectsDetected_rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 100;
    ObjectsDetected_rem_publication_data.topic_name = DDS_String_dup("detectedObjects");
    ObjectsDetected_rem_publication_data.type_name = DDS_String_dup(dds_perception_ObjectsDetectedTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    ObjectsDetected_rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    ObjectsDetected_rem_publication_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    retcode = DPSE_RemotePublication_assert(
        application->participant, "perception_dp",           /* Note: this string should match the remote participant name */
        &ObjectsDetected_rem_publication_data,
        dds_perception_ObjectsDetected_get_key_kind(dds_perception_ObjectsDetectedTypePlugin_get(), NULL));
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote publication for ObjectsDetected in perception_dp\n");
        goto done;
    }

#ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
#ifdef FILTER_ON_DESERIALIZE
    Basic_dr_listener.on_before_sample_deserialize =
        dds_sensing_gnss_BasicSubscriber_on_before_sample_deserialize;
#else  /* FILTER_ON_DESERIALIZE */
    Basic_dr_listener.on_before_sample_commit =
        dds_sensing_gnss_BasicSubscriber_on_before_sample_commit;
#endif  /* FILTER_ON_DESERIALIZE */
#endif  /* USE_SAMPLE_FILTER */

    Basic_dr_listener.on_data_available = dds_sensing_gnss_BasicSubscriber_on_data_available;
    Basic_dr_listener.on_subscription_matched = dds_sensing_gnss_BasicSubscriber_on_subscription_matched;
    Basic_dr_listener.as_listener.listener_data = &total_samples;
    Basic_dr_qos.protocol.rtps_object_id = 216;  /* Note: must assign unique numbers to each instance */

    Basic_datareader = DDS_Subscriber_create_datareader(
        subscriber,
        DDS_Topic_as_topicdescription(Basic_topic),
        &Basic_dr_qos,
        &Basic_dr_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if (Basic_datareader == NULL)
    {
        printf("Basic_datareader == NULL\n");
        goto done;
    }

    Basic_rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 146;
    Basic_rem_publication_data.topic_name = DDS_String_dup("gnssPosition");
    Basic_rem_publication_data.type_name = DDS_String_dup(dds_sensing_gnss_BasicTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Basic_rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Basic_rem_publication_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    printf("1: %d\n", dds_sensing_gnss_Basic_get_key_kind(dds_sensing_gnss_BasicTypePlugin_get(), NULL));
    retcode = DPSE_RemotePublication_assert(
        application->participant, "stimAndPrint_dp",           /* Note: this string should match the remote participant name */
        &Basic_rem_publication_data,
        dds_sensing_gnss_Basic_get_key_kind(dds_sensing_gnss_BasicTypePlugin_get(), NULL));
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote publication for gnss_Basic in stimAndPrint_dp (%d)\n", retcode);
        /* goto done; */
    }

#ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
#ifdef FILTER_ON_DESERIALIZE
    Trajectory_dr_listener.on_before_sample_deserialize =
        dds_perception_TrajectorySubscriber_on_before_sample_deserialize;
#else  /* FILTER_ON_DESERIALIZE */
    Trajectory_dr_listener.on_before_sample_commit =
        dds_perception_TrajectorySubscriber_on_before_sample_commit;
#endif  /* FILTER_ON_DESERIALIZE */
#endif  /* USE_SAMPLE_FILTER */

    Trajectory_dr_listener.on_data_available = dds_perception_TrajectorySubscriber_on_data_available;
    Trajectory_dr_listener.on_subscription_matched =
        dds_perception_TrajectorySubscriber_on_subscription_matched;

    Trajectory_dr_listener.as_listener.listener_data = &total_samples;
    Trajectory_dr_qos.protocol.rtps_object_id = 214;  /* Note: must assign unique numbers to each instance */

    Trajectory_datareader = DDS_Subscriber_create_datareader(
        subscriber,
        DDS_Topic_as_topicdescription(Trajectory_topic),
        &Trajectory_dr_qos,
        &Trajectory_dr_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if (Trajectory_datareader == NULL)
    {
        printf("Trajectory_datareader == NULL\n");
        goto done;
    }

    Trajectory_rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 124;
    Trajectory_rem_publication_data.topic_name = DDS_String_dup("egoMotion");
    Trajectory_rem_publication_data.type_name = DDS_String_dup(dds_perception_TrajectoryTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Trajectory_rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Trajectory_rem_publication_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    retcode = DPSE_RemotePublication_assert(
        application->participant, "egoMotion_dp",           /* Note: this string should match the remote participant name */
        &Trajectory_rem_publication_data,
        dds_perception_Trajectory_get_key_kind(dds_perception_TrajectoryTypePlugin_get(), NULL));

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote publication for Trajectory in egoMotion_dp\n");
        goto done;
    }

#ifdef RTI_CERT
#ifdef RTI_VXWORKS
    /** End initialization, disable further dynamic memory allocation ***/
    memAllocDisable();
#endif  /* RTI_VXWORKS */
#endif  /* RTI_CERT */

    /* loop ---------------- */
    for (i = 0; (application->count <= 0) || (i < application->count); ++i)
    {
        /* TODO set sample attributes here */
        Pose3D_real_sample->orientation.x = randFloatInRange(0.0f, 6.28f);
        Pose3D_real_sample->orientation.y = randFloatInRange(0.0f, 6.28f);
        Pose3D_real_sample->orientation.z = randFloatInRange(0.0f, 6.28f);
        Pose3D_real_sample->orientation.w = randFloatInRange(0.0f, 0.123f);
        Pose3D_real_sample->position.x = randFloatInRange(-100.0f, 100.0f);
        Pose3D_real_sample->position.y = randFloatInRange(-100.0f, 100.0f);
        Pose3D_real_sample->position.z = randFloatInRange(0.10f, 0.80f);

        retcode = dds_physics_Pose3D_realDataWriter_write(
            Pose3D_real_hw_datawriter,
            Pose3D_real_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "Pose3D_real");
        }
        else
        {
            printf("Written Pose3D_real sample %d\n",(i+1));
        }

        /* printf("Subscriber sleeping for %d msec...\n", sleep_time); */

        /* OSAPI_Thread_sleep() is not included in Connext DDS Cert because it might not
        * be thread safe. For this reason a call to OSAPI_Thread_sleep() cannot be done
        * in this example. Instead we use the code below.
        */
#if OSAPI_INCLUDE_POSIX
        {
            struct timespec remain, next;
            int rval;
            RTI_UINT32 is;

            is = application->sleep_time / 1000;

            next.tv_sec = is;
            next.tv_nsec = (application->sleep_time - (is * 1000U)) * 1000000U;

            do
            {
                rval = nanosleep(&next, &remain);
                if ((rval == -1) && (errno == EINTR))
                {
                    next = remain;
                }
            } while ((rval == -1) && (errno == EINTR));
        }
#elif RTI_VXWORKS
        taskDelay(((sysClkRateGet() * application->sleep_time) + 500) / 1000);
#else
        #error "Implementation of sleep() needed"
#endif
    }

    ret_value = 0;

    done:

#ifndef RTI_CERT
    if (application != NULL)
    {
        Application_delete(application);
    }

    if (Pose3D_real_sample != NULL)
    {
        dds_physics_Pose3D_realTypeSupport_delete_data(Pose3D_real_sample);
    }

#endif  /* RTI_CERT */
#ifndef RTI_CERT
    retcode = DDS_DataWriterQos_finalize(&Pose3D_real_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&Pose3D_real_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Pose3D_real\n");
        return -1;
    }

    retcode = DDS_DataReaderQos_finalize(&ObjectsDetected_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataReaderQos\n");
        return -1;
    }
    if (DDS_PublicationBuiltinTopicData_finalize(&ObjectsDetected_rem_publication_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for ObjectsDetected\n");
        return -1;
    }

    retcode = DDS_DataReaderQos_finalize(&Basic_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataReaderQos\n");
        return -1;
    }
    if (DDS_PublicationBuiltinTopicData_finalize(&Basic_rem_publication_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Basic\n");
        return -1;
    }

    retcode = DDS_DataReaderQos_finalize(&Trajectory_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataReaderQos\n");
        return -1;
    }
    if (DDS_PublicationBuiltinTopicData_finalize(&Trajectory_rem_publication_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Trajectory\n");
        return -1;
    }

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
