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

#include "res/types/data/rti/perception/Object_tPlugin.hpp"
#include "res/types/data/rti/sensing/Gnss_tPlugin.hpp"
#include "res/types/data/rti/sensing/Imu_tPlugin.hpp"
#include "res/types/data/rti/sensing/Compass_tPlugin.hpp"
#include "res/types/data/rti/perception/Trajectory_tPlugin.hpp"

// Listener that will be notified of DataWriter events
class TrajectoryDataWriterListener : public dds::pub::NoOpDataWriterListener<dds::perception::Trajectory> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<dds::perception::Trajectory>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<dds::perception::Trajectory>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<dds::perception::Trajectory>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<dds::perception::Trajectory>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class ObjectsDetectedDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::perception::ObjectsDetected> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::perception::ObjectsDetected>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::perception::ObjectsDetected>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::perception::ObjectsDetected>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::perception::ObjectsDetected>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::perception::ObjectsDetected>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::perception::ObjectsDetected>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class BasicDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::sensing::gnss::Basic> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::sensing::gnss::Basic>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::sensing::gnss::Basic>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::sensing::gnss::Basic>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::sensing::gnss::Basic>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::sensing::gnss::Basic>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::sensing::gnss::Basic>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class Imu_realDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::sensing::imu::Imu_real> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::sensing::imu::Imu_real>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::sensing::imu::Imu_real>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::sensing::imu::Imu_real>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::sensing::imu::Imu_real>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::sensing::imu::Imu_real>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::sensing::imu::Imu_real>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
// Listener that will be notified of DataReader events
class CompassDataReaderListener : public dds::sub::NoOpDataReaderListener<dds::sensing::Compass> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<dds::sensing::Compass>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<dds::sensing::Compass>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<dds::sensing::Compass>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    }
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<dds::sensing::Compass>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<dds::sensing::Compass>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<dds::sensing::Compass>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};

