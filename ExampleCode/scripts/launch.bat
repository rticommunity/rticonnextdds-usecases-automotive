@echo off
setlocal

set dir=%~dp0

set libDir=%NDDSHOME%\lib
set i86Win32Libs=i86Win32VS2017 i86Win32VS2015 i86Win32VS2013 i86Win32VS2012 i86Win32VS2010 i86Win32VS2008 i86Win32VS2005 i86Win32VS2003 i86Win32VC70 i86Win32VC60
set x64Win64Libs=x64Win64VS2017 x64Win64VS2015 x64Win64VS2013 x64Win64VS2012 x64Win64VS2010 x64Win64VS2008 x64Win64VS2005 %i86Win32Libs%


if "%PROCESSOR_ARCHITECTURE%"=="AMD64" (
    set "platformsToTry=%x64Win64Libs%"
) else if "%PROCESSOR_ARCHITEW6432%"=="AMD64" (
    set "platformsToTry=%x64Win64Libs%"
) else if "%PROCESSOR_ARCHITECTURE%"=="x86" (
    set "platformsToTry=%i86Win32Libs%"
) else (
    echo Processor "%PROCESSOR_ARCHITECTURE%" not supported. Please contact support@rti.com.
    exit /b 1
)

for %%a in (%platformsToTry%) do (
    if exist "%libDir%\%%a\nddscore.dll" (
                set platformName=%%a
                goto break
    )
)

@REM We need to use goto to be able to break in the for loop.
:break
echo %platformName%

set obj_dir=..\objs\%platformName%
cd ../resource

if exist "%obj_dir%" (
   start %obj_dir%\VisionSensor.exe
   start %obj_dir%\Lidar.exe
   start %obj_dir%\sensorFusion.exe
   start %obj_dir%\hmi.exe
   start %obj_dir%\collisionAvoidance.exe
   start %obj_dir%\vehiclePlatform.exe
   start %obj_dir%\CameraImageDataSub.exe
   start %obj_dir%\CameraImageDataPub.exe
   ) else (
   echo Object directory %obj_dir% not found. Check if the Visual Studio solution has been built
)
cd ../scripts

