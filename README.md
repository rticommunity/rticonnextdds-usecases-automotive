# Connext Drive Automotive Examples
Automotive examples using RTI Connext Drive.

This is a growing set of automotive architectural examples using RTI Connext Drive DDS APIs: Professional, Micro or Cert.
both are included in [Connext Drive 2.0](https://www.rti.com/drive) or available separately ( 
[Connext Pro](https://www.rti.com/products/connext-dds-professional) or 
[Connext Micro Cert](https://www.rti.com/products/connext-dds-cert)).  
Connext Drive / Micro Cert is [TUV SUD-certified to ASIL-D](https://www.rti.com/hubfs/_Products/Connext%20Drive/TUV_SUD_2022_26262_Certificate-Full.png) 
to meet the safety lifecycle requirements set forth by ISO 26262.

These examples create a working system architecture of independent applications, 
interconnected using high-performance data topics with Connext DDS (Pro or Cert).
The applications themselves are skeletal and do not contain any application logic
other than publishing topic data once per second, and printing a status message
when topic data is received.

Example systems of pre-written applications are provided, and the user is free to design
and create their own multi-application system using the included system code generator.

This example is divided into 3 sections which are to be built in the following order:

 1. `datatypes`: Data type definitions used in the examples, buildable as a type support library.  This uses the RTI code generator to convert IDL data type definition files into source code to support each data type.  Build support is included for Connext Pro and Micro, in Debug and Release configurations, 
 and for C++11, C++, C, and C-Cert language options.
 2. `appsrcgen`: Whole-system application source code generation.  This creates the source and build files for an entire system of multiple Connext applications, as directed by a system description file.  **NOTE** that this step can be skipped if building the pre-generated systems in the `./examples` folders.
 3. `<generated system>`: The buildable examples resulting from step 2 above, ready-to-build using CMake, and ready to be customized with your application logic.  **NOTE** that if building the pre-generated example systems, these will be in either the `./examples/pro_cpp11` (for Connext Pro, C++11, Release build), or the `./examples/micro_cert` (for Connext Micro Cert, C, Release build).
 
README files with detailed instructions can be found in the `datatypes` and `appsrcgen` directories.

## Example Overview

### Connext Pro, Connext Micro 2, or both?

This example supports creating multi-app systems using Connext Pro or Connext Micro 2:

- Connext Pro is a full-featured DDS implementation.  This example supports C, C++, or C++11 languages.
- Connext Micro 2 is a reduced footprint / safety-certifiable DDS.  This example supports C-cert, C, or C++ languages.

Note that the type support libraries in the `datatypes` directory *must be built first* to support Pro and/or 
Micro 2, in `Debug` and/or `Release` build configurations.

### Build the Data Type Support Libraries

See the `datatypes/README.md` file for detailed instructions.  
This results in datatype support libraries for selected data types from RTI, COVESA, ROS and more.

### Generate the Source Code and Build Files for a Complete System.

See the `appsrcgen/README.md` file for detailed instructions.  
This is a python3 utility that generates the buildable source code and build files for the multi-app system
selected from the `appsrcgen/examples` directory, or created by the user for a custom solution.

As an example, the file `appsrcgen/examples/ces2023demo.json` will create an 8-application system that interfaces
with the [CARLA autonomous vehicle simulator](http://carla.org/) and reports status of key vehicle signals using 
[COVESA](https://www.covesa.global/) VSS data types.   This system was demonstrated by RTI at CES 2023.

Other examples will create different system configurations, from other Next-Gen E/E configurations down to
simple 'Hello, World' pub/sub systems.   With the large collection of data types, the user is encouraged
to explore and create systems that exactly match their needs -- in minutes, without a steep learning curve.

### Build and Customize the System

The generated system source and cmake files will be in a ready-to-build configuration, resulting in a 
system of applications communicating on the DDS framework, and ready for you to add your own application logic.


## Quick Start Instructions

After cloning this repo:

**Build the Connext Micro Cert Library**

NOTE: if using this example with Connext Drive EVAL edition, skip ahead to the next step.
The EVAL edition has pre-built `Release` libraries for Connext Micro Cert, these are located
in the `rti_connext_dds_micro-2.4.14/lib` directories as `*target*_certprofile`, where each
target directory contains one library file ( `librti_mez.a` ).

For those with a non-EVAL installation of Connext Micro Cert, build the libraries with
`Release` build type, `RTIME_CERT=1`, and name the target using a `_certprofile` suffix,
as in: `x64Linux4gcc7.3.0_certprofile`.  
Complete build instructions are in the Connext Micro documentation.


**Build the Data Types Library**

- Open a terminal in the `datatypes` directory.
- Set up the environment to build for Connext (Pro or Micro).  For example: Connext Micro v2 Cert:
    - `export RTIMEHOME=<install-location-for-connext-micro2>`
- Set the target name as an environment variable, such as:
    - x64Linux:
        - `export RTIME_TARGET_NAME=x64Linux4gcc7.3.0_certprofile`
    - armv8Linux:
        - `export RTIME_TARGET_NAME=armv8Linux4gcc7.3.0_certprofile`

- If cross-compiling to a different CPU architecture (such as building ARMv8 on an x64 host PC), ensure that the correct toolchain is available.  For example:
    - armv8Linux:
        - `export CC="/usr/bin/aarch64-linux-gnu-gcc"`
        - `export CXX="/usr/bin/aarch64-linux-gnu-g++"`

- Run the build generator to create a build script for your target, such as:
    - x64Linux:
        - `./bin/build-gen.sh micro2cert x64Linux4gcc7.3.0_certprofile Release`
    - armv8Linux:
        - `./bin/build-gen.sh micro2cert armv8Linux4gcc7.3.0_certprofile Release`
    - Note: change the above to match your target platform if not listed
    - Note: if building on a Windows host, use the `./bin/build-gen.bat` script.

- Run the generated script to build the library, for example:
    - x64Linux:
        - `build/micro2cert-x64Linux4gcc7.3.0_certprofile-Release.sh`
    - armv8Linux:
        - `build/micro2cert-armv8Linux4gcc7.3.0_certprofile-Release.sh`
    - Note: this step will generate and build the typesupport header files and library.


**Build the Example Applications**

*If building for Connext Micro (C-cert)*:

- Open a terminal in the `examples/micro_cert` directory.

- Set up the environment for Connext Micro v2:
    - `export RTIMEHOME=<install-location-for-connext-micro2>`

- Set the target name as an environment variable, such as:
    - x64Linux:
        - `export RTIME_TARGET_NAME=x64Linux4gcc7.3.0_certprofile`
    - armv8Linux:
        - `export RTIME_TARGET_NAME=armv8Linux4gcc7.3.0_certprofile`

- If cross-compiling to a different CPU architecture (such as building ARMv8 on an x64 host PC), ensure that the correct toolchain is available.  For example:
    - armv8Linux:
        - `export CC="/usr/bin/aarch64-linux-gnu-gcc"`

- Create a build directory:
    - `mkdir build`
    - `cd build`

- Use CMake to create the makefile for a `Release` build:
    - `cmake -DCMAKE_BUILD_TYPE=Release ..`

- Run 'make' to build the applications:
    - `make`


*If building for Connext Pro (C++11):*

- Open a terminal in the `examples/pro_cpp11` directory.

- Set up the environment for Connext Pro:
    - `export NDDSHOME=<install-location-for-connext-pro>`

- If cross-compiling to a different CPU architecture (such as building ARMv8 on an x64 host PC), ensure that the correct toolchain is available.  For example:
    - armv8Linux:
        - `export CC="/usr/bin/aarch64-linux-gnu-gcc"`

- Create a build directory:
    - `mkdir build`
    - `cd build`

- Use CMake to create the makefile for a `Release` build:
    - `cmake -DCMAKE_BUILD_TYPE=Release ..`

- Run 'make' to build the applications:
    - `make`



**Run the Example Applications**

RUN ON LINUX BUILD PC (Native):  
If running this example in-place as native apps, a launcher script is available at `examples/run-demo.sh`,
this can be used to launch all applications in the example in separate GNOME terminal tabs:

```
    ./run-demo.sh
```
A series of terminal tabs will open (1 for each application in the example), 
and messages should appear in each terminal to indicate successful communications.  
Applications can be individually exited using ctrl-C.

RUN ON LINUX REMOTE TARGET (No desktop GUI):  
To run on a remote target such as an Automotive SoC platform running ARMv8 Linux:  

- Copy the resulting executables from the `build/<target>' directory to the remote target.
- Launch all 5 applications to run the example system


**Results**

Each application will print a message when it publishes a topic sample, and when a 
subscribed message sample is received.   At startup, status messages will also be 
printed to the terminal when connection to a publisher or subscriber has been established.  
The results should be similar to (for Connext Micro):

```
    Matched a ObjectsDetected subscriber
    Matched a Lidar publisher
    Matched a Camera publisher
    Matched a MapData publisher
    Matched a Pose3D publisher
    Matched a ObjectsDetected subscriber
    Matched a Trajectory publisher
    Matched a ObjectsDetected subscriber
    Valid Lidar_sample received
    Valid Camera_sample received
    Valid MapData_sample received
    Valid Trajectory_sample received
    Valid Pose3D_sample received
    Written ObjectsDetected sample 2
     Subscriber sleeping for 1000 msec...
    Valid Lidar_sample received
```

**Going Further**  
You now have a buildable, working, high-performance system of distributed applications
built to use the safety-certifiable Connext Cert framework.
This is an ideal starting point for building next-gen E/E vehicle architectures;
just add your own application logic to each module and take full advantage of the
communications framework that is already in place.
