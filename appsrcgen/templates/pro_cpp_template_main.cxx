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

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "{{Loop:Line:Topic:True:HeaderFileNameBase}}Support.h"
#include "ndds/ndds_cpp.h"
#include "ndds/ndds_namespace_cpp.h"

using namespace DDS;

static int shutdown_participant(
    DomainParticipant *participant,
    const char *shutdown_message,
    int status);

{{Loop:Start:Topic:DWListener:all}}
    // Listener that will be notified of DataWriter events
    class {{Repl:DataTypeName}}DataWriterListener : public DataWriterListener {
      public:
        // Notifications about data
        void on_offered_deadline_missed(
            DataReader * /*reader*/,
            const OfferedDeadlineMissedStatus& /*status*/)
        {
        }
        // Notifications about DataReaders
        void on_offered_incompatible_qos(
            DataReader * /*reader*/,
            const RequestedIncompatibleQosStatus& /*status*/)
        {
        }
        void on_publication_matched(
            DataReader * /*reader*/,
            const PublicationMatchedStatus& /*status*/)
        {
        }
        // Notification about DataWriter's liveliness
        void on_liveliness_lost(
            DataReader * /*reader*/,
            const LivelinessLostStatus& /*status*/)
        {
        }
    };
            
{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}
    // Listener that will be notified of DataReader events
    class {{Repl:DataTypeName}}DataReaderListener : public DataReaderListener {
      public:
        // Notifications about data
        void on_requested_deadline_missed(
            DataReader * /*reader*/,
            const RequestedDeadlineMissedStatus& /*status*/)
        {
        }
        void on_sample_rejected(
            DataReader * /*reader*/,
            const SampleRejectedStatus& /*status*/)
        {
        }
        void on_sample_lost(
            DataReader * /*reader*/,
            const SampleLostStatus& /*status*/)
        {
        }
        // Notifications about DataWriters
        void on_requested_incompatible_qos(
            DataReader * /*reader*/,
            const RequestedIncompatibleQosStatus& /*status*/)
        {
        }
        void on_liveliness_changed(
            DataReader * /*reader*/,
            const LivelinessChangedStatus& /*status*/)
        {
        }
        void on_subscription_matched(
            DataReader * /*reader*/,
            const SubscriptionMatchedStatus& /*status*/)
        {
        }
    };
            
{{Loop:End:Topic:DRListener:all}}
{{Loop:Start:Topic:DRWaitset:all}}
// Process data. Returns number of samples processed.
unsigned int {{Repl:DataTypeName}}_process_data({{Repl:DataTypePathAndName}}DataReader *{{Repl:DataTypeName}}_typed_reader)
{
    {{Repl:DataTypePathAndName}}%Seq data_seq;
    SampleInfoSeq info_seq;
    unsigned int samples_read = 0;
    ReturnCode_t retcode;

    // Take available data from DataReader's queue
    retcode = {{Repl:DataTypeName}}_typed_reader->take(
        data_seq,
        info_seq,
        LENGTH_UNLIMITED,
        ANY_SAMPLE_STATE,
        ANY_VIEW_STATE,
        ANY_INSTANCE_STATE);
    if (retcode == RETCODE_NO_DATA) {
        return samples_read;
    } else if (retcode != RETCODE_OK) {
        std::cerr << "take error " << retcode << std::endl;
        return samples_read;
    }

    // Iterate over all available data
    for (int i = 0; i < data_seq.length(); ++i) {
        // Check if a sample is an instance lifecycle event
        if (info_seq[i].valid_data) {
            // Print data
            std::cout << "Received data" << std::endl;
            {{Repl:DataTypePathAndName}}TypeSupport::print_data(&data_seq[i]);
            samples_read++;
        } else {
            std::cout << "Received instance state notification" << std::endl;
        }
    }
    // Data loaned from Connext for performance. Return loan when done.
    retcode = {{Repl:DataTypeName}}_typed_reader->return_loan(data_seq, info_seq);
    if (retcode != RETCODE_OK) {
        std::cerr << "return loan error " << retcode << std::endl;
    }

    return samples_read;
}
{{Loop:End:Topic:DRWaitset:all}}

