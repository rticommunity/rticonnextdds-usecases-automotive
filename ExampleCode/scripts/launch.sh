###############################################################################
##                                                                           ##
##         Permission to modify and use for internal purposes granted.       ##
## This software is provided "as is", without warranty, express or implied.  ##
##                                                                           ##
###############################################################################

#! /bin/sh

if [[ -z "${ARCH}" ]]; then
   ARCH=x64Linux3gcc5.4.0
fi
EXE_DIR=../objs/${ARCH}


# Determine which terminal program to use.
TERM=notset
for terminal in xterm gnome-terminal lxterminal
do
  type ${terminal} >/dev/null 2>&1
  if test $? -eq 0 ; then
    TERM=${terminal}
    break 
  fi
done

# Did we find one we know how to use? If not, error.
case ${TERM} in
  xterm) ;;
  gnome-terminal) ;;
  lxterminal) ;;
  *)
    echo "Terminal; ${TERM} is unknown! Program error!"
    exit 1
esac

### Make sure all component programs are available
PROGRAMS="${EXE_DIR}/VisionSensor ${EXE_DIR}/Lidar ${EXE_DIR}/sensorFusion ${EXE_DIR}/hmi ${EXE_DIR}/collisionAvoidance ${EXE_DIR}/Platform"

for exe in ${PROGRAMS}
do
  if [ ! -r ${exe} ] ; then
    echo "${exe} is not present. Did you build the application?"
    exit 1
  fi

  if [ -d ${exe} ] ; then
    echo "${exe} is a directory. You cannot execute that"
    exit 1
  fi
done

cd ../resource

### Launch all component programs
for exe in ${PROGRAMS}
do
  case ${TERM} in
    lxterminal)
      ${TERM} ${GEOMETRY} -t ${exe} -e "${exe}" &
      ;;
    xterm)
      ${TERM} ${GEOMETRY} -e "${exe}" &
      ;;
    gnome-terminal) 
      ${TERM} ${GEOMETRY} -- "${exe}" &
      ;;
    *) exit 1
  esac
done

### When the user is done, let them kill the programs
echo -n "Press return to kill programs> "
read ignored

for exe in ${PROGRAMS}
do
  pkill -9 ${TERM}
done

cd ../scripts

exit 0
