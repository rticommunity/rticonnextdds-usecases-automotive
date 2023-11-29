#!/bin/sh

filename=$0
script_dir=`dirname $filename`
{{Loop:Start:Appname:True:all}}
executable_{{Repl:AppName}}_name="{{Repl:AppName}}"
{{Loop:End:AppName:True:all}}

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

{{Loop:Start:Appname:True:all}}
execute $executable_{{Repl:AppName}}_name $bin_dir
{{Loop:End:Appname:True:all}}