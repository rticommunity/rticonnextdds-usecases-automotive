# Tutorial: Create new Datatypes and System Designs

This tutorial covers the steps needed to add new data types to the `datatypes`
library build, and to create custom system description files for use with the
`appsrcgen` system generator.

A `Hello, World!` pub-sub example will be the subject, to be built for 
Connext Pro and Connext Micro 2 C/CERT.   Note that the datatype and system
description files already exist in the example; this tutorial was created
to document the steps taken when making this example.


## Creating new Data Types
For this 'Hello, World' example system, we'll create a data type with a single
`string` member to carry the text message. While we could do this completely 
within a single new file, let's include one of the primitive data types already
in the database library, defined in the file `datatypes/res/types/data/rti/base/Promitives_t.idl`:

```cpp
        const Int32 MAXLEN32    = 32;
        // snip
        typedef string<MAXLEN32>  String32;
```

We will also put our custom data types into a separate location for clarity.  
Create a directory for the new data type, with starter files for the IDL and
for CMake-assisted conversion of this type to XML:

```bash
    mkdir -p datatypes/res/types/data/my_types/hello
    touch datatypes/res/types/data/my_types/hello/txtmsg.idl
    cp datatypes/res/types/data/rti/demo/CMakeLists.txt datatypes/res/types/data/my_types/hello/CMakeLists.txt
```

**Edit and save the IDL file to contain the following:**  

```cpp
#ifndef __TXTMSG_IDL__
#define __TXTMSG_IDL__

#include "res/types/data/rti/base/Primitives_t.idl"

module basictypes {
    struct charMessage {
        dds::base::String32 message;
    };
};

#endif /* __TXTMSG_IDL__ */
```
We now have a new IDL file with a single data type definition: `charMessage`

**Edit the new CMakeLists.txt file:**  

```cmake
#******************************************************************************
#  (c) 2020 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
#
#   Licensed according to the terms in the LICENSE.md file located at the root 
#   of this software repository:
#
#                                LICENSE.md
#
#*****************************************************************************

cmake_minimum_required(VERSION 3.14)

###################################################################################
# Convert IDLs to XML
###################################################################################

set(IDLs txtmsg)
set(xml_rti_automotive)

foreach(IDL ${IDLs})

  connextdds_rtiddsgen_convert(
    INPUT
      "${CMAKE_CURRENT_SOURCE_DIR}/${IDL}.idl"
    FROM
      "IDL"
    TO
      "XML"
    OUTPUT_DIRECTORY
      "${CMAKE_CURRENT_SOURCE_DIR}"
    INCLUDE_DIRS
      "${CMAKE_CURRENT_SOURCE_DIR}/../../../../.." # res/types
  )

  list(APPEND xml_rti_automotive "${CMAKE_CURRENT_SOURCE_DIR}/${IDL}.xml")

endforeach()

add_custom_target(my_types ALL DEPENDS
  ${xml_rti_automotive}
)
```
This file is used to automatically create an XML equivalent of the IDL file.
Included here for completeness.

**Add the new type to the datatypes library build**  
Use a text editor to open and edit the following files:  

`datatypes/res/types/CMakeLists.txt`: add the new IDL file to one of the enabled
lists.  Here it is added to the `IDL_RTI_AUTOMOTIVE` group of types:

```cmake
  data/rti/gateway/CAN_t.idl
  data/rti/system/InfoTopic_t.idl
  data/rti/system/StatusTopic_t.idl
  data/my_types/hello/txtmsg.idl     # added to list here
)

set(IDL_COVESA_VSS
```
This adds the new IDL file to the library build.

`datatypes/res/types/data/CMakeLists.txt`: add the new directory:

```cmake
  add_subdirectory("rti/sensing")
  add_subdirectory("rti/system")
  add_subdirectory("my_types/hello")    # added to list here
endif()
```
This adds the call to the new CMakeLists.txt file, to ensure an XML equivalent
of the IDL file is created.

**Rebuild the datatypes library**  

Follow the directions in the file `datatypes/README.md` to build the datatype library.  
When the build completes, your new type should be available in the new library.


## Create a Hello World system design file

This will use the Python3 generator application in the `appscrgen` directory
to create the source code and build files for our 'Hello, World' system, using 
the following steps:

**Create the JSON system description file**  

Create a file at `appsrcgen/examples/hello_pro.json` and insert the following:

```js
{
  "dest-path": "../hello_pro",
  "app-list": [
    {
      "appname": "helloProPub",
      "connext": "pro",
      "language": "C++11",
      "topics": [
        {
          "topicname": "HelloTopic",
          "typename": "charMessage",
          "typepath": "basictypes::",
          "typefile": "res/types/data/my_types/hello/txtmsg",
          "pubsub": "pub",
          "code": "DWListener"
        }
      ]
    },
    {
      "appname": "helloProSub",
      "connext": "pro",
      "language": "C++11",
      "topics": [
        {
          "topicname": "HelloTopic",
          "typename": "charMessage",
          "typepath": "basictypes::",
          "typefile": "res/types/data/my_types/hello/txtmsg",
          "pubsub": "sub",
          "code": "DRListener"
        }
      ]
    }
  ]
}
```
This file describes a system of 2 applications (pub and sub) written to use RTI Connext DDS Pro
and the `C++11` programming language.   It creates a single topic (`HelloTopic`) for communications
using the new type (`charMessage`) that we'd created in the section above.

