# datatypes library

This folder has a large collection of data types defined in OMG IDL, and ready to build
into a data type support library for use in your Connext DDS (Pro or Micro) applications.

## Before Building

Some decisions need to be made prior to building this library:

**What version of Connext DDS and build type will I need?**

- Connext Pro (full-featured DDS, with support in this example for C, C++, C++11)
- Connext Micro 2 (reduced-footprint / safety cert DDS, with support here for C-cert, C, C++)
- Both Pro and Micro 2
- Will I build my system for `Debug`, `Release`, or both?
- Am I building this on a Linux or Windows host system?

See the instructions below, and be sure to perform the build steps for each needed variant (pro/micro and build/release).

**Do I want to include support for additional data types?**

This example library includes many data types from `COVESA`, `ROS`, and different vehicle simulators, but to keep
the initial library build times to a minimum, the inclusion of these types is disabled by default.  
To enable these types, edit the file `datatypes/res/types/CMakeLists.txt` to enable / disable the groups of 
data types you expect to need in your system:

```cmake
#-----------------------------------------------------------------------------
# Type Selection: what types will be built?
#-----------------------------------------------------------------------------
# Note to user: (un)comment the following statements to (en/dis)able 
#  specific groups of data type definitions in the libraries to be built.
list(APPEND TYPES_TO_BUILD TYPES_RTI_AUTOMOTIVE)    # RTI Automotive data types
#list(APPEND TYPES_TO_BUILD TYPES_COVESA_VSS)        # COVESA VSS data types
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_CORE)         # ROS2 core data types
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_CARLA)        # 'CARLA' simulator with ROS2 bridge
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_GAZEBO)       # 'Gazebo' simulator in ROS2
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_LGSVL)        # 'LGSVL' simulator with ROS2 bridge
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_ASTUFF)       # Types from AutonomousStuff GitHub repo

```
Changes made to this section must be followed by building the library per the instructions below, 
in order to make these new types available in the library.


## Building

- Point to the location of the **RTI Connext SDK** to build for by setting the environment
  variables:

  - `RTIMEHOME` to the installed location of RTI Connext Micro (if building for Micro | Cert)
     - For example: `export RTIMEHOME=~/rti_connext_dds-6.1.1/rti_connext_dds_micro-2.4.14`

  - `NDDSHOME` to the installed location of RTI Connext DDS Professional (if building for Pro)
     - For example: `export NDDSHOME=~/rti_connext_dds-6.1.1`

- If cross-compiling to a different architecture than the host system, point to the proper tools.  For example:

    - armv8Linux:
        - `export CC="/usr/bin/aarch64-linux-gnu-gcc"`
        - `export CXX="/usr/bin/aarch64-linux-gnu-g++"`

- Generate the script to build the library using:

  - *Linux*:

      [DATABUS_PROJECT_DIR/]bin/build-gen.sh [<connext_sdk> [<target-arch> [<build_type>]]]

  - *Windows*:

      [DATABUS_PROJECT_DIR/]bin/build-gen.bat [<connext_sdk> [<target-arch> [<build_type>]]]

  where 
  - `<connext_sdk>` is the name that you want to use to refer to the build 
     for the selected SDK.  In the documentation, we use the names
      - `pro` | `micro` | `micro2` | `micro2cert`
     for Connext Professional, Connext Micro, Connext Micro 2, and Connext Micro 2 CERT respectively.

  - `<target-arch>` is the target architecture type supported by RTI Connext, such as `x64Linux4gcc7.3.0`,
    `x64Linux4gcc7.3.0_certprofile`, `arm64Linux4gcc7.3.0`, `x64Win64VS2017`, etc.

  - `<build_type>` is the type of build
    - `Debug` : to build using the debug libraries of the selected RTI Connext SDK
    - `Release` : to build using the release libraries of the selected RTI Connext SDK 

  e.g. (if building for the EVAL version of Micro CERT or Connext Drive):

      `bin/build-gen.[sh|bat] micro2cert x64Linux4gcc7.3.0_certprofile Release`

  or (if building for Connext Pro):

      `bin/build-gen.sh pro x64Linux4gcc7.3.0 Debug`

      `bin\build-gen.bat pro x64Win64VS2017 Debug`


- Build the repository using the generated build system script:

      `build/<connext_sdk>-<target_arch>-<build_type>.[sh|bat]`
        
  e.g. (EVAL CERT|Drive, Linux host):

      `build/micro2cert-x64Linux4gcc7.3.0_certprofile-Release.sh`

  or (pro, Windows host):

      `build\pro-x64Win64VS2017-Debug.bat`


- You can repeat the above steps for any available combinations of 
  `(connext_sdk, target_arch, build_type)`

   - An isolated build tree is generated for each combination
         
         build/<connext_sdk>/<target_arch>/<build_type>/
   
   - A standalone build script is generated for each combination
         
         build/<connext_sdk>-<target_arch>-<build_type>.sh or .bat

   - All the combinations can co-exist 

- Cleaning the generated build system

   - Delete the `build` directory to remove ALL the generated build systems
      
         rm -rf build/

   - Remove a specific combination of the build tree by removing a specific 
     `build/<connext_sdk>/<target_arch>/<build_type>` tree, e.g.:

         rm -rf build/pro/x64Linux4gcc7.3.0/Debug


## Running

Once the type support libraries are built (see [Building](#building)), they can be used
in other applications by #including the generated header files for the desired type(s),
and linking the application with the above type support libraries.
**Note** that this is automated when using the `./appsrcgen` utility to create whole-system
application source and CMake files.

## Known Issues

When building on a Windows host with ROS data types enabled in `datatypes\res\types\CMakeLists.txt`
using `TYPES_ROS2_CARLA` and `TYPES_ROS2_GAZEBO` enablers, some redefinition errors may be shown
due to these data types using keywords such as `ERROR`, `FIXED` for enumeration members.