int run_application(unsigned int domain_id)
{
    // Start communicating in a domain, usually one participant per application
    DomainParticipant *participant =
    TheParticipantFactory->create_participant_with_profile(
        domain_id,
        "exampleQoSLibrary",
        "exampleQoSProfile",
        NULL /* listener */,
        STATUS_MASK_NONE);
    if (participant == NULL) {
        return shutdown_participant(participant, "create_participant error", EXIT_FAILURE);
    }

{{Loop:Start:Topic:Pub:1}}
    // A Publisher allows an application to create one or more DataWriters
    Publisher *publisher = participant->create_publisher(
        PUBLISHER_QOS_DEFAULT,
        NULL /* listener */,
        STATUS_MASK_NONE);
    if (publisher == NULL) {
        return shutdown_participant(participant, "create_publisher error", EXIT_FAILURE);
    }

{{Loop:End:Topic:Pub:1}}
{{Loop:Start:Topic:Sub:1}}
    // A Subscriber allows an application to create one or more DataReaders
    Subscriber *subscriber = participant->create_subscriber(
        SUBSCRIBER_QOS_DEFAULT,
        NULL /* listener */,
        STATUS_MASK_NONE);
    if (subscriber == NULL) {
        return shutdown_participant(participant, "create_subscriber error", EXIT_FAILURE);
    }
    
{{Loop:End:Topic:Sub:1}}

    ReturnCode_t retcode;
{{Loop:Start:Topic:True:all}}
    // Register the datatype to use when creating the Topic
    const char *{{Repl:DataTypeName}}_type_name = {{Repl:DataTypePathAndName}}TypeSupport::get_type_name();
    retcode = {{Repl:DataTypePathAndName}}TypeSupport::register_type(participant, {{Repl:DataTypeName}}_type_name);
    if (retcode != RETCODE_OK) {
        return shutdown_participant(participant, "register_type error", EXIT_FAILURE);
    }

    // Create a Topic with a name and a datatype
    Topic *{{Repl:DataTopicName}}_topic = participant->create_topic(
        "{{Repl:DataTopicName}}",
        {{Repl:DataTypeName}}_type_name,
        TOPIC_QOS_DEFAULT,
        NULL /* listener */,
        STATUS_MASK_NONE);
    if ({{Repl:DataTopicName}}_topic == NULL) {
        return shutdown_participant(participant, "create_topic error", EXIT_FAILURE);
    }

{{Loop:End:Topic:True:all}}
{{Loop:Start:Topic:DWListener:all}}
    // Creating a writer listener, and enabling the DataWriter statuses we want
    // to be notified about
    // {{Repl:DataTypePathAndName}}DataWriterListener *{{Repl:DataTypeName}}_writer_listener = new {{Repl:DataTypePathAndName}}DataWriterListener;
    {{Repl:DataTypeName}}DataWriterListener *{{Repl:DataTypeName}}_writer_listener = new {{Repl:DataTypeName}}DataWriterListener;
    StatusMask {{Repl:DataTypeName}}_wrstatus_mask = OFFERED_DEADLINE_MISSED_STATUS
    | REQUESTED_INCOMPATIBLE_QOS_STATUS
    | PUBLICATION_MATCHED_STATUS
    | LIVELINESS_LOST_STATUS;

    // This DataWriter writes data on "Example_{{Repl:DataTypeName}}" Topic, and uses QoS
    // from USER_QOS_PROFILES.xml
    DataWriter *{{Repl:DataTypeName}}_untyped_writer = publisher->create_datawriter_with_profile(
        {{Repl:DataTopicName}}_topic,
        "exampleQoSLibrary",
        "exampleQoSProfile",
        {{Repl:DataTypeName}}_writer_listener,
        {{Repl:DataTypeName}}_wrstatus_mask);
    if ({{Repl:DataTypeName}}_untyped_writer == NULL) {
        return shutdown_participant(participant, "create_datawriter error", EXIT_FAILURE);
    }

    // Narrow casts from an untyped DataWriter to a writer of your type 
    {{Repl:DataTypePathAndName}}DataWriter *{{Repl:DataTypeName}}_typed_writer =
    {{Repl:DataTypePathAndName}}DataWriter::narrow({{Repl:DataTypeName}}_untyped_writer);
    if ({{Repl:DataTypeName}}_typed_writer == NULL) {
        return shutdown_participant(participant, "DataWriter narrow error", EXIT_FAILURE);
    }

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DWListener:all}}
    // Create data for writing
    {{Repl:DataTypePathAndName}} *{{Repl:DataTypeName}}_sample = {{Repl:DataTypePathAndName}}TypeSupport::create_data();
    if ({{Repl:DataTypeName}}_sample == NULL) {
        return shutdown_participant(
            participant,
            "{{Repl:DataTypePathAndName}}TypeSupport::create_data error",
            EXIT_FAILURE);
    }

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRListener:all}}
    // Create a data reader listener
    // {{Repl:DataTypePathAndName}}DataReaderListener *reader_listener = new {{Repl:DataTypePathAndName}}DataReaderListener();
    {{Repl:DataTypeName}}DataReaderListener *{{Repl:DataTypeName}}_reader_listener = new {{Repl:DataTypeName}}DataReaderListener();

    // Notify of all statuses in the listener except for new data, which we handle
    // in this thread with a WaitSet
    StatusMask {{Repl:DataTypeName}}_rdstatus_mask = STATUS_MASK_ALL & ~DATA_AVAILABLE_STATUS;

    // This DataReader reads data on "Example_{{Repl:DataTypeName}}" Topic and uses QoS
    // from USER_QOS_PROFILES.xml
    DataReader *{{Repl:DataTypeName}}_untyped_reader = subscriber->create_datareader_with_profile(
        {{Repl:DataTopicName}}_topic,
        "exampleQoSLibrary",
        "exampleQoSProfile",
        {{Repl:DataTypeName}}_reader_listener,
        {{Repl:DataTypeName}}_rdstatus_mask);
    if ({{Repl:DataTypeName}}_untyped_reader == NULL) {
        delete {{Repl:DataTypeName}}_reader_listener;
        return shutdown_participant(participant, "create_datareader error", EXIT_FAILURE);
    }

    // Narrow casts from a untyped DataReader to a reader of your type
    {{Repl:DataTypePathAndName}}DataReader *{{Repl:DataTypeName}}_typed_reader =
    {{Repl:DataTypePathAndName}}DataReader::narrow({{Repl:DataTypeName}}_untyped_reader);
    if ({{Repl:DataTypeName}}_typed_reader == NULL) {
        delete {{Repl:DataTypeName}}_reader_listener;
        return shutdown_participant(participant, "DataReader narrow error", EXIT_FAILURE);
    }

    // Create ReadCondition that triggers when unread data in reader's queue
    ReadCondition *{{Repl:DataTypeName}}_read_condition = {{Repl:DataTypeName}}_typed_reader->create_readcondition(
        ANY_SAMPLE_STATE,
        ANY_VIEW_STATE,
        ANY_INSTANCE_STATE);
    if ({{Repl:DataTypeName}}_read_condition == NULL) {
        delete {{Repl:DataTypeName}}_reader_listener;
        return shutdown_participant(participant, "create_readcondition error", EXIT_FAILURE);
    }

