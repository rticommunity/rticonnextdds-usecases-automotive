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
/* perception_main.c
* An application skeleton using the following DDS data types:
*   dds::sensing::Lidar
*   dds::sensing::Camera
*   dds::physics::Pose3D_real
*   dds::perception::Trajectory
*   dds::planning::MapData
*   dds::perception::ObjectsDetected
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
#include "res/types/data/rti/physics/Pose3D_tPlugin.hpp"
#include "res/types/data/rti/perception/Trajectory_tPlugin.hpp"
#include "res/types/data/rti/planning/Maps_tPlugin.hpp"
#include "res/types/data/rti/perception/Object_tPlugin.hpp"

// Listener that will be notified of DataWriter events
class ObjectsDetectedDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::perception::ObjectsDetected> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::perception::ObjectsDetected>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::perception::ObjectsDetected>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::perception::ObjectsDetected>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::perception::ObjectsDetected>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class LidarDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::sensing::Lidar> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::sensing::Lidar>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::sensing::Lidar>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::sensing::Lidar>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::sensing::Lidar>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::sensing::Lidar>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::sensing::Lidar>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class CameraDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::sensing::Camera> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::sensing::Camera>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::sensing::Camera>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::sensing::Camera>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::sensing::Camera>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::sensing::Camera>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::sensing::Camera>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class Pose3D_realDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::physics::Pose3D_real> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::physics::Pose3D_real>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::physics::Pose3D_real>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::physics::Pose3D_real>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::physics::Pose3D_real>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::physics::Pose3D_real>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::physics::Pose3D_real>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class TrajectoryDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::perception::Trajectory> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::perception::Trajectory>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::perception::Trajectory>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::perception::Trajectory>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::perception::Trajectory>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::perception::Trajectory>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::perception::Trajectory>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class MapDataDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::planning::MapData> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::planning::MapData>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::planning::MapData>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::planning::MapData>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::planning::MapData>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::planning::MapData>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::planning::MapData>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};

int Lidar_process_data(dds::sub::DataReader<dds::sensing::Lidar> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::sensing::Lidar> samples = reader.take();
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
int Camera_process_data(dds::sub::DataReader<dds::sensing::Camera> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::sensing::Camera> samples = reader.take();
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
int Pose3D_real_process_data(dds::sub::DataReader<dds::physics::Pose3D_real> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::physics::Pose3D_real> samples = reader.take();
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
int Trajectory_process_data(dds::sub::DataReader<dds::perception::Trajectory> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::perception::Trajectory> samples = reader.take();
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
int MapData_process_data(dds::sub::DataReader<dds::planning::MapData> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::planning::MapData> samples = reader.take();
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
    dds::topic::Topic<dds::physics::Pose3D_real> Pose3D_real_topic(participant, "egoPose");
    dds::topic::Topic<dds::perception::Trajectory> Trajectory_topic(participant, "egoMotion");
    dds::topic::Topic<dds::planning::MapData> MapData_topic(participant, "mapData");
    dds::topic::Topic<dds::perception::ObjectsDetected> ObjectsDetected_topic(participant, "detectedObjects");

    // Create a Publisher
    dds::pub::Publisher publisher(participant);

    // Create a Subscriber
    dds::sub::Subscriber subscriber(participant);

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask ObjectsDetected_status_mask;
    ObjectsDetected_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto ObjectsDetected_listener = std::make_shared<ObjectsDetectedDataWriterListener>();
    dds::pub::DataWriter<dds::perception::ObjectsDetected> ObjectsDetected_writer(
        publisher,
        ObjectsDetected_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            ObjectsDetected_listener,
            ObjectsDetected_status_mask);

    dds::perception::ObjectsDetected ObjectsDetected_data;

    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto Lidar_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Lidar_listener = std::make_shared<LidarDataReaderListener>();
    dds::sub::DataReader<dds::sensing::Lidar> Lidar_reader(
        subscriber,
        Lidar_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Lidar_listener,
            Lidar_status_mask);
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto Camera_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Camera_listener = std::make_shared<CameraDataReaderListener>();
    dds::sub::DataReader<dds::sensing::Camera> Camera_reader(
        subscriber,
        Camera_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Camera_listener,
            Camera_status_mask);
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto Pose3D_real_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Pose3D_real_listener = std::make_shared<Pose3D_realDataReaderListener>();
    dds::sub::DataReader<dds::physics::Pose3D_real> Pose3D_real_reader(
        subscriber,
        Pose3D_real_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Pose3D_real_listener,
            Pose3D_real_status_mask);
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto Trajectory_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Trajectory_listener = std::make_shared<TrajectoryDataReaderListener>();
    dds::sub::DataReader<dds::perception::Trajectory> Trajectory_reader(
        subscriber,
        Trajectory_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Trajectory_listener,
            Trajectory_status_mask);
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto MapData_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto MapData_listener = std::make_shared<MapDataDataReaderListener>();
    dds::sub::DataReader<dds::planning::MapData> MapData_reader(
        subscriber,
        MapData_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            MapData_listener,
            MapData_status_mask);

    dds::core::cond::WaitSet waitset;

    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int Lidar_samples_read = 0;
    dds::sub::cond::ReadCondition Lidar_read_condition(
        Lidar_reader,
        dds::sub::status::DataState::any(),
        [Lidar_reader, &Lidar_samples_read]() { Lidar_samples_read += Lidar_process_data(Lidar_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += Lidar_read_condition;
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int Camera_samples_read = 0;
    dds::sub::cond::ReadCondition Camera_read_condition(
        Camera_reader,
        dds::sub::status::DataState::any(),
        [Camera_reader, &Camera_samples_read]() { Camera_samples_read += Camera_process_data(Camera_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += Camera_read_condition;
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int Pose3D_real_samples_read = 0;
    dds::sub::cond::ReadCondition Pose3D_real_read_condition(
        Pose3D_real_reader,
        dds::sub::status::DataState::any(),
        [Pose3D_real_reader, &Pose3D_real_samples_read]() { Pose3D_real_samples_read += Pose3D_real_process_data(Pose3D_real_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += Pose3D_real_read_condition;
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int Trajectory_samples_read = 0;
    dds::sub::cond::ReadCondition Trajectory_read_condition(
        Trajectory_reader,
        dds::sub::status::DataState::any(),
        [Trajectory_reader, &Trajectory_samples_read]() { Trajectory_samples_read += Trajectory_process_data(Trajectory_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += Trajectory_read_condition;
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int MapData_samples_read = 0;
    dds::sub::cond::ReadCondition MapData_read_condition(
        MapData_reader,
        dds::sub::status::DataState::any(),
        [MapData_reader, &MapData_samples_read]() { MapData_samples_read += MapData_process_data(MapData_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += MapData_read_condition;
    int32_t samples_written = 0;

    // initialize the write data sample(s)
    ObjectsDetected_data.id().at(0) = 234;
    ObjectsDetected_data.id().at(1) = 0;
    ObjectsDetected_data.frame(dds::physics::FrameOfReferenceKind::FRAME_EGOCENTER);
    ObjectsDetected_data.objects().resize(1);
    ObjectsDetected_data.objects().at(0).path().resize(1);
    ObjectsDetected_data.objects().at(0).shape().outline().resize(4);
    ObjectsDetected_data.objects().at(0).shape().outline().at(0).x(0.0f);
    ObjectsDetected_data.objects().at(0).shape().outline().at(0).y(0.0f);
    ObjectsDetected_data.objects().at(0).shape().outline().at(1).x(1.0f);
    ObjectsDetected_data.objects().at(0).shape().outline().at(1).y(0.0f);
    ObjectsDetected_data.objects().at(0).shape().outline().at(2).x(1.0f);
    ObjectsDetected_data.objects().at(0).shape().outline().at(2).y(1.0f);
    ObjectsDetected_data.objects().at(0).shape().outline().at(3).x(0.0f);
    ObjectsDetected_data.objects().at(0).shape().outline().at(3).y(1.0f);


    while (1) {
        // Modify the data to be written here
        ObjectsDetected_data.objects().at(0).id().int32_v(samples_written);
        ObjectsDetected_data.objects().at(0).probability(randFloatInRange(0.12f, 0.73f));
        ObjectsDetected_data.objects().at(0).classification(dds::perception::ObjectKind::OBJECT_CAR);
        ObjectsDetected_data.objects().at(0).shape().height_max(randFloatInRange(1.01f, 1.03f));
        ObjectsDetected_data.objects().at(0).shape().height_min(randFloatInRange(0.97f, 0.99f));
        ObjectsDetected_data.objects().at(0).pose().orientation().x(randFloatInRange(0.0f, 6.28f));
        ObjectsDetected_data.objects().at(0).pose().orientation().y(randFloatInRange(0.0f, 6.28f));
        ObjectsDetected_data.objects().at(0).pose().orientation().z(randFloatInRange(0.0f, 6.28f));
        ObjectsDetected_data.objects().at(0).pose().orientation().w(randFloatInRange(0.0f, 0.123f));
        ObjectsDetected_data.objects().at(0).pose().position().x(randFloatInRange(-100.0f, 100.0f));
        ObjectsDetected_data.objects().at(0).pose().position().y(randFloatInRange(-100.0f, 100.0f));
        ObjectsDetected_data.objects().at(0).pose().position().z(randFloatInRange(0.10f, 0.80f));
        ObjectsDetected_data.objects().at(0).velocity().linear().x(randFloatInRange(40.0f, 60.0f));
        ObjectsDetected_data.objects().at(0).velocity().linear().y(randFloatInRange(1.0f, 6.0f));
        ObjectsDetected_data.objects().at(0).velocity().linear().z(randFloatInRange(0.10f, 0.5f));
        ObjectsDetected_data.objects().at(0).velocity().angular().x(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).velocity().angular().y(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).velocity().angular().z(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).acceleration().linear().x(randFloatInRange(1.0f, 6.0f));
        ObjectsDetected_data.objects().at(0).acceleration().linear().y(randFloatInRange(1.0f, 6.0f));
        ObjectsDetected_data.objects().at(0).acceleration().linear().z(randFloatInRange(0.10f, 0.5f));
        ObjectsDetected_data.objects().at(0).acceleration().angular().x(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).acceleration().angular().y(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).acceleration().angular().z(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).path().at(0).position().x(randFloatInRange(-100.0f, 100.0f));
        ObjectsDetected_data.objects().at(0).path().at(0).position().y(randFloatInRange(-100.0f, 100.0f));
        ObjectsDetected_data.objects().at(0).path().at(0).position().z(randFloatInRange(0.10f, 0.80f));
        ObjectsDetected_data.objects().at(0).path().at(0).velocity().linear().x(randFloatInRange(40.0f, 60.0f));
        ObjectsDetected_data.objects().at(0).path().at(0).velocity().linear().y(randFloatInRange(1.0f, 6.0f));
        ObjectsDetected_data.objects().at(0).path().at(0).velocity().linear().z(randFloatInRange(0.10f, 0.5f));
        ObjectsDetected_data.objects().at(0).path().at(0).velocity().angular().x(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).path().at(0).velocity().angular().y(randFloatInRange(0.10f, 0.20f));
        ObjectsDetected_data.objects().at(0).path().at(0).velocity().angular().z(randFloatInRange(0.10f, 0.20f));

        std::cout << "Writing dds::perception::ObjectsDetected, count " << samples_written << std::endl;
        ObjectsDetected_writer.write(ObjectsDetected_data);
        samples_written++;

        std::cout << "dds::sensing::Lidar subscriber sleeping up to 1 sec..." << std::endl;

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
