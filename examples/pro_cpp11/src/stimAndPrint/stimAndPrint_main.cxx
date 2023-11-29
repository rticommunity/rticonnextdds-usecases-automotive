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

#include <algorithm>
#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging
// alternatively, to include all the standard APIs:
//  <dds/dds.hpp>
// or to include both the standard APIs and extensions:
//  <rti/rti.hpp>
//
// For more information about the headers and namespaces, see:
//    https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/api/connext_dds/api_cpp2/group__DDSNamespaceModule.html
// For information on how to use extensions, see:
//    https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/api/connext_dds/api_cpp2/group__DDSCpp2Conventions.html

#include "res/types/data/rti/sensing/Lidar_tPlugin.hpp"
#include "res/types/data/rti/sensing/Camera_tPlugin.hpp"
#include "res/types/data/rti/sensing/Imu_tPlugin.hpp"
#include "res/types/data/rti/sensing/Compass_tPlugin.hpp"
#include "res/types/data/rti/sensing/Gnss_tPlugin.hpp"
#include "res/types/data/rti/planning/Maps_tPlugin.hpp"
#include "res/types/data/rti/system/StatusTopic_tPlugin.hpp"

// Listener that will be notified of DataWriter events
class LidarDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::sensing::Lidar> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::sensing::Lidar>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::sensing::Lidar>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::sensing::Lidar>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::sensing::Lidar>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataWriter events
class CameraDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::sensing::Camera> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::sensing::Camera>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::sensing::Camera>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::sensing::Camera>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::sensing::Camera>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataWriter events
class Imu_realDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::sensing::imu::Imu_real> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::sensing::imu::Imu_real>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::sensing::imu::Imu_real>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::sensing::imu::Imu_real>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::sensing::imu::Imu_real>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataWriter events
class CompassDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::sensing::Compass> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::sensing::Compass>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::sensing::Compass>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::sensing::Compass>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::sensing::Compass>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataWriter events
class BasicDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::sensing::gnss::Basic> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::sensing::gnss::Basic>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::sensing::gnss::Basic>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::sensing::gnss::Basic>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::sensing::gnss::Basic>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataWriter events
class MapDataDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::planning::MapData> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::planning::MapData>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::planning::MapData>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::planning::MapData>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::planning::MapData>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class StatusTopicDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::system::StatusTopic> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::system::StatusTopic>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::system::StatusTopic>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::system::StatusTopic>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::system::StatusTopic>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::system::StatusTopic>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::system::StatusTopic>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};

int StatusTopic_process_data(dds::sub::DataReader<dds::system::StatusTopic> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::system::StatusTopic> samples = reader.take();
    for (const auto& sample : samples) {
        if (sample.info().valid()) {
            count++;
            std::cout << sample.data() << std::endl;
        } else {
            std::cout << "Instance state changed to "
            << sample.info().state().instance_state() << std::endl;
        }
    }

    return count;
} // The LoanedSamples destructor returns the loan

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
    float rspan = static_cast<float>(high-low);
    return low + static_cast<int32_t>((rval * rspan));
}

// utility timestamp functions
void tstamp_get(timespec *tStamp)
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
void ptcloud_gen_data(dds::sensing::pointcloud::PointDataRecord *ptData)
{
    for(int i=0; i<PTCLOUD_POINTS_GEN ; i++)
    {
        ptData[i].x(randInt32InRange(-5000, 5000));
        ptData[i].y(randInt32InRange(-5000, 5000));
        ptData[i].z(randInt32InRange(0, 10000));
        ptData[i].intensity(static_cast<uint16_t>(randInt32InRange(0,1000)));
        ptData[i].pulse_return(0);
        ptData[i].classification(0);
        ptData[i].scan_angle_rank(0);
        ptData[i].user_data(0);
        ptData[i].point_source_id(0);
        timespec tStamp;
        tstamp_get(&tStamp);
        dds::base::Float64 tReal = static_cast<dds::base::Float64>(tStamp.tv_sec) + (static_cast<dds::base::Float64>(tStamp.tv_nsec) / 1000000000.0);
        ptData[i].gps_time(tReal);
    }
}
/* end added-in helper functions ------------------------------- */

