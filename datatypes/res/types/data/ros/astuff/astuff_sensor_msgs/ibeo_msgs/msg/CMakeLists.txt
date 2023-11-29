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

set(IDLs ObjectData2225 Velocity2D DeviceStatus ScanPoint2204 ObjectData2270 Size2D ScanPoint2205 Object2271 UntrackedProperties Object2270 Point2Dui HostVehicleState2805 ErrorWarning ScanData2204 ScanPoint2208 Sigma2D Object2221 HostVehicleState2806 CameraImage MountingPositionF Point2Df Object2225 IbeoDataHeader ObjectData2271 ScannerInfo2204 ScanData2208 ObjectData2221 Point2Di ObjectData2280 TrackedProperties HostVehicleState2807 ResolutionInfo ScanData2205 ScanPoint2202 ContourPointSigma ScanData2202 Object2280 ScannerInfo2205)
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

add_custom_target(xml_ros_ibeo_msgs_msg ALL DEPENDS
  ${xml_ros2_astuff}
)
