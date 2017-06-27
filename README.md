rticonnextdds-usecases-automotive
=================================

Case + Code Overview
--------------------
This repository is part of Real-Time Innovations' Case + Code project,
a project to create code for real-world RTI Connext DDS use cases.

This use case example includes six applications that send and receive data
related to an automotive system.

The six applications are:

1. LIDAR (Lidar)
        - Sends LIDAR data
        - This application generates periodic random data. The sample size
          of the data is 360kB.  
        - The lidar sends high amounts of data at a high data rate 
2. Vision Sensor (VisionSensor)
        - Sends vision sensor data.
        - The vision sensor sends a smaller amount of data (a few hundred bytes)
          at a lower rate than the LIDAR. 
        - sensor data is read from a file and can be modified to publish 
          different data.
3. Vehicle Platform (vehicle_platform)
        - sends data about the vehicle platform state
        - Takes/Receives control commands
4. Sensor Fusion Module (sensor_fusion)
        - Receives vision sensor information which it then aggrgates…
        - Sends data about/Provides information to the collision avoidance system.
        - The sensor fusion application aggregates all the sensor information which
          is then processed by the collision avoidance system.
5. Collison Avoidance System (collision_avoidance)
        = The sensor fusion application collects all the sensor information and 
          publishes a summary of all sensor data. 
6. HMI (hmi)
       - Receives alerts from the collisoon avoidance application
       - The HMI subscribes to the alert and pops-up an alert box if one of 
         the alert flags are set

Additional Documentation
------------------------

Additional documentation is available in the Docs directory and online at: 
www.rti.com/usecases/automotive.html

Download RTI Connext DDS
------------------------

If you do not already have RTI Connext DDS installed, download and install it 
now. You can use a 30-day trial license to try out the product. Your download 
will include the libraries that are required to run the example, and tools you 
can use to visualize and debug your distributed system.

How to Build this Code
----------------------

On all platforms, the first thing you must do is set an environment variable 
called NDDSHOME. This environment variable must point to the ndds.5.x.x 
directory inside your RTI Connext DDS installation. For more information on how 
to set an environment variable, please see the RTI Core Libraries and Utilities 
Getting Started Guide.

We will refer to the location where you unzipped the example in this document 
as EXAMPLE_HOME.  

All source and build files are located in EXAMPLE_HOME/ExampleCode/.  Before
building or running, change directories into EXAMPLE_HOME/ExampleCode.

Windows Systems
---------------

On a Windows system, start by opening the file 
win32\Automotive-vs2015.sln.

This code is made up of a combination of libraries, source, and IDL files that 
represent the interface to the application. The Visual Studio solution files 
are set up to automatically generate the necessary code and link against the 
required libraries.

Linux Systems
-------------

To build the applications on a Linux system, change directories to the 
ExampleCode directory and use the command:

gmake -f make/Makefile_x64Linux3gcc4.8.2
The platform you choose will be the combination of your processor, OS, and 
compiler version.  Right now this example only supportsx64Linux3gcc4.8.2

Run the Example
---------------

On Windows systems, navigate to the EXAMPLE_HOME\ExampleCode\scripts directory
and run launch.bat.  

On Linux systems, navigate to the EXAMPLE_HOME/ExampleCode/scripts directory 
and run launch.sh.  