{{Loop:End:Topic:DRListener:all}}
{{Loop:Start:Topic:DRWaitset:all}}
    // WaitSet will be woken when the attached condition is triggered
    WaitSet waitset;
    retcode = waitset.attach_condition({{Repl:DataTypeName}}_read_condition);
    if (retcode != RETCODE_OK) {
        delete {{Repl:DataTypeName}}_reader_listener;
        return shutdown_participant(participant, "attach_condition error", EXIT_FAILURE);
    }

{{Loop:End:Topic:DRWaitset:all}}
    // Main loop
    unsigned int samples_sent = 0;
    while (1) {
{{Loop:Start:Topic:DWListener:all}}
        // Modify the to-be-published sample here
	
        std::cout << "Writing {{Repl:DataTypePathAndName}}, count " << samples_sent  << std::endl;
        samples_sent++;
        retcode = {{Repl:DataTypeName}}_typed_writer->write(*{{Repl:DataTypeName}}_sample, HANDLE_NIL);
        if (retcode != RETCODE_OK) {
            std::cerr << "write error " << retcode << std::endl;
        }

{{Loop:End:Topic:DWListener:all}}
{{Loop:Start:Topic:DRWaitset:all}}
        ConditionSeq active_conditions_seq;

        // Wait for data and report if it does not arrive in 1 second
        Duration_t wait_timeout = { 1, 0 };
        retcode = waitset.wait(active_conditions_seq, wait_timeout);

        if (retcode == RETCODE_OK) {
            // If the read condition is triggered, process data
            samples_read += {{Repl:DataTypeName}}_process_data({{Repl:DataTypeName}}_typed_reader); 
        } else {
            if (retcode == RETCODE_TIMEOUT) {
                std::cout << "No data after 1 second" << std::endl;
            }
        }

{{Loop:End:Topic:DRWaitset:all}}
{{Loop:Start:Topic:DWListener:1}}
        // Send every 1 second
        Duration_t send_period = { 1, 0 };
        NDDSUtility::sleep(send_period);
{{Loop:End:Topic:DWListener:1}}
    }

    // Cleanup
{{Loop:Start:Topic:DRListener:all}}
    delete {{Repl:DataTypeName}}_reader_listener;
{{Loop:End:Topic:DRListener:all}}
{{Loop:Start:Topic:DWListener:all}}
    retcode = {{Repl:DataTypePathAndName}}TypeSupport::delete_data({{Repl:DataTypeName}}_sample);
    if (retcode != RETCODE_OK) {
        std::cerr << "{{Repl:DataTypePathAndName}}TypeSupport::delete_data error " << retcode
        << std::endl;
    }
{{Loop:End:Topic:DWListener:all}}
    return shutdown_participant(participant, "Shutting down", EXIT_SUCCESS);
}

