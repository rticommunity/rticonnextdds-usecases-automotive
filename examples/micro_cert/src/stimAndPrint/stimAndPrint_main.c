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
/* stimAndPrint_main.c
* An application skeleton using the following DDS data types:
*   dds::sensing::Lidar
*   dds::sensing::Camera
*   dds::sensing::imu::Imu_real
*   dds::sensing::Compass
*   dds::sensing::gnss::Basic
*   dds::planning::MapData
*   dds::system::StatusTopic
* This skeleton file is generated, but intended to be used
* as a starting point example: modified by the user
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
/* include the type support headers for the needed data types */
#include "res/types/data/rti/sensing/Lidar_tSupport.h"
#include "res/types/data/rti/sensing/Camera_tSupport.h"
#include "res/types/data/rti/sensing/Imu_tSupport.h"
#include "res/types/data/rti/sensing/Compass_tSupport.h"
#include "res/types/data/rti/sensing/Gnss_tSupport.h"
#include "res/types/data/rti/planning/Maps_tSupport.h"
#include "res/types/data/rti/system/StatusTopic_tSupport.h"
#include "stimAndPrint_dp.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"

/* Helper functions (added in) -------------------------------- */
// returns random float values within a specified range
float randFloatInRange(float low, float high)
{
    float rval = ((float) rand() / (float)RAND_MAX);
    float rspan = high-low;
    return low + (rval * rspan);
}
// returns random float values within a specified range
int32_t randInt32InRange(int32_t low, int32_t high)
{
    float rval = ((float) rand() / (float)RAND_MAX);
    float rspan = high-low;
    return low + (int32_t)(rval * rspan);
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
#define PTCLOUD_POINTS_GEN 256
// generate random pointcloud data
void ptcloud_gen_data(dds_sensing_pointcloud_PointCloud *ptCloud)
{
    for(int i=0; i<PTCLOUD_POINTS_GEN ; i++)
    {
        dds_sensing_pointcloud_PointDataRecord *tmpPoint = dds_sensing_pointcloud_PointDataRecordSeq_get_reference(&ptCloud->point, i);
        tmpPoint->parent.x = randInt32InRange(-5000, 5000);
        tmpPoint->parent.y = randInt32InRange(-5000, 5000);
        tmpPoint->parent.z = randInt32InRange(0, 10000);
        tmpPoint->intensity = (uint16_t)(randInt32InRange(0,1000));
        tmpPoint->pulse_return = 0;
        tmpPoint->classification = 0;
        tmpPoint->scan_angle_rank = 0;
        tmpPoint->user_data = 0;
        tmpPoint->point_source_id = 0;
        struct timespec tStamp;
        tstamp_get(&tStamp);
        dds_base_Float64 tReal = (double)tStamp.tv_sec + ((double)(tStamp.tv_nsec) / 1000000000.0);
        tmpPoint->gps_time = tReal;
    }
}
/* end added-in helper functions ------------------------------- */

void
dds_sensing_LidarPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a Lidar subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a Lidar subscriber\n");
    }
}

void
dds_sensing_CameraPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a Camera subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a Camera subscriber\n");
    }
}

void
dds_sensing_imu_Imu_realPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a IMU subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a IMU subscriber\n");
    }
}

void
dds_sensing_CompassPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a Compass subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a Compass subscriber\n");
    }
}

void
dds_sensing_gnss_BasicPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a GNSS subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a GNSS subscriber\n");
    }
}

