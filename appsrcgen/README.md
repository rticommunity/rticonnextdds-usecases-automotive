# appgen.py
Generator for creating multi topic/multi application Connext DDS systems

## What does this do?
**Rapid Creation of Working Multi-App DDS Systems**  
This is a Python3 script utility that generates source + CMake files to create ready-to-build systems
of Connext 'skeleton' applications, communicating on selected DDS topics.  In a matter of minutes,
a working system of multiple Connext applications can be generated, built, and run -- without any
prior knowledge of Connext DDS -- letting you immediately focus on your application logic.

These are 'skeleton' applications that communicate using their defined DDS topics, but otherwise 
have no application logic, an ideal starting point for creating new DDS systems using Connext.


## How does this work?
This is a command-line utility that is passed a system description file argument (simple JSON format) that
defines the applications and DDS topics to be created for the system.  From this file the utility will
generate the application source and build files for the entire system.  The user can then build the system
(using CMake) and launch all of the applications using a generated launch script.

Under the hood, the utility uses the file types defined in the `pathcfg.json` file to determine which template files (in the `templates` directory) are to be used when generating the buildable files.  
The template files are used for simple text replacement, inserting blocks of code for the types/topics/pubs/subs/apps contained in the system description file that was passed on the command line.

At present this supports the following Connext versions and Language combinations:
 - Connext Pro C++11
 - Connext Pro C++
 - Connext Pro C
 - Connext Micro 2 C++
 - Connext Micro 2 C
 - Connext Micro 2 Cert (C)


## Usage
Run using Python 3, with arguments for [1] system config JSON file, and [2] optional PATH to output destination, as in:
```
    python3 appgen.py examples/testsys.json ../MyBuildDir
```
This will place the buildable system described in `examples/testsys.json` into the `../MyBuildDir` directory.
If argument [2] is omitted, it will place the output into the directory indicated in the `dest-path` value inside the .json file of argument [1],


## Creating Custom System Description Files
See the file `TUTORIAL.md` in the root folder of this example.


## Building The Resulting System
To build the resulting system:
- Ensure the `../datatypes` portion of this example has been built for your selected Connext (Pro or Micro).  This is a library of DDS data types to be used in creating these generated systems.

- Open a terminal in the specified destination directory (`../MyBuildDir` or equivalent).

- Set up the environment for your planned Connext type (pro, micro2).
    - If building for Connext Micro Cert, this requires setting RTIMEHOME and RTIME_TARGET_NAME, for example:
        - `export RTIMEHOME=~/rti_connext_dds-6.1.1/rti_connext_dds_micro-2.4.14`
        - `export RTIME_TARGET_NAME=x64Linux4gcc7.3.0_certprofile`
    - If building for Connext Pro, this requires setting NDDSHOME:
        - `export NDDSHOME=~/rti_connext_dds-6.1.1`
    - Connext Pro environment can also be configured using the provided script, for example:
        - `source ~/rti_connext_dds-6.1.1/resource/scripts/rtisetenv_x64Linux4gcc7.3.0.bash`

- Create a build directory:
    - `mkdir build`
    - `cd build`

- Use CMake to create the makefile, using the same build type used to build the `datatypes` library, such as:
    - `cmake -DCMAKE_BUILD_TYPE=Release ..`

- Build the example using 'make'
    - `make`

This will build the example applications, placing the resulting binaries in `build/x64Linux4gcc7.3.0/`
(or equivalent for your target architecture).

## In Case of Build Issues
The most common causes will be:
- Required datatypes have not been built.  See the README.md file in the `datatypes` directory for more information.
- Debug/Release build type mismatch.   Review or rebuild the datatypes library to match the desired build type (debug or release).

## To Run the Resulting System
For convenience, a launcher script is available at `<MyBuildDir>/run-demo.sh`
which can be used to launch all applications in the example:
```
    cd <MyBuildDir>
    ./run-demo.sh
```

A series of terminal tabs will open (1 for each application in the example) and messages will be printed to each terminal window.  Applications can be individually exited using ctrl-C.