// Delete all entities
static int shutdown_participant(
    DomainParticipant *participant,
    const char *shutdown_message,
    int status)
{
    ReturnCode_t retcode;

    std::cout << shutdown_message << std::endl;

    if (participant != NULL) {
        // Cleanup everything created by this Participant
        retcode = participant->delete_contained_entities();
        if (retcode != RETCODE_OK) {
            std::cerr << "delete_contained_entities error" << retcode
            << std::endl;
            status = EXIT_FAILURE;
        }

        retcode = TheParticipantFactory->delete_participant(participant);
        if (retcode != RETCODE_OK) {
            std::cerr << "delete_participant error" << retcode << std::endl;
            status = EXIT_FAILURE;
        }
    }
    return status;
}

int main(int argc, char *argv[])
{
    // One optional argument: DDS domain ID (0-~240)
    unsigned int domain_id = 0;
    if(argc > 1) {
        domain_id = strtoul(argv[1], NULL, 10);
    }

    // Sets Connext verbosity to help debugging
    // NDDSConfigLogger::get_instance()->set_verbosity(NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);

    int status = run_application(domain_id);

    // Releases the memory used by the participant factory.
    // Optional at application exit
    ReturnCode_t retcode = DomainParticipantFactory::finalize_instance();
    if (retcode != RETCODE_OK) {
        std::cerr << "finalize_instance error" << retcode << std::endl;
        status = EXIT_FAILURE;
    }

    return status;
}
