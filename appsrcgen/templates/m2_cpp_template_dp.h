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

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

/* Define USE_RELIABLE_QOS to use reliable
* reliability; otherwise, best-effort is used
*/

#define USE_RELIABLE_QOS

class Application
{
  public:
    DDSDomainParticipant *participant; 
    DDSTopic *topic; 
    DDS_Long sleep_time;
    DDS_Long count;

    static void help(char *appname);

    DDS_ReturnCode_t initialize(
        DDS_Long domain_id, 
        char *udp_intf, 
        char *peer);

    Application();
    ~Application();
};

#endif

