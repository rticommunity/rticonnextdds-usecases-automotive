# Next-Gen EE Example (Connext Micro Cert(C) or Connext Pro C++11)

Automotive architectural example using RTI Connext (Micro or Pro)

**NOTE: DO NOT START HERE**

This is the final step in building the example, it depends on first having the type support
library in `../datatypes` be pre-built.   Make sure the type support library has been built before building this example.

**Build the Example Applications**

- Open a terminal in this 'examples' directory, in the subdirectory of the *Pro* or *Micro* example.
- Set up the environment for your planned Connext type (pro or micro2).

*Micro:*
    - `cd micro_cert`
    - `export RTIMEHOME=~/rti_connext_dds-6.1.2/rti_connext_dds_micro-2.4.14`
    - `export RTIME_TARGET_NAME=x64Linux4gcc7.3.0_certprofile`

*Pro:*
    - `cd pro_cpp11`
    - `export NDDSHOME=~/rti_connext_dds-6.1.2`

- If cross-compiling to a different architecture than the host system, point to the proper tools.  For example:

    - armv8Linux:
        - `export CC="/usr/bin/aarch64-linux-gnu-gcc"`
        - `export CXX="/usr/bin/aarch64-linux-gnu-g++"`

    - In addition, the CMakeLists.txt file in each `src/appname` directory will need to be edited to match the name of the Connext type support library (built in the `../datatypes` directory), such as:

        - `SET(TYPEFILES_LIB_DEBUG_DIR ${TYPEFILES_BASE_DIR}/datatypes/build/pro/armv8Linux4gcc7.3.0/Debug/)`
        - `SET(TYPEFILES_LIB_RELEASE_DIR ${TYPEFILES_BASE_DIR}/datatypes/build/pro/armv8Linux4gcc7.3.0/Release/)`

- Create a build directory:
    - `mkdir build`
    - `cd build`

- Use CMake to create the makefile, using a `Release` build type
    - `cmake -DCMAKE_BUILD_TYPE=Release ..`

- Build the example using 'make'
    - `make`

This will build the example applications, placing the resulting binaries in `build/x64Linux4gcc7.3.0/` 
(or equivalent for your target architecture).

**Run the Example Applications**

For convenience, a launcher script is available at `examples/run-demo.sh`
which can be used to launch all applications in the example:

```bash
    chmod +x ./run-demo.sh
    ./run-demo.sh
```

A series of terminal tabs will open (1 for each application in the example) and messages will be printed to each terminal window.   Note that these applications together create a next-gen EE architectural framework; they handle the inter-process communications, but otherwise have no internal logic.  
Applications can be individually exited using ctrl-C.
