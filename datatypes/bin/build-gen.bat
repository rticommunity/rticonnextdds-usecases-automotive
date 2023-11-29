@echo off

echo "USAGE:"
echo "    %0 [<pro|micro|micro2|micro2cert> [<target-arch> [<Debug|Release>]]]"
echo ""

rem Build System Parameters
rem pro/micro/micro2/micro2cert are supported Connext options (micro==Micro3)
IF "%1"=="" (SET RTI_CONNEXT_SDK=pro) ELSE (SET RTI_CONNEXT_SDK=%1)
IF "%2"=="" (SET RTI_ARCH=x64Win64VS2017) ELSE (SET RTI_ARCH=%2)
IF "%3"=="" (SET RTI_BUILD_TYPE=Debug) ELSE (SET RTI_BUILD_TYPE=%3)

rem show options
echo "Running..."
echo "    %0 %RTI_CONNEXT_SDK% %RTI_ARCH% %RTI_BUILD_TYPE%" 
echo ""

rem set the build dir, root dir, and CERT option
SET RTI_BUILD_DIR=build/%RTI_CONNEXT_SDK%/%RTI_ARCH%/%RTI_BUILD_TYPE%
SET DATABUS_PROJECT_DIR=%CD:\=/%
IF %RTI_CONNEXT_SDK%==micro2cert (
  SET CERT_OPTION=-DCMAKE_C_FLAGS
) ELSE (
  SET CERT_OPTION=
)

rem call CMake to create the build files.
rem NOTE: user may need to edit CMake command line (below) to match their build environment
echo "Generating build system..."
@echo off
cmake -B %RTI_BUILD_DIR% -DCMAKE_BUILD_TYPE=%RTI_BUILD_TYPE% -DRTI_ARCH=%RTI_ARCH% -DRTI_CONNEXT_SDK=%RTI_CONNEXT_SDK% -DDATABUS_PROJECT_DIR=%DATABUS_PROJECT_DIR% %CERT_OPTION% -G "Visual Studio 17 2022" -A x64

@echo off
rem create a batch file to launch the build (using CMake)
echo "Generating build launch script..."
SET RTI_BUILD_SCRIPT=build/%RTI_CONNEXT_SDK%-%RTI_ARCH%-%RTI_BUILD_TYPE%.bat
SET RTI_BSCR_L1=@echo off
SET RTI_BSCR_L2=cmake --build %RTI_BUILD_DIR% --config %RTI_BUILD_TYPE%
echo %RTI_BSCR_L1% > %RTI_BUILD_SCRIPT%
echo %RTI_BSCR_L2% >> %RTI_BUILD_SCRIPT% 

rem instruct on use
echo "Build as follows:"
echo "%RTI_BUILD_SCRIPT%"
echo "    -or-"
echo "cmake --build %RTI_BUILD_DIR% --config %RTI_BUILD_TYPE%"
