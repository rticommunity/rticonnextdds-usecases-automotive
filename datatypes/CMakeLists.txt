#******************************************************************************
#  (c) 2020 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
#
#   Licensed according to the terms in the LICENSE.md file located at the root 
#   of this software repository:
#
#                                LICENSE.md
#
#*****************************************************************************
cmake_minimum_required(VERSION 3.14)
project(databus)

message(STATUS "databus_SOURCE_DIR = ${databus_SOURCE_DIR}")
message(STATUS "databus_BINARY_DIR = ${databus_BINARY_DIR}")

include(build-helpers/cmake/init.cmake)

#-----------------------------------------------------------------------------

# Generate type handling code + build type libraries
add_subdirectory("res/types")

#-----------------------------------------------------------------------------
