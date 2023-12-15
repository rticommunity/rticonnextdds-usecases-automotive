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
/* {{Repl:AppName}}_dp.h
* Helper file: create and configure the domain participant
*/
#ifndef __{{Repl:AppName}}_dp_h__
#define __{{Repl:AppName}}_dp_h__

#include "rti_me_c.h"

/*e \dref_Example_Config_UseReliableQos
* Define USE_RELIABLE_QOS to use reliable
* reliability on the DataReader; otherwise, use
* best-effort reliability by default.
*/

#define USE_RELIABLE_QOS

/*e \dref_Example_Config_UseSampleFilter
* Define USE_SAMPLE_FILTER to filter samples
* using call-backs on the DataReader's listener
* and, in case the first field of your type is not
* a DDS_Long called "id", modify the following for your datatype:
* "<datatype>_Subscriber_filter_sample",
* "<datatype>_Subscriber_on_before_sample_deserialize",
* "<datatype>_Subscriber_deserialize_unsigned_long", and
* "<datatype>_Subscriber_filter_sample" functions to
* correctly filter by the field you want to use for filtering.
*/

/*#define USE_SAMPLE_FILTER*/

/*e \dref_Example_Config_FilterOnDeserialize
* Define FILTER_ON_DESERIALIZE to enable
* filtering on call-back on_before_sample_deserialize;
* otherwise use call-back on_before_sample_commit
* by default. */

/*#define FILTER_ON_DESERIALIZE*/

struct Application
{
    DDS_DomainParticipant *participant;
    char topic_name[255];
    char type_name[255];
    DDS_Long sleep_time;
    DDS_Long count;
};

extern void 
Application_help(char *appname);

extern struct Application*
Application_create(
    const char *local_participant_name,
    DDS_Long domain_id,
    char *udp_intf,
    char *peer);

#ifndef RTI_CERT
extern void
Application_delete(struct Application *application);

#endif
#endif  /* __{{Repl:AppName}}_dp_h__ */
