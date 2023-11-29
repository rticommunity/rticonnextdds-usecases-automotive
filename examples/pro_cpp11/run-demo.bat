@echo off

rem user may need to edit the target platform and build type in the bin_path below
SET bin_path=%~dp0build\x64Win64VS2017\Debug
SET executable_stimAndPrint_name=%bin_path%\stimAndPrint.exe
SET executable_sceneEval_name=%bin_path%\sceneEval.exe
SET executable_egoMotion_name=%bin_path%\egoMotion.exe
SET executable_localization_name=%bin_path%\localization.exe
SET executable_perception_name=%bin_path%\perception.exe

start %executable_stimAndPrint_name%
start %executable_sceneEval_name%
start %executable_egoMotion_name%
start %executable_localization_name%
start %executable_perception_name%
