#!/bin/sh


echo "USAGE:"
echo "    $0 [<pro|micro|micro2|micro2cert> [<target-arch> [<Debug|Release>]]]"
echo

# Build System Parameters
RTI_CONNEXT_SDK=${1:-pro}           # pro | micro | micro2 | micro2cert
RTI_ARCH=${2:-x64Darwin17clang9.0}
RTI_BUILD_TYPE=${3:-Debug}


echo "Running..."
echo "    $0 $RTI_CONNEXT_SDK $RTI_ARCH $RTI_BUILD_TYPE" 
echo


# Build Dir
RTI_BUILD_DIR="build/$RTI_CONNEXT_SDK/$RTI_ARCH/$RTI_BUILD_TYPE"
DATABUS_PROJECT_DIR=$(cd $(dirname "$0")/..; pwd -P)

# Cert or no?
if [ $RTI_CONNEXT_SDK = "micro2cert" ]
then
    CERT_OPTION=-DCMAKE_C_FLAGS=-DRTI_CERT=1
else
    CERT_OPTION=""
fi

# Generate the Build System
echo "Generating build system..."

# Unix
cmake -B$RTI_BUILD_DIR \
      -DCMAKE_BUILD_TYPE=$RTI_BUILD_TYPE \
      -DRTI_ARCH=$RTI_ARCH \
      -DRTI_CONNEXT_SDK=$RTI_CONNEXT_SDK \
      -DDATABUS_PROJECT_DIR=$DATABUS_PROJECT_DIR \
      $CERT_OPTION \
      -G "Unix Makefiles"

if [ $? -eq 0 ]
then
    # Generate build helper script
    echo "Generating build script..."
    RTI_BUILD_SCRIPT=build/$RTI_CONNEXT_SDK-$RTI_ARCH-$RTI_BUILD_TYPE.sh
    echo "#!/bin/sh" > $RTI_BUILD_SCRIPT
    echo "cmake --build $RTI_BUILD_DIR --config $RTI_BUILD_TYPE" >> $RTI_BUILD_SCRIPT
    chmod a+x $RTI_BUILD_SCRIPT


    # Build using the generated Build System
    echo
    echo
    echo "Build as follows:"
    echo
    echo "$RTI_BUILD_SCRIPT"
    echo "    -or-"
    cat $RTI_BUILD_SCRIPT
fi
