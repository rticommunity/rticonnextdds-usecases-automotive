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

set(IDLs NestedMessage_Feedback NestedMessage_Result NestedMessage_GetResult_Request Fibonacci_Result Fibonacci_SendGoal_Request NestedMessage_GetResult_Response Fibonacci_FeedbackMessage Fibonacci_GetResult_Request NestedMessage_Goal Fibonacci_Feedback NestedMessage_SendGoal_Request Fibonacci_Goal NestedMessage_SendGoal_Response NestedMessage_FeedbackMessage Fibonacci_GetResult_Response Fibonacci_SendGoal_Response)
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

add_custom_target(xml_ros_test_msgs_action ALL DEPENDS
  ${xml_ros2_core}
)
