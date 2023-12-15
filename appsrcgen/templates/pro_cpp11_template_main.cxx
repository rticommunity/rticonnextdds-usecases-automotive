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
* as a starting point example: modified by the user
*/

#include <algorithm>
#include <iostream>
{{Loop:Start:Topic:Pub:1}}
#include <dds/pub/ddspub.hpp>
{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:Sub:1}}
#include <dds/sub/ddssub.hpp>
{{Loop:End:Topic:Sub:1}}
#include <dds/core/ddscore.hpp>
{{Loop:Start:Topic:Pub:1}}
#include <rti/util/util.hpp>      // for sleep()
{{Loop:End:Topic:Pub:1}}
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

#include "{{Loop:Line:Topic:True:HeaderFileNameBase}}Plugin.hpp"

{{Loop:Start:Topic:DWListener:all}}
// Listener that will be notified of DataWriter events
class {{Repl:DataTypeName}}DataWriterListener : public dds::pub::NoOpDataWriterListener<{{Repl:DataTypePathAndName}}> {
  public:
    // Notifications about data
    void on_offered_deadline_missed(
        dds::pub::DataWriter<{{Repl:DataTypePathAndName}}>& writer,
        const dds::core::status::OfferedDeadlineMissedStatus& status)
        override
    {
    }
    // Notifications about DataReaders
    void on_offered_incompatible_qos(
        dds::pub::DataWriter<{{Repl:DataTypePathAndName}}>& writer,
        const dds::core::status::OfferedIncompatibleQosStatus& status)
        override
    {
    }
    void on_publication_matched(
        dds::pub::DataWriter<{{Repl:DataTypePathAndName}}>& writer,
        const ::dds::core::status::PublicationMatchedStatus& status)
        override
    {
    }
    // Notification about DataWriter's liveliness
    void on_liveliness_lost(
        dds::pub::DataWriter<{{Repl:DataTypePathAndName}}>& writer,
        const dds::core::status::LivelinessLostStatus& status) override
    {
    }
};
{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}
// Listener that will be notified of DataReader events
class {{Repl:DataTypeName}}DataReaderListener : public dds::sub::NoOpDataReaderListener<{{Repl:DataTypePathAndName}}> {
  public:
    // Notifications about data
    void on_requested_deadline_missed(
        dds::sub::DataReader<{{Repl:DataTypePathAndName}}>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
        override 
    {
    }
    void on_sample_rejected(
        dds::sub::DataReader<{{Repl:DataTypePathAndName}}>& reader,
        const dds::core::status::SampleRejectedStatus& status) override
    {
    }
    void on_sample_lost(
        dds::sub::DataReader<{{Repl:DataTypePathAndName}}>& reader,
        const dds::core::status::SampleLostStatus& status) override
    {
    } 
    // Notifications about DataWriters
    void on_requested_incompatible_qos(
        dds::sub::DataReader<{{Repl:DataTypePathAndName}}>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
        override
    {
    }
    void on_subscription_matched(
        dds::sub::DataReader<{{Repl:DataTypePathAndName}}>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status) override
    {
    }
    void on_liveliness_changed(
        dds::sub::DataReader<{{Repl:DataTypePathAndName}}>& reader,
        const dds::core::status::LivelinessChangedStatus& status) override
    {
    }
};
{{Loop:End:Topic:DRListener:all}}

{{Loop:Start:Topic:DRListener:all}}
int {{Repl:DataTypeName}}_process_data(dds::sub::DataReader<{{Repl:DataTypePathAndName}}> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<{{Repl:DataTypePathAndName}}> samples = reader.take();
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
{{Loop:End:Topic:DRListener:all}}

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
{{Loop:Start:Topic:True:all}}
    dds::topic::Topic<{{Repl:DataTypePathAndName}}> {{Repl:DataTypeName}}_topic(participant, "{{Repl:DataTopicName}}");
{{Loop:End:Topic:True:all}}

{{Loop:Start:Topic:Pub:1}}
    // Create a Publisher
    dds::pub::Publisher publisher(participant);

{{Loop:End:Topic:Pub:1}}    
{{Loop:Start:Topic:Sub:1}}
    // Create a Subscriber
    dds::sub::Subscriber subscriber(participant);

{{Loop:End:Topic:Sub:1}}
{{Loop:Start:Topic:DWListener:all}}
    // Enable the DataWriter statuses we want to be notified about 
    dds::core::status::StatusMask {{Repl:DataTypeName}}_status_mask;
    {{Repl:DataTypeName}}_status_mask |= dds::core::status::StatusMask::offered_deadline_missed()
    | dds::core::status::StatusMask::offered_incompatible_qos()
    | dds::core::status::StatusMask::publication_matched()
    | dds::core::status::StatusMask::liveliness_lost();

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto {{Repl:DataTypeName}}_listener = std::make_shared<{{Repl:DataTypeName}}DataWriterListener>();
    dds::pub::DataWriter<{{Repl:DataTypePathAndName}}> {{Repl:DataTypeName}}_writer(
        publisher,
        {{Repl:DataTypeName}}_topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            {{Repl:DataTypeName}}_listener,
            {{Repl:DataTypeName}}_status_mask);

    {{Repl:DataTypePathAndName}} {{Repl:DataTypeName}}_data;

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}
    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet.
    auto {{Repl:DataTypeName}}_status_mask = dds::core::status::StatusMask::all()
    & ~dds::core::status::StatusMask::data_available();

    // Create a DataReader, loading QoS profile from USER_QOS_PROFILES.xml, and
    // using a listener for events.
    auto {{Repl:DataTypeName}}_listener = std::make_shared<{{Repl:DataTypeName}}DataReaderListener>();
    dds::sub::DataReader<{{Repl:DataTypePathAndName}}> {{Repl:DataTypeName}}_reader(
        subscriber,
        {{Repl:DataTypeName}}_topic,
        dds::core::QosProvider::Default().datareader_qos(
            "exampleQoSLibrary::exampleQoSProfile"),
            {{Repl:DataTypeName}}_listener,
            {{Repl:DataTypeName}}_status_mask);
{{Loop:End:Topic:DRListener:all}}

{{Loop:Start:Topic:DRListener:1}}
    dds::core::cond::WaitSet waitset;
{{Loop:End:Topic:DRListener:1}}

{{Loop:Start:Topic:DRListener:all}}
    // Create a ReadCondition for any data received on this reader and set a
    // handler to process the data
    unsigned int {{Repl:DataTypeName}}_samples_read = 0;
    dds::sub::cond::ReadCondition {{Repl:DataTypeName}}_read_condition(
        {{Repl:DataTypeName}}_reader,
        dds::sub::status::DataState::any(),
        [{{Repl:DataTypeName}}_reader, &{{Repl:DataTypeName}}_samples_read]() { {{Repl:DataTypeName}}_samples_read += {{Repl:DataTypeName}}_process_data({{Repl:DataTypeName}}_reader); });

    // WaitSet will be woken when the attached condition is triggered
    waitset += {{Repl:DataTypeName}}_read_condition;
{{Loop:End:Topic:DRListener:all}}
    int32_t samples_written = 0;

    while (1) {
{{Loop:Start:Topic:Pub:all}}
        // Modify the data to be written here

        std::cout << "Writing {{Repl:DataTypePathAndName}}, count " << samples_written << std::endl;
        {{Repl:DataTypeName}}_writer.write({{Repl:DataTypeName}}_data);
        
{{Loop:End:Topic:Pub:all}}
{{Loop:Start:Topic:DRListener:1}}
        std::cout << "{{Repl:DataTypePathAndName}} subscriber sleeping up to 1 sec..." << std::endl;

        // Run the handlers of the active conditions. Wait for up to 1 second.
        waitset.dispatch(dds::core::Duration(1));
{{Loop:End:Topic:DRListener:1}}
{{Loop:Start:Topic:Pub:1}}
        // Send every 1 second
        rti::util::sleep(dds::core::Duration(1));
{{Loop:End:Topic:Pub:1}}
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
