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
/* egoMotion_main.c
* An application skeleton using the following DDS data types:
*   dds::perception::ObjectsDetected
*   dds::sensing::gnss::Basic
*   dds::sensing::imu::Imu_real
*   dds::sensing::Compass
*   dds::perception::Trajectory
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
#include "res/types/data/rti/sensing/Imu_tSupport.h"
#include "res/types/data/rti/sensing/Compass_tSupport.h"
#include "res/types/data/rti/perception/Trajectory_tSupport.h"
#include "egoMotion_dp.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"

/* Helper functions (added in) -------------------------------- */
/* returns random float values within a specified range */
float randFloatInRange(float low, float high)
{
    float rval = ((float) rand() / (float)RAND_MAX);
    float rspan = high-low;
    return low + (rval * rspan);
}
// utility timestamp functions
void tstamp_get(struct timespec *tStamp)
{
#ifdef WIN32
    timespec_get(tStamp, TIME_UTC);
#else
    clock_gettime(CLOCK_REALTIME, tStamp);
#endif
    return;
}
void tstamp_diff(struct timespec *tElapsed, struct timespec *tStart)
{
    struct timespec tNow;
    tstamp_get(&tNow);
    tElapsed->tv_sec = tNow.tv_sec - tStart->tv_sec;
    tElapsed->tv_nsec = tNow.tv_nsec - tStart->tv_nsec;
    if(tElapsed->tv_nsec < 0) {
        tElapsed->tv_sec++;
        tElapsed->tv_nsec += 1000000000;
    }
}
/* end added-in helper functions ------------------------------- */


