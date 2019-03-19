/** ------------------------------------------------------------------------
 * CameraImageData_subscriber.cxx
 * Subscribes to fixed-frame data arrays of type "CameraImageData" defined in 
 * automotive.idl file, with options for "Flat Data" optimizations to be 
 * included (note: "Zero Copy" optimizations do not require changes in this file.
 *
 * The data is generated from an LFSR function in the publisher, and can optionally
 * be verified here in the subscriber.  Timestamps have also been included in the
 * published packets, these are used here in the subscriber to measure the transit
 * times of each optimization mode.
 *
 * (c) 2005-2019 Copyright, Real-Time Innovations, Inc.  All rights reserved.    	                             
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the Software.  Licensee has the right to distribute object form
 * only for use with RTI products.  The Software is provided 'as is', with no
 * arranty of any type, including any warranty for fitness for any purpose. RTI
 * is under no obligation to maintain or support the Software.  RTI shall not
 * be liable for any incidental or consequential damages arising out of the
 * use or inability to use the software.
 **/
#include <stdio.h>
#include <stdlib.h>

#include "dataObject.h"
#include "Utils.h"

#include "automotive.h"
#include "automotiveSupport.h"
#include "ndds/ndds_cpp.h"

#ifdef _WIN32
#include <Windows.h>
#endif  // def _WIN32

// uncomment if using FLAT_DATA
// #define DDS_LARGE_DATA_FLAT_DATA

#ifdef _WIN32
#define  TICKS_PER_DAY ((uint64_t)864000000000)         // 100nS resolution
uint64_t UtcNowPrecise()
{
    const uint64_t OA_ZERO_TICKS = 94353120000000000; //12/30/1899 12:00am in ticks
    // const uint64_t TICKS_PER_DAY = 864000000000;      //ticks per day

    FILETIME ft;
    GetSystemTimePreciseAsFileTime(&ft);

    ULARGE_INTEGER dt; //needed to avoid alignment faults
    dt.LowPart = ft.dwLowDateTime;
    dt.HighPart = ft.dwHighDateTime;
    return dt.QuadPart - OA_ZERO_TICKS;
}
#endif  // def _WIN32


class CameraImage_CameraImageDataListener : public DDSDataReaderListener {
  public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {}

    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader* reader);
};

/** ----------------------------------------------------------------
 * calcAndPrintTransitTime()
 * given a send timestamp and a receive timestamp, calculate and print
 * the timing stats and sample counter.
 **/
void calcAndPrintTransitTime(uint64_t tSend, uint64_t tReceive)
{
    static uint64_t tMin = (uint64_t)-1;
    static uint64_t tMax = 0;
    static uint64_t tSum = 0;
    static uint32_t tSampleCount = 0;

    uint32_t tDelta = tReceive - tSend;
    if (tDelta < tMin)
        tMin = tDelta;
    if (tDelta > tMax)
        tMax = tDelta;
    tSum += tDelta;
    tSampleCount++;
    printf("tNow: %2.7f tMin: %2.7f tMax: %2.7f, tAvg: %2.7f Samples[%u] size:%u\n",
        ((double)tDelta / 10000000),
        ((double)tMin / 10000000),
        ((double)tMax / 10000000),
        (((double)tSum / tSampleCount) / 10000000), tSampleCount,
        MAX_IMAGE_SIZE);
    return;
}

/** ----------------------------------------------------------------
 * checkLfsrDataInArray()
 * Check the u32 data in array for correct LFSR sequence, based on 
 * value in position [0].  Scan until MAX_IMAGE_SIZE
 * returns true if no error
 **/
bool checkLfsrDataInArray(uint32_t *lfsrArray)
{
    uint32_t lfsr = *lfsrArray;
    for (int j = 4; j < MAX_IMAGE_SIZE; j += 4) {
        lfsrArray++;
        lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xD0000001u);
        if (lfsr != *lfsrArray) {
            printf("Image data received != sent [%08x != %08x] at %s:%d\n", *lfsrArray, lfsr, __FILE__, __LINE__);
            return false;
        }
    }
    return true;
}

/** ----------------------------------------------------------------
 * on_data_available()
 * Data listener -- called when new data has been received.
 **/
