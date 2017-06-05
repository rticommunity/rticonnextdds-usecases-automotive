@echo off

set arch=i86Win32VS2015
set obj_dir=..\objs\%arch%

if exist "%obj_dir%" (
   start ..\objs\i86Win32VS2015\VisionSensor.exe
   start ..\objs\i86Win32VS2015\Lidar.exe
   start ..\objs\i86Win32VS2015\sensor_fusion.exe
   start ..\objs\i86Win32VS2015\hmi.exe
   start ..\objs\i86Win32VS2015\collision_avoidance.exe
   start ..\objs\i86Win32VS2015\vehicle_platform.exe
   ) else (
   echo Object directory %obj_dir% not found. Check if the Visual Studio solution has been built
)