The keywords in the file control the following:
- `dest-path` = directory to write the resulting generated files (unless overridden with command line arg[2])
- `app-list` = list of applications to generate.
    - `appname` = name of the appication
    - `connext` = which Connext to use (pro or micro2)
    - `language` = programming language for the application:
        - micro2: (C, C-cert, C++)
        - pro: (C, C++, C++11)
    - `topics` = list of DDS data topics and types to use in the application
        - `topicname` = the name of the DDS topic
        - `typename` = the name of the data type (minus any nested module path names)
        - `typepath` = the nested module path portion of the data type name, separated by "::"
        - `typefile` = the relative location of the typesupport file in the `datatypes` library build.
        - `pubsub` = create a publisher, or a subscriber for this topic.
        - `code` = implementation form of the DDS support code.  At the moment, this only includes Listeners for datawriters or datareaders (DWListener, DRListener).

To create applications for different programming languages or other variants of Connext,
simply edit the `"connext"` and `"language"` portions of the above.  An example of this
targeting Connext Micro 2 and the `C` programming language can be found
in the file `appsrcgen/examples/hello_micro2.json`.

**NOTE**: mixing different connext types (pro, micro) and languages (C, C++, C++11) within a single system
description file is not supported at this time.   Intermixed systems can be created by using multiple system
description files (1 file per connext/language combination).

Take this opportunity to review the other files in this `examples` directory; note that large,
multi-app systems can be created with ease.

With this new `hello_pro.json` file saved, let's use it to create our 'Hello, World' system.  
Open a terminal in the `appsrcgen` directory and enter the following:

```bash
  python3 appgen.py examples/hello_pro.json
```

This will generate the following files in `../hello_pro/`:
```
CMakeLists.txt                        = CMake file for system
src/helloProPub/helloProPub_main.cxx  = source for pub app
src/helloProPub/CMakeLists.txt        =  CMake for pub app
src/helloProSub/helloProSub_main.cxx  = source for sub app
src/helloProSub/CMakeLists.txt        =  CMake for sub app
systemDataTypes.xml                   = System data types in XML format
run-demo.sh                           = Launch script for system
USER_QOS_PROFILES.xml                 = Quality of Service settings for system
```

**Edit the generated source**  
Although the source is ready-to-build, by default it will publish 'empty' samples, 
so we'll modify the source to publish our 'Hello World' message.  
Open the `hello_pro/src/helloProPub/helloProPub_main.cxx` file in a text editor and 
make the following modifications (starting at approximately line 109):
```cpp
    int32_t samples_written = 0;
    std::string messageText;        // <-- add this variable

    while (1) {
        // Modify the data to be written here
        messageText = "Hello, World! " + std::to_string(samples_written);   // <-- add this line
        charMessage_data.message(messageText);                              // <-- add this line

        std::cout << "Writing basictypes::charMessage, count " << samples_written << std::endl;
        charMessage_writer.write(charMessage_data);
        samples_written++;                                                  // <-- add this line

        // Send every 1 second
```
Save this file, then let's build the system.

**Build the System Applications**  
Open a terminal in the `hello_pro` directory, initialize the environment for Connext, and 
build the applications using the following commands (note:paths may need to be adjusted 
to match your system):

```bash
  source ~/rti_connext_dds-6.1.1/resource/scripts/rtisetenv_x64Linux4gcc7.3.0.bash
  mkdir build
  cd build
  cmake -DCMAKE_BUILD_TYPE=Release ..
  make
```

When the build finishes, you should be ready to run your 'Hello World' system.
Open a terminal in `hello_pro` and run the launch script to start the applications:

```bash
  chmod +x run-demo.sh
  ./run-demo.sh
```

You should see the script open 2 additional tabs on your terminal window (one each for 
pub and sub), with messages appearing to show the system is communicating, such as:
```bash
basictypes::charMessage subscriber sleeping up to 1 sec...
basictypes::charMessage subscriber sleeping up to 1 sec...
[message: Hello, World! 1]
basictypes::charMessage subscriber sleeping up to 1 sec...
[message: Hello, World! 2]
basictypes::charMessage subscriber sleeping up to 1 sec...
[message: Hello, World! 3]
basictypes::charMessage subscriber sleeping up to 1 sec...
basictypes::charMessage subscriber sleeping up to 1 sec...
[message: Hello, World! 4]
```

Press ctrl-c in each window to close and quit each application.
If your host system does not support this method of launching, then the applications
can be launched individually from a terminal (from the same location as the `USER_QOS_PROFILES.xml` file).

## NEXT STEPS

This tutorial has shown how to create custom data types and how to use the variety of types 
in the `datatypes` library to describe and generate complete systems of skeletal applications.

These applications form working systems that have operational DDS communications, 
enabling you to get right to the application logic; the DDS part is already working!