void
dds_perception_TrajectoryPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a Trajectory subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a Trajectory subscriber\n");
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
    struct dds_perception_ObjectsDetectedSeq sample_seq =
    DDS_SEQUENCE_INITIALIZER;

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
            printf("  Valid ObjectsDetected sample received (%u)\n", sample->parent.id[0]);
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
dds_sensing_imu_Imu_realSubscriber_deserialize_unsigned_long(
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
dds_sensing_imu_Imu_realSubscriber_on_before_sample_deserialize(
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
    * function and dds_sensing_imu_Imu_realSubscriber_deserialize_unsigned_long
    * to match your type.
    */
    dds_sensing_imu_Imu_realSubscriber_deserialize_unsigned_long(
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
* \brief Helper function to filter an dds_sensing_imu_Imu_real sample
*
* \param[in]  sample       A dds_sensing_imu_Imu_real data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void
dds_sensing_imu_Imu_realSubscriber_filter_sample(
    dds_sensing_imu_Imu_real *sample,
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
dds_sensing_imu_Imu_realSubscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    dds_sensing_imu_Imu_real *hw_sample = (dds_sensing_imu_Imu_real *)sample;

    dds_sensing_imu_Imu_realSubscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}
#endif /* FILTER_ON_DESERIALIZE */
#endif /* USE_SAMPLE_FILTER */

void
dds_sensing_imu_Imu_realSubscriber_on_subscription_matched(
    void *listener_data,
    DDS_DataReader *reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a IMU publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a IMU publisher\n");
    }
}

void
dds_sensing_imu_Imu_realSubscriber_on_data_available(
    void *listener_data,
    DDS_DataReader * reader)
{
    dds_sensing_imu_Imu_realDataReader *hw_reader = dds_sensing_imu_Imu_realDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    dds_sensing_imu_Imu_real *sample = NULL;

    struct DDS_SampleInfoSeq info_seq =
    DDS_SEQUENCE_INITIALIZER;
    struct dds_sensing_imu_Imu_realSeq sample_seq =
    DDS_SEQUENCE_INITIALIZER;

    DDS_Long i;
    DDS_Long *total_samples = (DDS_Long*) listener_data;

    retcode = dds_sensing_imu_Imu_realDataReader_take(
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
    for (i = 0; i < dds_sensing_imu_Imu_realSeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = dds_sensing_imu_Imu_realSeq_get_reference(&sample_seq, i);
            printf("  Valid Imu sample received (%f)\n", sample->orientation.x);
            *total_samples += 1;

            /* TODO read and process sample attributes here */

        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    dds_sensing_imu_Imu_realDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
#ifndef RTI_CERT
    dds_sensing_imu_Imu_realSeq_finalize(&sample_seq);
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
dds_sensing_CompassSubscriber_deserialize_unsigned_long(
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
dds_sensing_CompassSubscriber_on_before_sample_deserialize(
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
    * function and dds_sensing_CompassSubscriber_deserialize_unsigned_long
    * to match your type.
    */
    dds_sensing_CompassSubscriber_deserialize_unsigned_long(
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
* \brief Helper function to filter an dds_sensing_Compass sample
*
* \param[in]  sample       A dds_sensing_Compass data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void
dds_sensing_CompassSubscriber_filter_sample(
    dds_sensing_Compass *sample,
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
dds_sensing_CompassSubscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    dds_sensing_Compass *hw_sample = (dds_sensing_Compass *)sample;

    dds_sensing_CompassSubscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}
#endif /* FILTER_ON_DESERIALIZE */
#endif /* USE_SAMPLE_FILTER */

void
dds_sensing_CompassSubscriber_on_subscription_matched(
    void *listener_data,
    DDS_DataReader *reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a Compass publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a Compass publisher\n");
    }
}

void
dds_sensing_CompassSubscriber_on_data_available(
    void *listener_data,
    DDS_DataReader * reader)
{
    dds_sensing_CompassDataReader *hw_reader = dds_sensing_CompassDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    dds_sensing_Compass *sample = NULL;

    struct DDS_SampleInfoSeq info_seq =
    DDS_SEQUENCE_INITIALIZER;
    struct dds_sensing_CompassSeq sample_seq =
    DDS_SEQUENCE_INITIALIZER;

    DDS_Long i;
    DDS_Long *total_samples = (DDS_Long*) listener_data;

    retcode = dds_sensing_CompassDataReader_take(
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
    for (i = 0; i < dds_sensing_CompassSeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = dds_sensing_CompassSeq_get_reference(&sample_seq, i);
            printf("  Valid compass sample received (%f)\n", sample->heading);
            *total_samples += 1;

            /* TODO read and process sample attributes here */

        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    dds_sensing_CompassDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
#ifndef RTI_CERT
    dds_sensing_CompassSeq_finalize(&sample_seq);
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
    DDS_DataWriter *Trajectory_datawriter;
    dds_perception_TrajectoryDataWriter *Trajectory_hw_datawriter;
    struct DDS_DataWriterQos Trajectory_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_perception_Trajectory *Trajectory_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData Trajectory_rem_subscription_data =
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
    DDS_DataReader *Imu_real_datareader;
    struct DDS_DataReaderQos Imu_real_dr_qos = DDS_DataReaderQos_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData Imu_real_rem_publication_data =
        DDS_PublicationBuiltinTopicData_INITIALIZER;
    DDS_DataReader *Compass_datareader;
    struct DDS_DataReaderQos Compass_dr_qos = DDS_DataReaderQos_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData Compass_rem_publication_data =
        DDS_PublicationBuiltinTopicData_INITIALIZER;

    struct DDS_DataWriterListener Trajectory_dw_listener = DDS_DataWriterListener_INITIALIZER;
    Trajectory_sample = dds_perception_TrajectoryTypeSupport_create_data();
    if (Trajectory_sample == NULL)
    {
        printf("failed dds_perception_TrajectoryTypeSupport_create_data\n");
        return -1;
    }
    struct DDS_DataReaderListener ObjectsDetected_dr_listener = DDS_DataReaderListener_INITIALIZER;
    struct DDS_DataReaderListener Basic_dr_listener = DDS_DataReaderListener_INITIALIZER;
    struct DDS_DataReaderListener Imu_real_dr_listener = DDS_DataReaderListener_INITIALIZER;
    struct DDS_DataReaderListener Compass_dr_listener = DDS_DataReaderListener_INITIALIZER;
    DDS_ReturnCode_t retcode;

    int ret_value = -1;
    DDS_Long total_samples = 0;
    DDS_Long i = 0;

    /* create and init the DDS domain participant */
    application = Application_create("egoMotion_dp", domain_id, udp_intf, peer);
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

    /* gnss_Basic topic */
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

    /* Imu_real topic */
    DDS_Topic *Imu_real_topic;
    strcpy(type_name_tmp, dds_sensing_imu_Imu_realTypeSupport_get_type_name());
    retcode = dds_sensing_imu_Imu_realTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "imuData");
    Imu_real_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (Imu_real_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

    /* Compass topic */
    DDS_Topic *Compass_topic;
    strcpy(type_name_tmp, dds_sensing_CompassTypeSupport_get_type_name());
    retcode = dds_sensing_CompassTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "compass");
    Compass_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (Compass_topic == NULL)
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
        "perception_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant perception_dp\n");
        goto done;
    }
    retcode = DPSE_RemoteParticipant_assert(
        application->participant,
        "localization_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant localization_dp\n");
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
    Trajectory_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    Trajectory_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    Trajectory_dw_qos.resource_limits.max_samples_per_instance = 4;
    Trajectory_dw_qos.resource_limits.max_instances = 3;
    Trajectory_dw_qos.resource_limits.max_samples = Trajectory_dw_qos.resource_limits.max_instances *
        Trajectory_dw_qos.resource_limits.max_samples_per_instance;
    Trajectory_dw_qos.history.depth = 4;
    Trajectory_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    Trajectory_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    Trajectory_dw_listener.on_publication_matched = dds_perception_TrajectoryPublisher_on_publication_matched;
	Trajectory_dw_qos.protocol.rtps_object_id = 124;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    Trajectory_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        Trajectory_topic,
        &Trajectory_dw_qos,
        &Trajectory_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (Trajectory_datawriter == NULL)
    {
        printf("Trajectory_datawriter == NULL\n");
        goto done;
    }

    Trajectory_rem_subscription_data.topic_name = DDS_String_dup("egoMotion");
    Trajectory_rem_subscription_data.type_name = DDS_String_dup(dds_perception_TrajectoryTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Trajectory_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Trajectory_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    Trajectory_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 204;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "perception_dp",        /* Note: this string should match the remote participant name */
        &Trajectory_rem_subscription_data,
        dds_perception_Trajectory_get_key_kind(dds_perception_TrajectoryTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in perception_dp\n");
        goto done;
    }
    Trajectory_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 214;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "localization_dp",        /* Note: this string should match the remote participant name */
        &Trajectory_rem_subscription_data,
        dds_perception_Trajectory_get_key_kind(dds_perception_TrajectoryTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in localization_dp\n");
        goto done;
    }
    Trajectory_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 234;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "sceneEval_dp",        /* Note: this string should match the remote participant name */
        &Trajectory_rem_subscription_data,
        dds_perception_Trajectory_get_key_kind(dds_perception_TrajectoryTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in sceneEval_dp\n");
        goto done;
    }

    Trajectory_hw_datawriter = dds_perception_TrajectoryDataWriter_narrow(Trajectory_datawriter);
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
    Imu_real_dr_qos.resource_limits.max_instances = 1;
#else  /* USE_SAMPLE_FILTER */
    Imu_real_dr_qos.resource_limits.max_instances = 2;
#endif  /* USE_SAMPLE_FILTER */

    Imu_real_dr_qos.resource_limits.max_samples_per_instance = 8;
    Imu_real_dr_qos.resource_limits.max_samples = Imu_real_dr_qos.resource_limits.max_instances *
        Imu_real_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    Imu_real_dr_qos.reader_resource_limits.max_remote_writers = 1;
    Imu_real_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 1;
    Imu_real_dr_qos.history.depth = 8;

    /* Publisher sends samples with id = 0 or id = 1, so 2 instances maximum.
    * But in case filtering is done, all samples with 'id = 0' are
    * filtered so only one instance is needed.
    */
#ifdef USE_SAMPLE_FILTER
    Compass_dr_qos.resource_limits.max_instances = 1;
#else  /* USE_SAMPLE_FILTER */
    Compass_dr_qos.resource_limits.max_instances = 2;
#endif  /* USE_SAMPLE_FILTER */

    Compass_dr_qos.resource_limits.max_samples_per_instance = 8;
    Compass_dr_qos.resource_limits.max_samples = Compass_dr_qos.resource_limits.max_instances *
        Compass_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    Compass_dr_qos.reader_resource_limits.max_remote_writers = 1;
    Compass_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 1;
    Compass_dr_qos.history.depth = 8;

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
    ObjectsDetected_dr_qos.protocol.rtps_object_id = 220;  /* Note: must assign unique numbers to each instance */

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
    Basic_dr_qos.protocol.rtps_object_id = 226;  /* Note: must assign unique numbers to each instance */

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
        printf("failed to assert remote publication for gnss_Basic in stimAndPrint_dp\n");
        goto done;
    }

#ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
#ifdef FILTER_ON_DESERIALIZE
    Imu_real_dr_listener.on_before_sample_deserialize =
        dds_sensing_imu_Imu_realSubscriber_on_before_sample_deserialize;
#else  /* FILTER_ON_DESERIALIZE */
    Imu_real_dr_listener.on_before_sample_commit =
        dds_sensing_imu_Imu_realSubscriber_on_before_sample_commit;
#endif  /* FILTER_ON_DESERIALIZE */
#endif  /* USE_SAMPLE_FILTER */

    Imu_real_dr_listener.on_data_available = dds_sensing_imu_Imu_realSubscriber_on_data_available;
    Imu_real_dr_listener.on_subscription_matched =
        dds_sensing_imu_Imu_realSubscriber_on_subscription_matched;

    Imu_real_dr_listener.as_listener.listener_data = &total_samples;
    Imu_real_dr_qos.protocol.rtps_object_id = 227;  /* Note: must assign unique numbers to each instance */

    Imu_real_datareader = DDS_Subscriber_create_datareader(
        subscriber,
        DDS_Topic_as_topicdescription(Imu_real_topic),
        &Imu_real_dr_qos,
        &Imu_real_dr_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if (Imu_real_datareader == NULL)
    {
        printf("Imu_real_datareader == NULL\n");
        goto done;
    }

    Imu_real_rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 147;
    Imu_real_rem_publication_data.topic_name = DDS_String_dup("imuData");
    Imu_real_rem_publication_data.type_name = DDS_String_dup(dds_sensing_imu_Imu_realTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Imu_real_rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Imu_real_rem_publication_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    retcode = DPSE_RemotePublication_assert(
        application->participant, "stimAndPrint_dp",           /* Note: this string should match the remote participant name */
        &Imu_real_rem_publication_data,
        dds_sensing_imu_Imu_real_get_key_kind(dds_sensing_imu_Imu_realTypePlugin_get(), NULL));
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote publication for IMU in stimAndPrint_dp\n");
        goto done;
    }

#ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
#ifdef FILTER_ON_DESERIALIZE
    Compass_dr_listener.on_before_sample_deserialize =
        dds_sensing_CompassSubscriber_on_before_sample_deserialize;
#else  /* FILTER_ON_DESERIALIZE */
    Compass_dr_listener.on_before_sample_commit =
        dds_sensing_CompassSubscriber_on_before_sample_commit;
#endif  /* FILTER_ON_DESERIALIZE */
#endif  /* USE_SAMPLE_FILTER */

    Compass_dr_listener.on_data_available = dds_sensing_CompassSubscriber_on_data_available;
    Compass_dr_listener.on_subscription_matched =
        dds_sensing_CompassSubscriber_on_subscription_matched;

    Compass_dr_listener.as_listener.listener_data = &total_samples;
    Compass_dr_qos.protocol.rtps_object_id = 228;  /* Note: must assign unique numbers to each instance */

    Compass_datareader = DDS_Subscriber_create_datareader(
        subscriber,
        DDS_Topic_as_topicdescription(Compass_topic),
        &Compass_dr_qos,
        &Compass_dr_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if (Compass_datareader == NULL)
    {
        printf("Compass_datareader == NULL\n");
        goto done;
    }

    Compass_rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 148;
    Compass_rem_publication_data.topic_name = DDS_String_dup("compass");
    Compass_rem_publication_data.type_name = DDS_String_dup(dds_sensing_CompassTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Compass_rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Compass_rem_publication_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    retcode = DPSE_RemotePublication_assert(
        application->participant, "stimAndPrint_dp",           /* Note: this string should match the remote participant name */
        &Compass_rem_publication_data,
        dds_sensing_Compass_get_key_kind(dds_sensing_CompassTypePlugin_get(), NULL));
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote publication for Compass in stimAndPrint_dp\n");
        goto done;
    }

#ifdef RTI_CERT
#ifdef RTI_VXWORKS
    /** End initialization, disable further dynamic memory allocation ***/
    memAllocDisable();
#endif  /* RTI_VXWORKS */
#endif  /* RTI_CERT */

    /* initialize the write data samples */
    struct timespec tStart, tElapsed;
    tstamp_get(&tStart);

    Trajectory_sample->parent.id[0] = 123;
    Trajectory_sample->parent.id[1] = 0;
#define TRAJECTORY_POINT_COUNT 2
    dds_perception_TrajectoryPointSeq_set_length(&Trajectory_sample->points, TRAJECTORY_POINT_COUNT);

    /* loop ---------------- */
    for (i = 0; (application->count <= 0) || (i < application->count); ++i)
    {
        /* set sample attributes here */
        for(int p=0 ; p<TRAJECTORY_POINT_COUNT ; p++) {
            dds_perception_TrajectoryPoint *tmpPoint = dds_perception_TrajectoryPointSeq_get_reference(&Trajectory_sample->points, p);
            tmpPoint->acceleration.x = randFloatInRange(-0.333f, 0.333f);
            tmpPoint->acceleration.y = randFloatInRange(-0.022f, 0.022f);
            tmpPoint->velocity.x = randFloatInRange(-0.0f, 67.0f);
            tmpPoint->velocity.y = randFloatInRange(-0.022f, 0.022f);
            tmpPoint->pose.orientation.x = randFloatInRange(0.0f, 6.28f);
            tmpPoint->pose.orientation.y = randFloatInRange(0.0f, 6.28f);
            tmpPoint->pose.orientation.z = randFloatInRange(0.0f, 6.28f);
            tmpPoint->pose.orientation.w = randFloatInRange(0.0f, 0.123f);
            tmpPoint->pose.position.x = randFloatInRange(-100.0f, 100.0f);
            tmpPoint->pose.position.y = randFloatInRange(-100.0f, 100.0f);
            tmpPoint->pose.position.z = randFloatInRange(0.10f, 0.80f);
            tmpPoint->heading_rate = randFloatInRange(-2.222f, 2.222f);
            tmpPoint->wheel_angle[0] = randFloatInRange(-0.011, 0.011);
            tmpPoint->wheel_angle[1] = randFloatInRange(-0.011, 0.011);
            tstamp_diff(&tElapsed, &tStart);
            tmpPoint->time_since_start.sec = tElapsed.tv_sec;
            tmpPoint->time_since_start.nanosec = tElapsed.tv_nsec;
        }


        retcode = dds_perception_TrajectoryDataWriter_write(
            Trajectory_hw_datawriter,
            Trajectory_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "Trajectory");
        }
        else
        {
            printf("Written Trajectory sample %d\n",(i+1));
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

    if (Trajectory_sample != NULL)
    {
        dds_perception_TrajectoryTypeSupport_delete_data(Trajectory_sample);
    }

#endif  /* RTI_CERT */
#ifndef RTI_CERT
    retcode = DDS_DataWriterQos_finalize(&Trajectory_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&Trajectory_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Trajectory\n");
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

    retcode = DDS_DataReaderQos_finalize(&Imu_real_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataReaderQos\n");
        return -1;
    }
    if (DDS_PublicationBuiltinTopicData_finalize(&Imu_real_rem_publication_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Imu_real\n");
        return -1;
    }

    retcode = DDS_DataReaderQos_finalize(&Compass_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataReaderQos\n");
        return -1;
    }
    if (DDS_PublicationBuiltinTopicData_finalize(&Compass_rem_publication_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Compass\n");
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