void CameraImage_CameraImageDataListener::on_data_available(DDSDataReader* reader)
{
    CameraImage_CameraImageDataDataReader *CameraImage_CameraImageData_reader = NULL;
    CameraImage_CameraImageDataSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    CameraImage_CameraImageData_reader = CameraImage_CameraImageDataDataReader::narrow(reader);
    if (CameraImage_CameraImageData_reader == NULL) {
        fprintf(stderr, "DataReader narrow error(%s:%d)\n", __FILE__, __LINE__);
        return;
    }

    retcode = CameraImage_CameraImageData_reader->take(
        data_seq, info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    } else if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "take error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) {
        if (info_seq[i].valid_data) {
            // get the current time value
            uint64_t tReceive = UtcNowPrecise();

#ifdef DDS_LARGE_DATA_FLAT_DATA
            // get the root to the Flat Data sample            
            CameraImage_CameraImageDataOffset sample_root = data_seq[i].root();

            // get the send-timestamp value from the received packet
            uint64_t tSend = (((uint64_t)sample_root.sec_()) * 10000000) + sample_root.nanosec_();

            // verify the contents of the received data (optional)
            auto data_array = rti::flat::plain_cast(sample_root.data());
            uint32_t *rcvBuffer = (uint32_t *)&data_array[0];
            checkLfsrDataInArray(rcvBuffer);

#else  // ndef DDS_LARGE_DATA_FLAT_DATA
            // get the send-timestamp value from the received packet
            uint64_t tSend = (((uint64_t)data_seq[i].sec_) * 10000000) + data_seq[i].nanosec_;

            // verify the contents of the received data (optional)
            uint32_t *rcvBuffer = (uint32_t *) &data_seq[i].data[0];
            checkLfsrDataInArray(rcvBuffer);

#endif  // ndef DDS_LARGE_DATA_FLAT_DATA
            // print the transit timing
            calcAndPrintTransitTime(tSend, tReceive);
        }
    }

    retcode = CameraImage_CameraImageData_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "return loan error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
    }
}

/* Delete all entities */
static int subscriber_shutdown(
    DDSDomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
            status = -1;
        }
    }

    /* RTI Connext provides the finalize_instance() method on
    domain participant factory for people who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
        status = -1;
    }
    */
    return status;
}

/** ----------------------------------------------------------------
* subscriber_main()
* create the topic subscriber & receive data.
**/extern "C" int subscriber_main(int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSSubscriber *subscriber = NULL;
    DDSTopic *topic = NULL;
    CameraImage_CameraImageDataListener *reader_listener = NULL; 
    DDSDataReader *reader = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int count = 0;
    int domainId = 0;
    DDS_Duration_t receive_period = {4,0};
    int status = 0;

    /* Get the configurtion properties from the camera_image.properties file */
    PropertyUtil* prop = new PropertyUtil("camera_image.properties");

    long time = prop->getLongProperty("config.pubInterval");
    receive_period.sec = time / 1000;
    receive_period.nanosec = (time % 1000) * 1000 * 1000;

    domainId = prop->getLongProperty("config.domainId");
    std::string topicName = prop->getStringProperty("topic.Sensor");
    if (topicName == "") {
        printf("No topic name specified (%s:%d)\n", __FILE__, __LINE__);
        return -1;
    }

    std::string qosLibrary = prop->getStringProperty("qos.Library");
    if (qosLibrary == "") {
        printf("No QoS Library specified (%s:%d)\n", __FILE__, __LINE__);
        return -1;
    }
    std::string qosProfile = prop->getStringProperty("qos.Profile");
    if (qosProfile == "") {
        printf("No QoS Profile specified (%s:%d)\n", __FILE__, __LINE__);
        return -1;
    }



    /* To customize the participant QoS, use the configuration file USER_QOS_PROFILES.xml */
    // create participant
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), qosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error(%s:%d)\n", __FILE__, __LINE__);
        subscriber_shutdown(participant);
        return -1;
    }

    // create subscriber
    subscriber = participant->create_subscriber_with_profile(
        qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        fprintf(stderr, "create_subscriber error(%s:%d)\n", __FILE__, __LINE__);
        subscriber_shutdown(participant);
        return -1;
    }

    // register the type and create the topic
    type_name = CameraImage_CameraImageDataTypeSupport::get_type_name();
    retcode = CameraImage_CameraImageDataTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
        subscriber_shutdown(participant);
        return -1;
    }
    topic = participant->create_topic_with_profile(
        topicName.c_str(),
        type_name, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        fprintf(stderr, "create_topic error(%s:%d)\n", __FILE__, __LINE__);
        subscriber_shutdown(participant);
        return -1;
    }

    // create a data reader listener and datareader
    reader_listener = new CameraImage_CameraImageDataListener();
    reader = subscriber->create_datareader_with_profile(
        topic, qosLibrary.c_str(), qosProfile.c_str(), reader_listener,
        DDS_STATUS_MASK_ALL & ~~DDS_DATA_AVAILABLE_STATUS);
    if (reader == NULL) {
        fprintf(stderr, "create_datareader error(%s:%d)\n", __FILE__, __LINE__);
        subscriber_shutdown(participant);
        delete reader_listener;
        return -1;
    }


    printf("Start Receiving\n");
    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        // printf("CameraImage_CameraImageData subscriber sleeping for %d sec...\n", receive_period.sec);

        NDDSUtility::sleep(receive_period);
    }

    /* Delete all entities */
    status = subscriber_shutdown(participant);
    delete reader_listener;

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