int ObjectsDetected_process_data(dds::sub::DataReader<dds::perception::ObjectsDetected> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::perception::ObjectsDetected> samples = reader.take();
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
int Basic_process_data(dds::sub::DataReader<dds::sensing::gnss::Basic> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::sensing::gnss::Basic> samples = reader.take();
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
int Imu_real_process_data(dds::sub::DataReader<dds::sensing::imu::Imu_real> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::sensing::imu::Imu_real> samples = reader.take();
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
int Compass_process_data(dds::sub::DataReader<dds::sensing::Compass> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<dds::sensing::Compass> samples = reader.take();
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
void tstamp_diff(timespec *tElapsed, timespec *tStart)
{
    timespec tNow;
    tstamp_get(&tNow);
    tElapsed->tv_sec = tNow.tv_sec - tStart->tv_sec;
    tElapsed->tv_nsec = tNow.tv_nsec - tStart->tv_nsec;
    if(tElapsed->tv_nsec < 0) {
        tElapsed->tv_sec++;
        tElapsed->tv_nsec += 1000000000;
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
    dds::topic::Topic<dds::perception::ObjectsDetected> ObjectsDetected_topic(participant, "detectedObjects");
    dds::topic::Topic<dds::sensing::gnss::Basic> Basic_topic(participant, "gnssPosition");
    dds::topic::Topic<dds::sensing::imu::Imu_real> Imu_real_topic(participant, "imuData");
    dds::topic::Topic<dds::sensing::Compass> Compass_topic(participant, "compass");
    dds::topic::Topic<dds::perception::Trajectory> Trajectory_topic(participant, "egoMotion");

    // Create a Publisher
    dds::pub::Publisher publisher(participant);

    // Create a Subscriber
    dds::sub::Subscriber subscriber(participant);

    // Enable the DataWriter statuses we want to be notified about
    dds::core::status::StatusMask Trajectory_status_mask;
    Trajectory_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Trajectory_listener = std::make_shared<TrajectoryDataWriterListener>();
    dds::pub::DataWriter<dds::perception::Trajectory> Trajectory_writer(
        publisher,
        Trajectory_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Trajectory_listener,
            Trajectory_status_mask);

    dds::perception::Trajectory Trajectory_data;

    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto ObjectsDetected_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto ObjectsDetected_listener = std::make_shared<ObjectsDetectedDataReaderListener>();
    dds::sub::DataReader<dds::perception::ObjectsDetected> ObjectsDetected_reader(
        subscriber,
        ObjectsDetected_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            ObjectsDetected_listener,
            ObjectsDetected_status_mask);
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto Basic_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Basic_listener = std::make_shared<BasicDataReaderListener>();
    dds::sub::DataReader<dds::sensing::gnss::Basic> Basic_reader(
        subscriber,
        Basic_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Basic_listener,
            Basic_status_mask);
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto Imu_real_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Imu_real_listener = std::make_shared<Imu_realDataReaderListener>();
    dds::sub::DataReader<dds::sensing::imu::Imu_real> Imu_real_reader(
        subscriber,
        Imu_real_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Imu_real_listener,
            Imu_real_status_mask);
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto Compass_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto Compass_listener = std::make_shared<CompassDataReaderListener>();
    dds::sub::DataReader<dds::sensing::Compass> Compass_reader(
        subscriber,
        Compass_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            Compass_listener,
            Compass_status_mask);

    dds::core::cond::WaitSet waitset;

    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int ObjectsDetected_samples_read = 0;
    dds::sub::cond::ReadCondition ObjectsDetected_read_condition(
        ObjectsDetected_reader,
        dds::sub::status::DataState::any(),
        [ObjectsDetected_reader, &ObjectsDetected_samples_read]() { ObjectsDetected_samples_read += ObjectsDetected_process_data(ObjectsDetected_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += ObjectsDetected_read_condition;
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int Basic_samples_read = 0;
    dds::sub::cond::ReadCondition Basic_read_condition(
        Basic_reader,
        dds::sub::status::DataState::any(),
        [Basic_reader, &Basic_samples_read]() { Basic_samples_read += Basic_process_data(Basic_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += Basic_read_condition;
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int Imu_real_samples_read = 0;
    dds::sub::cond::ReadCondition Imu_real_read_condition(
        Imu_real_reader,
        dds::sub::status::DataState::any(),
        [Imu_real_reader, &Imu_real_samples_read]() { Imu_real_samples_read += Imu_real_process_data(Imu_real_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += Imu_real_read_condition;
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int Compass_samples_read = 0;
    dds::sub::cond::ReadCondition Compass_read_condition(
        Compass_reader,
        dds::sub::status::DataState::any(),
        [Compass_reader, &Compass_samples_read]() { Compass_samples_read += Compass_process_data(Compass_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += Compass_read_condition;
    int32_t samples_written = 0;
    timespec tStart, tElapsed;
    tstamp_get(&tStart);

    // initialize the write data sample(s)
    Trajectory_data.id().at(0) = 123;
    Trajectory_data.id().at(1) = 0;
    Trajectory_data.points().resize(1);

    while (1) {
        // Modify the per-sample data to be written here
        Trajectory_data.points().at(0).acceleration().x(randFloatInRange(-0.333f, 0.333f));
        Trajectory_data.points().at(0).acceleration().y(randFloatInRange(-0.022f, 0.022f));
        Trajectory_data.points().at(0).velocity().x(randFloatInRange( 0.0f, 67.0f));
        Trajectory_data.points().at(0).velocity().y(randFloatInRange(-0.022f, 0.022f));
        Trajectory_data.points().at(0).pose().orientation().x(randFloatInRange(0.0f, 6.28f));
        Trajectory_data.points().at(0).pose().orientation().y(randFloatInRange(0.0f, 6.28f));
        Trajectory_data.points().at(0).pose().orientation().z(randFloatInRange(0.0f, 6.28f));
        Trajectory_data.points().at(0).pose().orientation().w(randFloatInRange(0.0f, 0.123f));
        Trajectory_data.points().at(0).pose().position().x(randFloatInRange(-100.0f, 100.0f));
        Trajectory_data.points().at(0).pose().position().y(randFloatInRange(-100.0f, 100.0f));
        Trajectory_data.points().at(0).pose().position().z(randFloatInRange(0.10f, 0.80f));
        Trajectory_data.points().at(0).heading_rate(randFloatInRange(-2.222f, 2.222f));
        Trajectory_data.points().at(0).wheel_angle().at(0) = randFloatInRange(-0.011f, 0.011f);
        Trajectory_data.points().at(0).wheel_angle().at(1) = randFloatInRange(-0.011f, 0.011f);
        tstamp_diff(&tElapsed, &tStart);
        Trajectory_data.points().at(0).time_since_start().sec(static_cast<uint32_t>(tElapsed.tv_sec));
        Trajectory_data.points().at(0).time_since_start().nanosec(tElapsed.tv_nsec);


        std::cout << "Writing dds::perception::Trajectory, count " << samples_written << std::endl;
        Trajectory_writer.write(Trajectory_data);
        samples_written++;

        std::cout << "dds::perception::ObjectsDetected subscriber sleeping up to 1 sec..." << std::endl;

        // Run the handlers of the active conditions. Wait for up to 200 millisecond.
        waitset.dispatch(dds::core::Duration(0, 200000000));
        // Send every 800 milliseconds
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
