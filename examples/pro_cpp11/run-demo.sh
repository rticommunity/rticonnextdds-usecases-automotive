#!/bin/sh

filename=$0
script_dir=`dirname $filename`
executable_stimAndPrint_name="stimAndPrint"
executable_sceneEval_name="sceneEval"
executable_egoMotion_name="egoMotion"
executable_localization_name="localization"
executable_perception_name="perception"

bin_dir=${script_dir}/build/x64Linux4gcc7.3.0

printError(){
    echo "***************************************************************"
    echo $1 executable does not exist in:
    echo $2
    echo ""
    echo Please, try to recompile the application using the commands:
    echo " $ cmake .."
    echo " $ make"
    echo while in the build directory.
    echo "***************************************************************"
}

execute() {
if [ -f "$2/$1" ]; then
    if [ -n "$SSH_CLIENT" ] || [ -n "$SSH_TTY" ]; then
        "$2/$1" &
    else
        gnome-terminal --title "$1" --tab -- bash -c "./$2/$1; sleep 5"
    fi
else
    printError $1 $2
fi
}

execute $executable_stimAndPrint_name $bin_dir
execute $executable_sceneEval_name $bin_dir
execute $executable_egoMotion_name $bin_dir
execute $executable_localization_name $bin_dir
execute $executable_perception_name $bin_dir
