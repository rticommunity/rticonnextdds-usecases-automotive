/** ------------------------------------------------------------------------
 * CameraImageData_publisher.cxx
 * Publishes fixed-frame data arrays of type "CameraImageData" defined in 
 * automotive.idl file, with options for "Flat Data" and/or "Zero Copy"
 * optimizations to be included.
 *
 * The data is generated from an LFSR function, with optional verification
 * at the receiving end.   Timestamps are included to measure the transit
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

// uncomment one|other|both|neither of the following for FLAT_DATA | ZERO_COPY | FLAT and ZERO | (standard DDS) speedup
// #define DDS_LARGE_DATA_FLAT_DATA
// #define DDS_LARGE_DATA_ZERO_COPY

// seed for LFSR used for striping the data array
#define LFSR_SEED   (0x55555555)

uint32_t lfsr = LFSR_SEED;
uint32_t seqNum = 1;


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

/* Delete all entities */
static int publisher_shutdown(
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

    /* RTI Connext provides finalize_instance() method on
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

#ifdef DDS_LARGE_DATA_FLAT_DATA
/** ----------------------------------------------------------------
 * build_data_sample()
 * Fill the sample's data array with LFSR data, then add a current
 * timestamp to measure the transfer time at the subscriper.
 * This uses a plain_cast to speed the fill of the sample array.
 * returns true
 **/
bool build_data_sample(CameraImage_CameraImageDataBuilder& builder)
{
    // Build the CameraImage_CameraImageData data sample
    builder.add_id(LFSR_SEED);
    builder.add_seqnum(seqNum++);
    auto data_offset = builder.add_data();
    auto data_array = rti::flat::plain_cast(data_offset);
    for (int i = 0; i < MAX_IMAGE_SIZE; i += 4) {
        uint32_t *lfsrVal = (uint32_t *)&data_array[i];
        *lfsrVal = lfsr;
        lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xD0000001u);
    }
    uint64_t tNow = UtcNowPrecise();
    builder.add_sec_(tNow / 10000000);
    builder.add_nanosec_(tNow % 10000000);
    return true;
}
#endif 	// DDS_LARGE_DATA_FLAT_DATA

/** ----------------------------------------------------------------
 * publisher_main()
 * create the topic publisher & send data.
 **/
extern "C" int publisher_main(int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    CameraImage_CameraImageDataDataWriter * CameraImage_CameraImageData_writer = NULL;
    CameraImage_CameraImageData *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int domainId = 0;
    int count = 0;  
    DDS_Duration_t send_period = {4,0};

    /* Get the configurtion properties from the camera_image.properties file */
    PropertyUtil* prop = new PropertyUtil("camera_image.properties");

    long time = prop->getLongProperty("config.pubInterval");
    if (time) {
        send_period.sec = time / 1000;
        send_period.nanosec = (time % 1000) * 1000 * 1000;
    }

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

    /* To customize participant QoS, use the configuration file USER_QOS_PROFILES.xml */

    // create participant
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), qosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error(%s:%d)\n", __FILE__, __LINE__);
        publisher_shutdown(participant);
        return -1;
    }

    // create publisher
    publisher = participant->create_publisher_with_profile(
        qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        fprintf(stderr, "create_publisher error(%s:%d)\n", __FILE__, __LINE__);
        publisher_shutdown(participant);
        return -1;
    }

    // register and create topic
    type_name = CameraImage_CameraImageDataTypeSupport::get_type_name();
    retcode = CameraImage_CameraImageDataTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
        publisher_shutdown(participant);
        return -1;
    }

    topic = participant->create_topic_with_profile(
        topicName.c_str(),
        type_name, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        fprintf(stderr, "create_topic error(%s:%d)\n", __FILE__, __LINE__);
        publisher_shutdown(participant);
        return -1;
    }

    // create datawriter
    writer = publisher->create_datawriter_with_profile(
        topic, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        fprintf(stderr, "create_datawriter error(%s:%d)\n", __FILE__, __LINE__);
        publisher_shutdown(participant);
        return -1;
    }
    CameraImage_CameraImageData_writer = CameraImage_CameraImageDataDataWriter::narrow(writer);
    if (CameraImage_CameraImageData_writer == NULL) {
        fprintf(stderr, "DataWriter narrow error(%s:%d)\n", __FILE__, __LINE__);
        publisher_shutdown(participant);
        return -1;
    }

