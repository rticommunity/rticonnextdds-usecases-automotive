![Image](https://www.rti.com/hubfs/RTI_Oct2016/Images/rti-logounit.png)  
 RTI Connext DDS Use Case: Automotive
=====================================

## Concept
This use case example includes six applications that send and receive data
related to an automotive system.

The six applications are:

1. LiDAR (Lidar)
  - Sends LiDAR point clouds at a high data rate.
  - This application generates periodic ray-casted LiDAR data from a point observer.
  - Scan is configurable for range & resolution by editing lidar.properties file.
   - Default is full-circle, 180 columns by 64 rows.  184kB per sample.
  - If an `RTI Shapes Demo` is publishing `Circle` data on the same domain, these will be rendered in the LiDAR data.
   - A Yellow circle will control the LiDAR observer position.
  - The LiDAR data can be 3D visualized using RViz2.
2. Vision Sensor (Vision)
  - Sends vision sensor data.
  - The vision sensor sends a smaller amount of data (a few hundred bytes) at
    a lower rate than the LiDAR.
  - Sensor data is read from a file and can be modified to publish different
    data.
3. Vehicle Platform (Vehicle_Platform)
  - Sends data about the vehicle platform state.
  - Takes/Receives control commands.
4. Sensor Fusion Module (Sensor_Fusion)
  - Receives vision sensor information which it then aggregates.
  - Sends data about/Provides information to the collision  
    avoidance system.
  - The sensor fusion application aggregates all the sensor  information which
    is then processed by the collision avoidance system.
5. Collision Avoidance System (Collision_Avoidance)
  - The sensor fusion application collects all the sensor
    information and publishes a summary of all sensor data.
6. HMI (HMI)
  - Receives alerts from the collision avoidance application.
  - The HMI subscribes to the alert and pops-up an alert box if
    one of the alert flags are set.

## Additional Documentation
Detailed documentation for this example is available online at:
  https://www.rti.com/resources/usecases/automotive.

More Case + Code examples are available at:
  https://www.rti.com/resources/usecases

## Download RTI Connext DDS
If you do not already have RTI Connext DDS installed, download and install it
now. You can use a 30-day trial license to try out the product. Your download
will include the libraries that are required to run the example, and tools you
can use to visualize and debug your distributed system.

You can download RTI Connext here: https://www.rti.com/downloads/

## How to Build this Code
On all platforms, the first thing you must do is set an environment variable
called `NDDSHOME`. This environment variable must point to the
rti_connext_dds-x.y.z directory inside your RTI Connext DDS installation. For
more information on how to set an environment variable, please see the RTI
Core Libraries and Utilities Getting Started Guide.

We will refer to the location where you unzipped the example in this document
as EXAMPLE_HOME.  

All source and build files are located in EXAMPLE_HOME/ExampleCode/.  Before
building or running, change directories into EXAMPLE_HOME/ExampleCode.

### Windows Systems
On a Windows system, start by opening the file win32\Automotive-vs2015.sln.

This code is made up of a combination of libraries, source, and IDL files that
represent the interface to the application. The Visual Studio solution files
are set up to automatically generate the necessary code and link against the
required libraries.

### Linux Systems
To build the applications on a Linux system, change directories to the
ExampleCode directory and use the command:

    make -f make/Makefile_x64Linux3gcc4.8.2

The platform you choose will be the combination of your processor, OS, and
compiler version.  Right now this example supports x64Linux3gcc4.8.2, with
an example makefile for x64Linux3gcc5.4.0

## How to Run the Example
On Windows systems, navigate to the EXAMPLE_HOME\ExampleCode\scripts directory
and run

    launch.bat

On Linux systems, navigate to the EXAMPLE_HOME/ExampleCode/scripts directory
and run:

    ./launch.sh
