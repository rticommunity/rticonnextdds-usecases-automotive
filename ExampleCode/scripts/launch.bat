@echo off

set arch=i86Win32VS2015
set obj_dir=..\objs\%arch%

if exist "%obj_dir%" (
   start ..\objs\i86Win32VS2015\VisionSensor.exe
   start ..\objs\i86Win32VS2015\Lidar.exe
   start ..\objs\i86Win32VS2015\sensorFusion.exe
   start ..\objs\i86Win32VS2015\hmi.exe
   start ..\objs\i86Win32VS2015\collisionAvoidance.exe
   start ..\objs\i86Win32VS2015\vehiclePlatform.exe
   ) else (
   echo Object directory %obj_dir% not found. Check if the Visual Studio solution has been built
)

