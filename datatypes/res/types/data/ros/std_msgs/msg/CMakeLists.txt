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

###################################################################################
# Convert IDLs to XML
###################################################################################

set(IDLs String UInt64MultiArray Int64 Int32MultiArray Byte Int16MultiArray ColorRGBA Header UInt64 Float32 UInt32MultiArray MultiArrayLayout Int16 UInt16MultiArray UInt32 Float64MultiArray UInt16 Int8 Bool UInt8MultiArray MultiArrayDimension Float32MultiArray Empty Int8MultiArray Float64 UInt8 ByteMultiArray Char Int32 Int64MultiArray)
set(xml_ros2_core)

foreach(IDL ${IDLs})

  connextdds_rtiddsgen_convert(
    INPUT
      "${CMAKE_CURRENT_SOURCE_DIR}/${IDL}.idl"
    FROM
      "IDL"
    TO
      "XML"
    OUTPUT_DIRECTORY
      "${CMAKE_CURRENT_SOURCE_DIR}"
    INCLUDE_DIRS
      "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../.." # res/types
  )

  list(APPEND xml_ros2_core "${CMAKE_CURRENT_SOURCE_DIR}/${IDL}.xml")

endforeach()

add_custom_target(xml_ros_std_msgs_msg ALL DEPENDS
  ${xml_ros2_core}
)
