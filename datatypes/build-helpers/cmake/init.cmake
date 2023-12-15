#******************************************************************************
#  (c) 2020 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
#
#   Licensed according to the terms in the LICENSE.md file located at the root 
#   of this software repository:
#
#                                LICENSE.md
#
#*****************************************************************************
# include(<this_list_file_for_common_initialization)
#-----------------------------------------------------------------------------
# Common ONE-TIME Initialization for top-level project CMakeLists.txt files
# 
# include(<this_file>) in a top-level project CMakeLists.file, 
# typically after the setting the top level project() name
#
# e.g. 
# 
#    CMakeLists.txt:
#
#        cmake_minimum_required(VERSION 3.14)i
#
#        project(<name>)   # optional 
#
#        include(${databus_SOURCE_DIR}/build-helpers/cmake/CMakeLists.txt)
#
#        :
#
#-----------------------------------------------------------------------------
# Prevent multiple inclusions
# Skip the file contents, if the variable "BUILD_HELPERS_CMAKE_DIR" is defined
if(NOT BUILD_HELPERS_CMAKE_DIR)
#-----------------------------------------------------------------------------
message(STATUS "BEGIN Initialize ${PROJECT_NAME}: ${CMAKE_CURRENT_LIST_FILE} >>>")
#-----------------------------------------------------------------------------

# Define BUILD_HELPERS_CMAKE_DIR variable = path to *this* directory
get_filename_component(
    BUILD_HELPERS_CMAKE_DIR ${CMAKE_CURRENT_LIST_FILE} DIRECTORY)


# RTIConnextDDS cmake modules
#
# You need to set the variables
#   - NDDSHOME and RTI_ARCH before running this script
#   - Also, will need to set RTIMEHOME if building for Connext Micro
#
#   - Set the build type (CMAKE_BUILD_TYPE to Release/Debug)
#   - Set the link type
#             BUILD_SHARED_LIBS=0 for Static or
#             BUILD_SHARED_LIBS=1 for Dynamic
#
# Variables to pass to the CMake Command
#    "${CONNEXTDDS_DIR}"           # Pro installation
#    "${CONNEXTDDS_ARCH}"          # Pro architecture
#    "${CONNEXTDDSMICRO_DIR}"      # Micro installation
#    "${CONNEXTDDSMICRO_ARCH}"     # Micro architecture
#
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}

  # To allow including custom CMake modules
  "${BUILD_HELPERS_CMAKE_DIR}/cmake_modules"

  # Set the path to where FindRTIConnextDDS.cmake is located
  "${CONNEXTDDS_DIR}/resource/cmake" # CMake Argument
  "${NDDSHOME}/resource/cmake"       # CMake Argument
  "$ENV{NDDSHOME}/resource/cmake"    # Environment Variable
)

message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

#-----------------------------------------------------------------------------
# RTI_CONNEXT_SDK specific settings

# Checking that $NDDSHOME is set
if("${RTI_CONNEXT_SDK}" MATCHES "pro")

  # Set the target architecture
  set(CONNEXTDDS_ARCH "${RTI_ARCH}")

  # Find the ConnextDDS libraries and set the needed variables
  find_package(RTIConnextDDS 6.0.1 COMPONENTS core)

  # Connext DDS SDK Installation Directory
  set(RTI_CONNEXT_SDK_DIR "${CONNEXTDDS_DIR}")

elseif("${RTI_CONNEXT_SDK}" MATCHES "micro")

  # Set the target architecture
  set(CONNEXTDDSMICRO_ARCH "${RTI_ARCH}")

  # Find the ConnextDDS Micro libraries and set the needed variables
  if("${RTI_CONNEXT_SDK}" STREQUAL "micro2")
    find_package(RTIConnextDDSMicro 2.4.12)
  else() # micro [micro3+]
    find_package(RTIConnextDDSMicro 3.0.2)
  endif()

  # Connext DDS SDK Installation Directory
  set(RTI_CONNEXT_SDK_DIR "${CONNEXTDDSMICRO_DIR}")

else()
  message(FATAL_ERROR "The ${RTI_CONNEXT_SDK} SDK is not supported")
endif()

message(STATUS "RTI_CONNEXT_SDK_DIR: ${RTI_CONNEXT_SDK_DIR}")

#-----------------------------------------------------------------------------
# Output Directories 

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

#-----------------------------------------------------------------------------
# OPTIONALLY import "databus" targets to satisfy "component" build dependencies

# Include IMPORTED targets from the "databus" project if and only if (iff)
# they are will not be defined by the current CMake project build
# - i.e. the "databus" project is NOT a sub-directory of the current project
#   i.e. DATABUS_PROJECT_DIR is NOT a subdirectory of CMAKE_SOURCE_DIR
message(STATUS "DATABUS_PROJECT_DIR: ${DATABUS_PROJECT_DIR}")
if(NOT "${DATABUS_PROJECT_DIR}" MATCHES "^${CMAKE_SOURCE_DIR}")
    set(databus_exports_file 
        "${DATABUS_PROJECT_DIR}/build/${RTI_CONNEXT_SDK}/${RTI_ARCH}/${CMAKE_BUILD_TYPE}/databus-exports.cmake")
    if (EXISTS "${databus_exports_file}") 
        include("${databus_exports_file}")
    else()
        message(FATAL_ERROR 
          "\nPlease build 'databus' project first!\n ${DATABUS_PROJECT_DIR}\n")
    endif()
endif()

#-----------------------------------------------------------------------------
# Install Directories

set(INSTALL_LIBRARY_OUTPUT_DIRECTORY 
    "${CMAKE_SOURCE_DIR}/lib/${RTI_CONNEXT_SDK}/${RTI_ARCH}/${CMAKE_BUILD_TYPE}")

set(INSTALL_ARCHIVE_OUTPUT_DIRECTORY 
    "${CMAKE_SOURCE_DIR}/lib/${RTI_CONNEXT_SDK}/${RTI_ARCH}/${CMAKE_BUILD_TYPE}")

set(INSTALL_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_SOURCE_DIR}/lib/${RTI_CONNEXT_SDK}/${RTI_ARCH}/${CMAKE_BUILD_TYPE}")

#-----------------------------------------------------------------------------
message(STATUS "END   Initialize ${PROJECT_NAME}: ${CMAKE_CURRENT_LIST_FILE} <<<")
#-----------------------------------------------------------------------------
endif()