void
dds_planning_MapDataPublisher_on_publication_matched(
    void *listener_data,
    DDS_DataWriter *writer,
    const struct DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a MapData subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a MapData subscriber\n");
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
dds_system_StatusTopicSubscriber_deserialize_unsigned_long(
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
dds_system_StatusTopicSubscriber_on_before_sample_deserialize(
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
    * function and dds_system_StatusTopicSubscriber_deserialize_unsigned_long
    * to match your type.
    */
    dds_system_StatusTopicSubscriber_deserialize_unsigned_long(
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
* \brief Helper function to filter an dds_system_StatusTopic sample
*
* \param[in]  sample       A dds_system_StatusTopic data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void
dds_system_StatusTopicSubscriber_filter_sample(
    dds_system_StatusTopic *sample,
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
dds_system_StatusTopicSubscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    dds_system_StatusTopic *hw_sample = (dds_system_StatusTopic *)sample;

    dds_system_StatusTopicSubscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}
#endif /* FILTER_ON_DESERIALIZE */
#endif /* USE_SAMPLE_FILTER */

void
dds_system_StatusTopicSubscriber_on_subscription_matched(
    void *listener_data,
    DDS_DataReader *reader,
    const struct DDS_SubscriptionMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a StatusTopic publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a StatusTopic publisher\n");
    }
}

void
dds_system_StatusTopicSubscriber_on_data_available(
    void *listener_data,
    DDS_DataReader * reader)
{
    dds_system_StatusTopicDataReader *hw_reader = dds_system_StatusTopicDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    dds_system_StatusTopic *sample = NULL;

    struct DDS_SampleInfoSeq info_seq =
    DDS_SEQUENCE_INITIALIZER;
    struct dds_system_StatusTopicSeq sample_seq =
    DDS_SEQUENCE_INITIALIZER;

    DDS_Long i;
    DDS_Long *total_samples = (DDS_Long*) listener_data;

    retcode = dds_system_StatusTopicDataReader_take(
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
    for (i = 0; i < dds_system_StatusTopicSeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = dds_system_StatusTopicSeq_get_reference(&sample_seq, i);
            printf("  Valid StatusTopic sample received (%s)\n", sample->data);
            *total_samples += 1;

            /* TODO read and process sample attributes here */

        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    dds_system_StatusTopicDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
#ifndef RTI_CERT
    dds_system_StatusTopicSeq_finalize(&sample_seq);
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
    DDS_DataWriter *Lidar_datawriter;
    dds_sensing_LidarDataWriter *Lidar_hw_datawriter;
    struct DDS_DataWriterQos Lidar_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_sensing_Lidar *Lidar_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData Lidar_rem_subscription_data =
        DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    DDS_DataWriter *Camera_datawriter;
    dds_sensing_CameraDataWriter *Camera_hw_datawriter;
    struct DDS_DataWriterQos Camera_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_sensing_Camera *Camera_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData Camera_rem_subscription_data =
        DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    DDS_DataWriter *Imu_real_datawriter;
    dds_sensing_imu_Imu_realDataWriter *Imu_real_hw_datawriter;
    struct DDS_DataWriterQos Imu_real_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_sensing_imu_Imu_real *Imu_real_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData Imu_real_rem_subscription_data =
        DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    DDS_DataWriter *Compass_datawriter;
    dds_sensing_CompassDataWriter *Compass_hw_datawriter;
    struct DDS_DataWriterQos Compass_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_sensing_Compass *Compass_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData Compass_rem_subscription_data =
        DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    DDS_DataWriter *Basic_datawriter;
    dds_sensing_gnss_BasicDataWriter *Basic_hw_datawriter;
    struct DDS_DataWriterQos Basic_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_sensing_gnss_Basic *Basic_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData Basic_rem_subscription_data =
        DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    DDS_DataWriter *MapData_datawriter;
    dds_planning_MapDataDataWriter *MapData_hw_datawriter;
    struct DDS_DataWriterQos MapData_dw_qos = DDS_DataWriterQos_INITIALIZER;
    dds_planning_MapData *MapData_sample = NULL;
    struct DDS_SubscriptionBuiltinTopicData MapData_rem_subscription_data =
        DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    DDS_Subscriber *subscriber;
    DDS_DataReader *StatusTopic_datareader;
    struct DDS_DataReaderQos StatusTopic_dr_qos = DDS_DataReaderQos_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData StatusTopic_rem_publication_data =
        DDS_PublicationBuiltinTopicData_INITIALIZER;

    struct DDS_DataWriterListener Lidar_dw_listener = DDS_DataWriterListener_INITIALIZER;
    Lidar_sample = dds_sensing_LidarTypeSupport_create_data();
    if (Lidar_sample == NULL)
    {
        printf("failed dds_sensing_LidarTypeSupport_create_data\n");
        return -1;
    }

    struct DDS_DataWriterListener Camera_dw_listener = DDS_DataWriterListener_INITIALIZER;
    Camera_sample = dds_sensing_CameraTypeSupport_create_data();
    if (Camera_sample == NULL)
    {
        printf("failed dds_sensing_CameraTypeSupport_create_data\n");
        return -1;
    }

    struct DDS_DataWriterListener Imu_real_dw_listener = DDS_DataWriterListener_INITIALIZER;
    Imu_real_sample = dds_sensing_imu_Imu_realTypeSupport_create_data();
    if (Imu_real_sample == NULL)
    {
        printf("failed dds_sensing_imu_Imu_realTypeSupport_create_data\n");
        return -1;
    }

    struct DDS_DataWriterListener Compass_dw_listener = DDS_DataWriterListener_INITIALIZER;
    Compass_sample = dds_sensing_CompassTypeSupport_create_data();
    if (Compass_sample == NULL)
    {
        printf("failed dds_sensing_CompassTypeSupport_create_data\n");
        return -1;
    }

    struct DDS_DataWriterListener Basic_dw_listener = DDS_DataWriterListener_INITIALIZER;
    Basic_sample = dds_sensing_gnss_BasicTypeSupport_create_data();
    if (Basic_sample == NULL)
    {
        printf("failed dds_sensing_gnss_BasicTypeSupport_create_data\n");
        return -1;
    }

    struct DDS_DataWriterListener MapData_dw_listener = DDS_DataWriterListener_INITIALIZER;
    MapData_sample = dds_planning_MapDataTypeSupport_create_data();
    if (MapData_sample == NULL)
    {
        printf("failed dds_planning_MapDataTypeSupport_create_data\n");
        return -1;
    }
    struct DDS_DataReaderListener StatusTopic_dr_listener = DDS_DataReaderListener_INITIALIZER;
    DDS_ReturnCode_t retcode;

    int ret_value = -1;
    DDS_Long total_samples = 0;
    DDS_Long i = 0;

    /* create and init the DDS domain participant */
    application = Application_create("stimAndPrint_dp", domain_id, udp_intf, peer);
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
    /* Lidar topic */
    DDS_Topic *Lidar_topic;
    strcpy(type_name_tmp, dds_sensing_LidarTypeSupport_get_type_name());
    retcode = dds_sensing_LidarTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "lidarPoints");
    Lidar_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (Lidar_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

    /* Camera topic */
    DDS_Topic *Camera_topic;
    strcpy(type_name_tmp, dds_sensing_CameraTypeSupport_get_type_name());
    retcode = dds_sensing_CameraTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "cameraView");
    Camera_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (Camera_topic == NULL)
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

    /* Basic(GNSS) topic */
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

    /* MapData topic */
    DDS_Topic *MapData_topic;
    strcpy(type_name_tmp, dds_planning_MapDataTypeSupport_get_type_name());
    retcode = dds_planning_MapDataTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "mapData");
    MapData_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (MapData_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
        goto done;
    }

    /* StatusTopic topic */
    DDS_Topic *StatusTopic_topic;
    strcpy(type_name_tmp, dds_system_StatusTopicTypeSupport_get_type_name());
    retcode = dds_system_StatusTopicTypeSupport_register_type(
        application->participant, type_name_tmp);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to register type: %s\n", type_name_tmp);
        goto done;
    }
    strcpy(topic_name_tmp, "egoStatus");
    StatusTopic_topic = DDS_DomainParticipant_create_topic(
        application->participant, topic_name_tmp, type_name_tmp,
        &DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if (StatusTopic_topic == NULL)
    {
        printf("topic %s == NULL\n", type_name_tmp);
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
        "perception_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant perception_dp\n");
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
        "localization_dp");     /* Note: this string should match the remote participant name */
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote participant localization_dp\n");
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
    Lidar_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    Lidar_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    Lidar_dw_qos.resource_limits.max_samples_per_instance = 4;
    Lidar_dw_qos.resource_limits.max_instances = 1;
    Lidar_dw_qos.resource_limits.max_samples = Lidar_dw_qos.resource_limits.max_instances *
        Lidar_dw_qos.resource_limits.max_samples_per_instance;
    Lidar_dw_qos.history.depth = 4;
    Lidar_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    Lidar_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    Lidar_dw_listener.on_publication_matched = dds_sensing_LidarPublisher_on_publication_matched;
	Lidar_dw_qos.protocol.rtps_object_id = 141;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    Lidar_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        Lidar_topic,
        &Lidar_dw_qos,
        &Lidar_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (Lidar_datawriter == NULL)
    {
        printf("Lidar_datawriter == NULL\n");
        goto done;
    }

    Lidar_rem_subscription_data.topic_name = DDS_String_dup("lidarPoints");
    Lidar_rem_subscription_data.type_name = DDS_String_dup(dds_sensing_LidarTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Lidar_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Lidar_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    Lidar_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 201;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "perception_dp",        /* Note: this string should match the remote participant name */
        &Lidar_rem_subscription_data,
        dds_sensing_Lidar_get_key_kind(dds_sensing_LidarTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in perception_dp\n");
        goto done;
    }

    Lidar_hw_datawriter = dds_sensing_LidarDataWriter_narrow(Lidar_datawriter);
    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    Camera_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    Camera_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    Camera_dw_qos.resource_limits.max_samples_per_instance = 4;
    Camera_dw_qos.resource_limits.max_instances = 1;
    Camera_dw_qos.resource_limits.max_samples = Camera_dw_qos.resource_limits.max_instances *
        Camera_dw_qos.resource_limits.max_samples_per_instance;
    Camera_dw_qos.history.depth = 4;
    Camera_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    Camera_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    Camera_dw_listener.on_publication_matched = dds_sensing_CameraPublisher_on_publication_matched;
	Camera_dw_qos.protocol.rtps_object_id = 142;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    Camera_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        Camera_topic,
        &Camera_dw_qos,
        &Camera_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (Camera_datawriter == NULL)
    {
        printf("Camera_datawriter == NULL\n");
        goto done;
    }

    Camera_rem_subscription_data.topic_name = DDS_String_dup("cameraView");
    Camera_rem_subscription_data.type_name = DDS_String_dup(dds_sensing_CameraTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Camera_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Camera_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    Camera_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 202;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "perception_dp",        /* Note: this string should match the remote participant name */
        &Camera_rem_subscription_data,
        dds_sensing_Camera_get_key_kind(dds_sensing_CameraTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in perception_dp\n");
        goto done;
    }

    Camera_hw_datawriter = dds_sensing_CameraDataWriter_narrow(Camera_datawriter);
    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    Imu_real_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    Imu_real_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    Imu_real_dw_qos.resource_limits.max_samples_per_instance = 4;
    Imu_real_dw_qos.resource_limits.max_instances = 1;
    Imu_real_dw_qos.resource_limits.max_samples = Imu_real_dw_qos.resource_limits.max_instances *
        Imu_real_dw_qos.resource_limits.max_samples_per_instance;
    Imu_real_dw_qos.history.depth = 4;
    Imu_real_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    Imu_real_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    Imu_real_dw_listener.on_publication_matched = dds_sensing_imu_Imu_realPublisher_on_publication_matched;
	Imu_real_dw_qos.protocol.rtps_object_id = 147;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    Imu_real_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        Imu_real_topic,
        &Imu_real_dw_qos,
        &Imu_real_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (Imu_real_datawriter == NULL)
    {
        printf("Imu_real_datawriter == NULL\n");
        goto done;
    }

    Imu_real_rem_subscription_data.topic_name = DDS_String_dup("imuData");
    Imu_real_rem_subscription_data.type_name = DDS_String_dup(dds_sensing_imu_Imu_realTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Imu_real_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Imu_real_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    Imu_real_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 227;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "egoMotion_dp",        /* Note: this string should match the remote participant name */
        &Imu_real_rem_subscription_data,
        dds_sensing_imu_Imu_real_get_key_kind(dds_sensing_imu_Imu_realTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in egoMotion_dp\n");
        goto done;
    }

    Imu_real_hw_datawriter = dds_sensing_imu_Imu_realDataWriter_narrow(Imu_real_datawriter);
    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    Compass_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    Compass_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    Compass_dw_qos.resource_limits.max_samples_per_instance = 4;
    Compass_dw_qos.resource_limits.max_instances = 1;
    Compass_dw_qos.resource_limits.max_samples = Compass_dw_qos.resource_limits.max_instances *
        Compass_dw_qos.resource_limits.max_samples_per_instance;
    Compass_dw_qos.history.depth = 4;
    Compass_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    Compass_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    Compass_dw_listener.on_publication_matched = dds_sensing_CompassPublisher_on_publication_matched;
	Compass_dw_qos.protocol.rtps_object_id = 148;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    Compass_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        Compass_topic,
        &Compass_dw_qos,
        &Compass_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (Compass_datawriter == NULL)
    {
        printf("Compass_datawriter == NULL\n");
        goto done;
    }

    Compass_rem_subscription_data.topic_name = DDS_String_dup("compass");
    Compass_rem_subscription_data.type_name = DDS_String_dup(dds_sensing_CompassTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Compass_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Compass_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    Compass_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 228;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "egoMotion_dp",        /* Note: this string should match the remote participant name */
        &Compass_rem_subscription_data,
        dds_sensing_Compass_get_key_kind(dds_sensing_CompassTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in egoMotion_dp\n");
        goto done;
    }

    Compass_hw_datawriter = dds_sensing_CompassDataWriter_narrow(Compass_datawriter);
    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    Basic_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    Basic_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    Basic_dw_qos.resource_limits.max_samples_per_instance = 4;
    Basic_dw_qos.resource_limits.max_instances = 2;
    Basic_dw_qos.resource_limits.max_samples = Basic_dw_qos.resource_limits.max_instances *
        Basic_dw_qos.resource_limits.max_samples_per_instance;
    Basic_dw_qos.history.depth = 4;
    Basic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    Basic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    Basic_dw_listener.on_publication_matched = dds_sensing_gnss_BasicPublisher_on_publication_matched;
	Basic_dw_qos.protocol.rtps_object_id = 146;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    Basic_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        Basic_topic,
        &Basic_dw_qos,
        &Basic_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (Basic_datawriter == NULL)
    {
        printf("Basic_datawriter == NULL\n");
        goto done;
    }
    Basic_rem_subscription_data.topic_name = DDS_String_dup("gnssPosition");
    Basic_rem_subscription_data.type_name = DDS_String_dup(dds_sensing_gnss_BasicTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    Basic_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    Basic_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    Basic_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 216;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "localization_dp",        /* Note: this string should match the remote participant name */
        &Basic_rem_subscription_data,
        dds_sensing_gnss_Basic_get_key_kind(dds_sensing_gnss_BasicTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in localization_dp\n");
        goto done;
    }
    Basic_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 226;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "egoMotion_dp",        /* Note: this string should match the remote participant name */
        &Basic_rem_subscription_data,
        dds_sensing_gnss_Basic_get_key_kind(dds_sensing_gnss_BasicTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in egoMotion_dp\n");
        goto done;
    }

    Basic_hw_datawriter = dds_sensing_gnss_BasicDataWriter_narrow(Basic_datawriter);
    /* Reliability QoS */
#ifdef USE_RELIABLE_QOS
    MapData_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else  /* USE_RELIABLE_QOS */
    MapData_dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif  /* USE_RELIABLE_QOS */
    MapData_dw_qos.resource_limits.max_samples_per_instance = 4;
    MapData_dw_qos.resource_limits.max_instances = 2;
    MapData_dw_qos.resource_limits.max_samples = MapData_dw_qos.resource_limits.max_instances *
        MapData_dw_qos.resource_limits.max_samples_per_instance;
    MapData_dw_qos.history.depth = 4;
    MapData_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    MapData_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    MapData_dw_listener.on_publication_matched = dds_planning_MapDataPublisher_on_publication_matched;
	MapData_dw_qos.protocol.rtps_object_id = 145;  /* Note: must assign unique numbers to each instance */

    /* create datawriters for each pub topic */
    MapData_datawriter = DDS_Publisher_create_datawriter(
        publisher,
        MapData_topic,
        &MapData_dw_qos,
        &MapData_dw_listener,
        DDS_PUBLICATION_MATCHED_STATUS);

    if (MapData_datawriter == NULL)
    {
        printf("MapData_datawriter == NULL\n");
        goto done;
    }

    MapData_rem_subscription_data.topic_name = DDS_String_dup("mapData");
    MapData_rem_subscription_data.type_name = DDS_String_dup(dds_planning_MapDataTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    MapData_rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    MapData_rem_subscription_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    /* assert for every expected subscriber */
    MapData_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 235;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "sceneEval_dp",        /* Note: this string should match the remote participant name */
        &MapData_rem_subscription_data,
        dds_planning_MapData_get_key_kind(dds_planning_MapDataTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in sceneEval_dp\n");
        goto done;
    }
    MapData_rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 205;
    if (DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
        application->participant, "perception_dp",        /* Note: this string should match the remote participant name */
        &MapData_rem_subscription_data,
        dds_planning_MapData_get_key_kind(dds_planning_MapDataTypePlugin_get(), NULL)))
    {
        printf("failed to assert remote subscription in perception_dp\n");
        goto done;
    }

    MapData_hw_datawriter = dds_planning_MapDataDataWriter_narrow(MapData_datawriter);
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
    StatusTopic_dr_qos.resource_limits.max_instances = 1;
#else  /* USE_SAMPLE_FILTER */
    StatusTopic_dr_qos.resource_limits.max_instances = 2;
#endif  /* USE_SAMPLE_FILTER */

    StatusTopic_dr_qos.resource_limits.max_samples_per_instance = 8;
    StatusTopic_dr_qos.resource_limits.max_samples = StatusTopic_dr_qos.resource_limits.max_instances *
        StatusTopic_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    StatusTopic_dr_qos.reader_resource_limits.max_remote_writers = 1;
    StatusTopic_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 1;
    StatusTopic_dr_qos.history.depth = 8;

#ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
#ifdef FILTER_ON_DESERIALIZE
    StatusTopic_dr_listener.on_before_sample_deserialize =
        dds_system_StatusTopicSubscriber_on_before_sample_deserialize;
#else  /* FILTER_ON_DESERIALIZE */
    StatusTopic_dr_listener.on_before_sample_commit =
        dds_system_StatusTopicSubscriber_on_before_sample_commit;
#endif  /* FILTER_ON_DESERIALIZE */
#endif  /* USE_SAMPLE_FILTER */

    StatusTopic_dr_listener.on_data_available = dds_system_StatusTopicSubscriber_on_data_available;
    StatusTopic_dr_listener.on_subscription_matched =
        dds_system_StatusTopicSubscriber_on_subscription_matched;

    StatusTopic_dr_listener.as_listener.listener_data = &total_samples;
    StatusTopic_dr_qos.protocol.rtps_object_id = 249;  /* Note: must assign unique numbers to each instance */

    StatusTopic_datareader = DDS_Subscriber_create_datareader(
        subscriber,
        DDS_Topic_as_topicdescription(StatusTopic_topic),
        &StatusTopic_dr_qos,
        &StatusTopic_dr_listener,
        DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);

    if (StatusTopic_datareader == NULL)
    {
        printf("StatusTopic_datareader == NULL\n");
        goto done;
    }

    StatusTopic_rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 139;
    StatusTopic_rem_publication_data.topic_name = DDS_String_dup("egoStatus");
    StatusTopic_rem_publication_data.type_name = DDS_String_dup(dds_system_StatusTopicTypeSupport_get_type_name());

#ifdef USE_RELIABLE_QOS
    StatusTopic_rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    StatusTopic_rem_publication_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    retcode = DPSE_RemotePublication_assert(
        application->participant,
        "sceneEval_dp",           /* Note: this string should match the remote participant name */
        &StatusTopic_rem_publication_data,
        dds_system_StatusTopic_get_key_kind(dds_system_StatusTopicTypePlugin_get(), NULL));

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to assert remote publication\n");
        goto done;
    }

#ifdef RTI_CERT
#ifdef RTI_VXWORKS
    /** End initialization, disable further dynamic memory allocation ***/
    memAllocDisable();
#endif  /* RTI_VXWORKS */
#endif  /* RTI_CERT */

    // initialize the write data sample(s)
    Lidar_sample->parent.id[0] = 456;
    Lidar_sample->parent.id[1] = 0;
    dds_sensing_pointcloud_PointDataRecordSeq_set_length(&Lidar_sample->pointcloud.point, PTCLOUD_POINTS_GEN);
    Lidar_sample->pointcloud.scale.x = 1.0f;
    Lidar_sample->pointcloud.scale.y = 1.0f;
    Lidar_sample->pointcloud.scale.z = 1.0f;
    Lidar_sample->pointcloud.offset.x = 0.0f;
    Lidar_sample->pointcloud.offset.y = 0.0f;
    Lidar_sample->pointcloud.offset.z = 0.0f;
    Lidar_sample->pointcloud.point_max.x = 5.0f;
    Lidar_sample->pointcloud.point_max.y = 5.0f;
    Lidar_sample->pointcloud.point_max.z = 10.0f;
    Lidar_sample->pointcloud.point_min.x = -5.0f;
    Lidar_sample->pointcloud.point_min.y = -5.0f;
    Lidar_sample->pointcloud.point_min.z = 0.0f;
    Lidar_sample->pointcloud.point_return_count[0] = PTCLOUD_POINTS_GEN;
    Camera_sample->parent.id[0] = 457;
    Camera_sample->parent.id[1] = 0;
#define CAMERA_PIXEL_COUNT 16           /* undersized; set to frame size */
    dds_base_ByteSeq_set_length(&Camera_sample->image.pixel, CAMERA_PIXEL_COUNT);
    Camera_sample->image.height = dds_sensing_image_MAX_HEIGHT;
    Camera_sample->image.width = dds_sensing_image_MAX_WIDTH;
    Camera_sample->image.width_step = dds_sensing_image_MAX_WIDTH;
    Imu_real_sample->parent.id[0] = 458;
    Imu_real_sample->parent.id[1] = 0;
    Compass_sample->parent.id[0] = 459;
    Compass_sample->parent.id[1] = 0;
    Basic_sample->parent.id[0] = 460;
    Basic_sample->parent.id[1] = 0;
    MapData_sample->parent.id[0] = 461;
    MapData_sample->parent.id[1] = 0;
    MapData_sample->data = "<requested map data goes here>";
    struct timespec tStamp;

    /* loop ---------------- */
    for (i = 0; (application->count <= 0) || (i < application->count); ++i)
    {
        /* set sample attributes here */
        ptcloud_gen_data(&Lidar_sample->pointcloud);

        retcode = dds_sensing_LidarDataWriter_write(
            Lidar_hw_datawriter,
            Lidar_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "Lidar");
        }
        else
        {
            printf("Written Lidar sample %d\n",(i+1));
        }

        for(int j=0 ; j<CAMERA_PIXEL_COUNT ; j++) {
            dds_base_Byte *tmpPixel = dds_base_ByteSeq_get_reference(&Camera_sample->image.pixel, j);
            *tmpPixel = (dds_base_Byte)(rand());
        }
        retcode = dds_sensing_CameraDataWriter_write(
            Camera_hw_datawriter,
            Camera_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "Camera");
        }
        else
        {
            printf("Written Camera sample %d\n",(i+1));
        }

        Imu_real_sample->orientation.x = randFloatInRange(0.0f, 6.28f);
        Imu_real_sample->orientation.y = randFloatInRange(0.0f, 6.28f);
        Imu_real_sample->orientation.z = randFloatInRange(0.0f, 6.28f);
        Imu_real_sample->orientation.w = randFloatInRange(0.0f, 0.123f);
        Imu_real_sample->angular_velocity.x = randFloatInRange(0.10f, 0.20f);
        Imu_real_sample->angular_velocity.y = randFloatInRange(0.10f, 0.20f);
        Imu_real_sample->angular_velocity.z = randFloatInRange(0.10f, 0.20f);
        Imu_real_sample->linear_acceleration.x = randFloatInRange(0.10f, 0.20f);
        Imu_real_sample->linear_acceleration.y = randFloatInRange(0.10f, 0.20f);
        Imu_real_sample->linear_acceleration.z = randFloatInRange(0.10f, 0.20f);
        retcode = dds_sensing_imu_Imu_realDataWriter_write(
            Imu_real_hw_datawriter,
            Imu_real_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "Imu_real");
        }
        else
        {
            printf("Written Imu_real sample %d\n",(i+1));
        }

        tstamp_get(&tStamp);
        Compass_sample->utc_seconds = tStamp.tv_sec;
        Compass_sample->heading = randFloatInRange(0.0f, 360.0f);
        retcode = dds_sensing_CompassDataWriter_write(
            Compass_hw_datawriter,
            Compass_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "Compass");
        }
        else
        {
            printf("Written Compass sample %d\n",(i+1));
        }

        Basic_sample->lat = randFloatInRange(-90.0f, 90.0f);
        Basic_sample->lon = randFloatInRange(-180.0f, 180.0f);
        Basic_sample->alt = randFloatInRange(0.0f, 30.0f);
        Basic_sample->utc_seconds = tStamp.tv_sec;
        retcode = dds_sensing_gnss_BasicDataWriter_write(
            Basic_hw_datawriter,
            Basic_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "Basic");
        }
        else
        {
            printf("Written GNSS sample %d\n",(i+1));
        }

        MapData_sample->seq_id = i;
        MapData_sample->timestamp.sec = tStamp.tv_sec;
        MapData_sample->timestamp.nanosec = tStamp.tv_nsec;
        retcode = dds_planning_MapDataDataWriter_write(
            MapData_hw_datawriter,
            MapData_sample,
            &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write %s sample\n", "MapData");
        }
        else
        {
            printf("Written MapData sample %d\n",(i+1));
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

    if (Lidar_sample != NULL)
    {
        dds_sensing_LidarTypeSupport_delete_data(Lidar_sample);
    }
    if (Camera_sample != NULL)
    {
        dds_sensing_CameraTypeSupport_delete_data(Camera_sample);
    }
    if (Imu_real_sample != NULL)
    {
        dds_sensing_imu_Imu_realTypeSupport_delete_data(Imu_real_sample);
    }
    if (Compass_sample != NULL)
    {
        dds_sensing_CompassTypeSupport_delete_data(Compass_sample);
    }
    if (Basic_sample != NULL)
    {
        dds_sensing_gnss_BasicTypeSupport_delete_data(Basic_sample);
    }
    if (MapData_sample != NULL)
    {
        dds_planning_MapDataTypeSupport_delete_data(MapData_sample);
    }

#endif  /* RTI_CERT */
#ifndef RTI_CERT
    retcode = DDS_DataWriterQos_finalize(&Lidar_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&Lidar_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Lidar\n");
        return -1;
    }

    retcode = DDS_DataWriterQos_finalize(&Camera_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&Camera_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Camera\n");
        return -1;
    }

    retcode = DDS_DataWriterQos_finalize(&Imu_real_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&Imu_real_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Imu_real\n");
        return -1;
    }

    retcode = DDS_DataWriterQos_finalize(&Compass_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&Compass_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Compass\n");
        return -1;
    }

    retcode = DDS_DataWriterQos_finalize(&Basic_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&Basic_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for Basic\n");
        return -1;
    }

    retcode = DDS_DataWriterQos_finalize(&MapData_dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataWriterQos\n");
        return -1;
    }
    if (DDS_SubscriptionBuiltinTopicData_finalize(&MapData_rem_subscription_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for MapData\n");
        return -1;
    }

    retcode = DDS_DataReaderQos_finalize(&StatusTopic_dr_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot finalize DataReaderQos\n");
        return -1;
    }
    if (DDS_PublicationBuiltinTopicData_finalize(&StatusTopic_rem_publication_data) !=
    DDS_BOOLEAN_TRUE)
    {
        printf("Cannot finalize DDS_SubscriptionBuiltinTopicData for StatusTopic\n");
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
