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

set(IDLs SrrDebug5 SrrStatus2 SrrStatus3 SrrTrack SrrStatus5 SrrFeatureSwVersion SrrStatus1 SrrFeatureAlert SrrDebug4 SrrStatus4 SrrDebug3)
set(xml_ros2_astuff)

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
      "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../../.." # res/types
  )

  list(APPEND xml_ros2_astuff "${CMAKE_CURRENT_SOURCE_DIR}/${IDL}.xml")

endforeach()

add_custom_target(xml_ros_delphi_srr_msgs_msg ALL DEPENDS
  ${xml_ros2_astuff}
)