#ifndef DDS_LARGE_DATA_FLAT_DATA
#ifndef DDS_LARGE_DATA_ZERO_COPY
    /* Create data sample for writing */
    instance = CameraImage_CameraImageDataTypeSupport::create_data();
    if (instance == NULL) {
        fprintf(stderr, "CameraImage_CameraImageDataTypeSupport::create_data error(%s:%d)\n", __FILE__, __LINE__);
        publisher_shutdown(participant);
        return -1;
    }

    // CameraImageData type uses a @key; init and register it here
    instance->id = lfsr;
    instance_handle = CameraImage_CameraImageData_writer->register_instance(*instance);

#endif	// ndef DDS_LARGE_DATA_ZERO_COPY
#endif	// ndef DDS_LARGE_DATA_FLAT_DATA

    printf("start sending\n");
    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {
#ifdef DDS_LARGE_DATA_FLAT_DATA
        CameraImage_CameraImageDataBuilder builder = rti::flat::build_data<CameraImage_CameraImageData>(CameraImage_CameraImageData_writer);
        if (builder.check_failure()) {
            printf("builder creation error (%s:%d)\n", __FILE__, __LINE__);
            publisher_shutdown(participant);
            return -1;
        }

        // Build the CameraImage_CameraImageData data sample using the builder
        if (!build_data_sample(builder)) {
            printf("error building the sample(%s:%d)\n", __FILE__, __LINE__);
            publisher_shutdown(participant);
            return -1;
        }

        // Create the sample
        CameraImage_CameraImageData *instance = builder.finish_sample();
        if (instance == NULL) {
            printf("finish_sample() error(%s:%d)\n", __FILE__, __LINE__);
            publisher_shutdown(participant);
            return -1;            
        }
#endif 	// def DDS_LARGE_DATA_FLAT_DATA
#ifdef DDS_LARGE_DATA_ZERO_COPY
#ifndef DDS_LARGE_DATA_FLAT_DATA
        /* Get a new sample before every write. This data sample can come from a
        free sample or a previously written sample which is ready for reuse. */

        retcode = CameraImage_CameraImageData_writer->get_loan(instance);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "CameraImage_CameraImageDataDataWriter_get_loan error(%s:%d)\n", __FILE__, __LINE__);
            publisher_shutdown(participant);
            return -1;
        }
#endif 	// ndef DDS_LARGE_DATA_FLAT_DATA
#endif	//  def DDS_LARGE_DATA_ZERO_COPY
        printf("Writing CameraImage_CameraImageData, count %d\n", count);

#ifndef DDS_LARGE_DATA_FLAT_DATA
        /* If not using Flat Data, Modify the data to be sent here */
        for (int i = 0; i < MAX_IMAGE_SIZE; i+=4) {
            uint32_t *lfsrVal = (uint32_t *)&instance->data[i];
            *lfsrVal = lfsr;
            lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xD0000001u);
        }
        instance->seqnum = seqNum++;
        uint64_t tNow = UtcNowPrecise();
        instance->sec_ = (tNow / 10000000);
        instance->nanosec_ = (tNow % 10000000);
        //printf("tNow: %llu = %u.%u\n", tNow, instance->sec_, instance->nanosec_);


#endif  // ndef DDS_LARGE_DATA_FLAT_DATA

        retcode = CameraImage_CameraImageData_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "write error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
        }

        NDDSUtility::sleep(send_period);
    }

#ifndef DDS_LARGE_DATA_FLAT_DATA
#ifndef DDS_LARGE_DATA_ZERO_COPY
    /*
    retcode = CameraImage_CameraImageData_writer->unregister_instance(
        *instance, instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "unregister instance error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
    }
    */

    /* Delete data sample */
    retcode = CameraImage_CameraImageDataTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "CameraImage_CameraImageDataTypeSupport::delete_data error %d (%s:%d)\n", retcode, __FILE__, __LINE__);
    }
#endif // ndef DDS_LARGE_DATA_ZERO_COPY
#endif // ndef DDS_LARGE_DATA_FLAT_DATA

    /* Delete all entities */
    return publisher_shutdown(participant);
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
    NDDSConfigLogger::get_instance()->
    set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
    NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */

    return publisher_main(sample_count);
}