void run_participant_application(unsigned int domain_id)
{
    // DDS objects behave like shared pointers or value types
    // (see https://community.rti.com/best-practices/use-modern-c-types-correctly)

    // Start communicating in a domain, usually one participant per application
    // Load QoS profile from USER_QOS_PROFILES.xml file
    dds::domain::DomainParticipant participant(
        domain_id,
        dds::core::QosProvider::Default().participant_qos(
            "exampleQoSLibrary::exampleQoSProfile"));

    // Create Topics with a name and a datatype
    dds::topic::Topic<dds::sensing::Lidar> Lidar_topic(participant, "lidarPoints");
    dds::topic::Topic<dds::sensing::Camera> Camera_topic(participant, "cameraView");
    dds::topic::Topic<dds::sensing::imu::Imu_real> Imu_real_topic(participant, "imuData");
    dds::topic::Topic<dds::sensing::Compass> Compass_topic(participant, "compass");
    dds::topic::Topic<dds::sensing::gnss::Basic> Basic_topic(participant, "gnssPosition");
    dds::topic::Topic<dds::planning::MapData> MapData_topic(participant, "mapData");
    dds::topic::Topic<dds::system::StatusTopic> StatusTopic_topic(participant, "egoStatus");

    // Create a Publisher
    dds::pub::Publisher publisher(participant);

    // Create a Subscriber
    dds::sub::Subscriber subscriber(participant);

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask Lidar_status_mask;
    Lidar_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Lidar_listener = std::make_shared<LidarDataWriterListener>();
    dds::pub::DataWriter<dds::sensing::Lidar> Lidar_writer(
        publisher,
        Lidar_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Lidar_listener,
            Lidar_status_mask);

    dds::sensing::Lidar Lidar_data;

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask Camera_status_mask;
    Camera_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Camera_listener = std::make_shared<CameraDataWriterListener>();
    dds::pub::DataWriter<dds::sensing::Camera> Camera_writer(
        publisher,
        Camera_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Camera_listener,
            Camera_status_mask);

    dds::sensing::Camera Camera_data;

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask Imu_real_status_mask;
    Imu_real_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Imu_real_listener = std::make_shared<Imu_realDataWriterListener>();
    dds::pub::DataWriter<dds::sensing::imu::Imu_real> Imu_real_writer(
        publisher,
        Imu_real_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Imu_real_listener,
            Imu_real_status_mask);

    dds::sensing::imu::Imu_real Imu_real_data;

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask Compass_status_mask;
    Compass_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Compass_listener = std::make_shared<CompassDataWriterListener>();
    dds::pub::DataWriter<dds::sensing::Compass> Compass_writer(
        publisher,
        Compass_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Compass_listener,
            Compass_status_mask);

    dds::sensing::Compass Compass_data;

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask Basic_status_mask;
    Basic_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Basic_listener = std::make_shared<BasicDataWriterListener>();
    dds::pub::DataWriter<dds::sensing::gnss::Basic> Basic_writer(
        publisher,
        Basic_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Basic_listener,
            Basic_status_mask);

    dds::sensing::gnss::Basic Basic_data;

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask MapData_status_mask;
    MapData_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto MapData_listener = std::make_shared<MapDataDataWriterListener>();
    dds::pub::DataWriter<dds::planning::MapData> MapData_writer(
        publisher,
        MapData_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            MapData_listener,
            MapData_status_mask);

    dds::planning::MapData MapData_data;

    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto StatusTopic_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto StatusTopic_listener = std::make_shared<StatusTopicDataReaderListener>();
    dds::sub::DataReader<dds::system::StatusTopic> StatusTopic_reader(
        subscriber,
        StatusTopic_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            StatusTopic_listener,
            StatusTopic_status_mask);

    dds::core::cond::WaitSet waitset;

    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int StatusTopic_samples_read = 0;
    dds::sub::cond::ReadCondition StatusTopic_read_condition(
        StatusTopic_reader,
        dds::sub::status::DataState::any(),
        [StatusTopic_reader, &StatusTopic_samples_read]() { StatusTopic_samples_read += StatusTopic_process_data(StatusTopic_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += StatusTopic_read_condition;
    int32_t samples_written = 0;
    timespec tStamp;

    // initialize the write data sample(s)
    Lidar_data.id().at(0) = 456;
    Lidar_data.id().at(1) = 0;
    Lidar_data.pointcloud().point().resize(PTCLOUD_POINTS_GEN);
    Lidar_data.pointcloud().scale().x(1.0f);
    Lidar_data.pointcloud().scale().y(1.0f);
    Lidar_data.pointcloud().scale().z(1.0f);
    Lidar_data.pointcloud().offset().x(0.0f);
    Lidar_data.pointcloud().offset().y(0.0f);
    Lidar_data.pointcloud().offset().z(0.0f);
    Lidar_data.pointcloud().point_max().x(5.0f);
    Lidar_data.pointcloud().point_max().y(5.0f);
    Lidar_data.pointcloud().point_max().z(10.0f);
    Lidar_data.pointcloud().point_min().x(-5.0f);
    Lidar_data.pointcloud().point_min().y(-5.0f);
    Lidar_data.pointcloud().point_min().z(0.0f);
    Lidar_data.pointcloud().point_return_count().at(0) = PTCLOUD_POINTS_GEN;
    Camera_data.id().at(0) = 457;
    Camera_data.id().at(1) = 0;
    Camera_data.image().pixel().resize(16);     // undersized; set to frame size
    Camera_data.image().height(dds::sensing::image::MAX_HEIGHT);
    Camera_data.image().width(dds::sensing::image::MAX_WIDTH);
    Camera_data.image().width_step(dds::sensing::image::MAX_WIDTH);
    Imu_real_data.id().at(0) = 458;
    Imu_real_data.id().at(1) = 0;
    Compass_data.id().at(0) = 459;
    Compass_data.id().at(1) = 0;
    Basic_data.id().at(0) = 460;
    Basic_data.id().at(1) = 0;
    MapData_data.id().at(0) = 461;
    MapData_data.id().at(1) = 0;
    MapData_data.data(std::string("<requested map data goes here>"));
    

    while (1) {
        // Modify the data to be written here
        ptcloud_gen_data(Lidar_data.pointcloud().point().data());

        std::cout << "Writing dds::sensing::Lidar, count " << samples_written << std::endl;
        Lidar_writer.write(Lidar_data);

        // Modify the data to be written here
        for(int i=0 ; i<16 ; i++) {
            Camera_data.image().pixel().at(i) = static_cast<uint8_t>(rand());
        }
        std::cout << "Writing dds::sensing::Camera, count " << samples_written << std::endl;
        Camera_writer.write(Camera_data);

        // Modify the data to be written here
        Imu_real_data.orientation().x(randFloatInRange(0.0f, 6.28f));
        Imu_real_data.orientation().y(randFloatInRange(0.0f, 6.28f));
        Imu_real_data.orientation().z(randFloatInRange(0.0f, 6.28f));
        Imu_real_data.orientation().w(randFloatInRange(0.0f, 0.123f));
        Imu_real_data.angular_velocity().x(randFloatInRange(0.10f, 0.20f));
        Imu_real_data.angular_velocity().y(randFloatInRange(0.10f, 0.20f));
        Imu_real_data.angular_velocity().z(randFloatInRange(0.10f, 0.20f));
        Imu_real_data.linear_acceleration().x(randFloatInRange(0.10f, 0.20f));
        Imu_real_data.linear_acceleration().y(randFloatInRange(0.10f, 0.20f));
        Imu_real_data.linear_acceleration().z(randFloatInRange(0.10f, 0.20f));
        std::cout << "Writing dds::sensing::imu::Imu_real, count " << samples_written << std::endl;
        Imu_real_writer.write(Imu_real_data);

        // Modify the data to be written here
        tstamp_get(&tStamp);
        Compass_data.utc_seconds(tStamp.tv_sec);
        Compass_data.heading(randFloatInRange(0.0f, 360.0f));
        std::cout << "Writing dds::sensing::Compass, count " << samples_written << std::endl;
        Compass_writer.write(Compass_data);

        // Modify the data to be written here
        Basic_data.lat(randFloatInRange(-90.0f, 90.0f));
        Basic_data.lon(randFloatInRange(-180.0f, 180.0f));
        Basic_data.alt(randFloatInRange(0.0f, 30.0f));
        Basic_data.utc_seconds(tStamp.tv_sec);
        std::cout << "Writing dds::sensing::gnss::Basic, count " << samples_written << std::endl;
        Basic_writer.write(Basic_data);

        // Modify the data to be written here
        MapData_data.seq_id(samples_written);
        MapData_data.timestamp().sec(static_cast<uint32_t>(tStamp.tv_sec));
        MapData_data.timestamp().nanosec(tStamp.tv_nsec);
        std::cout << "Writing dds::planning::MapData, count " << samples_written << std::endl;
        MapData_writer.write(MapData_data);
        samples_written++;

        std::cout << "dds::system::StatusTopic subscriber sleeping up to 1 sec..." << std::endl;

        // Run the handlers of the active conditions. Wait for up to 1 second.
        waitset.dispatch(dds::core::Duration(0, 200000000));
        // Send every 1 second
        rti::util::sleep(dds::core::Duration(0, 800000000));
    }
}

int main(int argc, char *argv[])
{
    // One optional argument: DDS domain ID (0-~240)
    unsigned int domain_id = 0;
    if(argc > 1) {
        domain_id = strtoul(argv[1], NULL, 10);
    }

    // Sets Connext verbosity to help debugging
    // rti::config::Logger::instance().verbosity(NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);

    try {
        run_participant_application(domain_id);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_participant_application(): " << ex.what()
        << std::endl;
        return EXIT_FAILURE;
    }

    // Releases the memory used by the participant factory.  Optional at
    // application exit
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
