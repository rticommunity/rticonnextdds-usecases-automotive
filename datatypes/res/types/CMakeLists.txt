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

#-----------------------------------------------------------------------------
# Type Selection: what types will be built?
#-----------------------------------------------------------------------------
# Note to user: (un)comment the following statements to (en/dis)able 
#  specific groups of data type definitions in the libraries to be built.
list(APPEND TYPES_TO_BUILD TYPES_RTI_AUTOMOTIVE)    # RTI Automotive data types
#list(APPEND TYPES_TO_BUILD TYPES_COVESA_VSS)        # COVESA VSS data types
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_CORE)         # ROS2 core data types
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_CARLA)        # 'CARLA' simulator with ROS2 bridge
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_GAZEBO)       # 'Gazebo' simulator in ROS2
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_LGSVL)        # 'LGSVL' simulator with ROS2 bridge
#list(APPEND TYPES_TO_BUILD TYPES_ROS2_ASTUFF)       # Types from AutonomousStuff GitHub repo


#-----------------------------------------------------------------------------
# Codegen
#-----------------------------------------------------------------------------

# Include the CodegenRTIConnextDDS cmake module
include(CodegenRTIConnextDDS)

# Connext SDK specific codegen settings: 
if("${RTI_CONNEXT_SDK}" MATCHES "pro")
  set(CODEGEN_FLAGS UNBOUNDED NAMESPACE)
elseif("${RTI_CONNEXT_SDK}" MATCHES "micro")
  set(CODEGEN_FLAGS MICRO)
endif()

set(CODEGEN_OUTPUT_DIR "${CMAKE_BINARY_DIR}/../../generated")
message(STATUS "CODEGEN_OUTPUT_DIR: ${CODEGEN_OUTPUT_DIR}")

#-----------------------------------------------------------------------------
# Convert IDLs to XML
#-----------------------------------------------------------------------------

add_subdirectory("data")
# add_subdirectory("services")

list(FIND TYPES_TO_BUILD "TYPES_RTI_AUTOMOTIVE" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_RTI_AUTOMOTIVE to XML Gen")
  add_custom_target(xml_gen_rti_automotive ALL DEPENDS
    ${xml_rti_automotive}
  )
endif()
list(FIND TYPES_TO_BUILD "TYPES_COVESA_VSS" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_COVESA_VSS to XML Gen")
  add_custom_target(xml_gen_covesa_vss ALL DEPENDS
    ${xml_covesa_vss}
  )
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_CORE" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_CORE to XML Gen")
  add_custom_target(xml_gen_ros2_core ALL DEPENDS
    ${xml_ros2_core}
  )
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_CARLA" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_CARLA to XML Gen")
  add_custom_target(xml_gen_ros2_carla ALL DEPENDS
    ${xml_ros2_carla}
  )
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_GAZEBO" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_GAZEBO to XML Gen")
  add_custom_target(xml_gen_ros2_gazebo ALL DEPENDS
    ${xml_ros2_gazebo}
  )
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_LGSVL" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_LGSVL to XML Gen")
  add_custom_target(xml_gen_ros2_lgsvl ALL DEPENDS
    ${xml_ros2_lgsvl}
  )
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_ASTUFF" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_ASTUFF to XML Gen")
  add_custom_target(xml_gen_ros2_astuff ALL DEPENDS
    ${xml_ros2_astuff}
  )
endif()

#-----------------------------------------------------------------------------
# Generate files
#-----------------------------------------------------------------------------

set(IDL_RTI_AUTOMOTIVE 
  # RTI Automotive types
  data/rti/base/Primitives_t.idl
  data/rti/base/Entity_t.idl
  data/rti/base/Variants_t.idl
  data/rti/actuation/Actuation_t.idl
  data/rti/physics/Point2D_t.idl
  data/rti/physics/Point3D_t.idl
  data/rti/physics/Acceleration_t.idl
  data/rti/physics/Frame_t.idl
  data/rti/physics/Path_t.idl
  data/rti/physics/Pose3D_t.idl
  data/rti/physics/Quaternion_t.idl
  data/rti/physics/Vector_t.idl
  data/rti/physics/Velocity_t.idl
  data/rti/physics/Time_t.idl
  data/rti/perception/Polygon_t.idl
  data/rti/perception/Object_t.idl
  data/rti/perception/Lane_t.idl
  data/rti/perception/Track_t.idl
  data/rti/perception/Trajectory_t.idl
  data/rti/planning/Alert_t.idl
  data/rti/planning/Maps_t.idl
  data/rti/sensing/Camera_t.idl
  data/rti/sensing/Compass_t.idl
  data/rti/sensing/Gnss_t.idl
  data/rti/sensing/Image_t.idl
  data/rti/sensing/Imu_t.idl
  data/rti/sensing/PointCloud_t.idl
  data/rti/sensing/Lidar_t.idl
  data/rti/gateway/CAN_t.idl
  data/rti/system/InfoTopic_t.idl
  data/rti/system/StatusTopic_t.idl
  data/my_types/hello/txtmsg.idl
)

set(IDL_COVESA_VSS
  # COVESA VSS data types
  data/covesa/base/entity.idl
  data/covesa/ADAS/ADAS.idl
  data/covesa/Body/Body.idl
  data/covesa/Cabin/Cabin.idl
  data/covesa/Chassis/Chassis.idl
  data/covesa/Driver/Driver.idl
  data/covesa/OBD/OBD.idl
  data/covesa/Powertrain/Powertrain.idl
  data/covesa/Vehicle/Vehicle.idl
)

set(IDL_ROS2_CORE
  # ROS2 core data types
  data/ros/builtin_interfaces/msg/Time.idl
  data/ros/builtin_interfaces/msg/Duration.idl
  data/ros/unique_identifier_msgs/msg/UUID.idl
  data/ros/std_msgs/msg/Header.idl
  data/ros/std_msgs/msg/Empty.idl
  data/ros/std_msgs/msg/Bool.idl
  data/ros/std_msgs/msg/Byte.idl
  data/ros/std_msgs/msg/Char.idl
  data/ros/std_msgs/msg/Int8.idl
  data/ros/std_msgs/msg/UInt8.idl
  data/ros/std_msgs/msg/Int16.idl
  data/ros/std_msgs/msg/UInt16.idl
  data/ros/std_msgs/msg/Int32.idl
  data/ros/std_msgs/msg/UInt32.idl
  data/ros/std_msgs/msg/Int64.idl
  data/ros/std_msgs/msg/UInt64.idl
  data/ros/std_msgs/msg/Float32.idl
  data/ros/std_msgs/msg/Float64.idl
  data/ros/std_msgs/msg/String.idl
  data/ros/std_msgs/msg/ByteMultiArray.idl
  data/ros/std_msgs/msg/Int8MultiArray.idl
  data/ros/std_msgs/msg/UInt8MultiArray.idl
  data/ros/std_msgs/msg/Int16MultiArray.idl
  data/ros/std_msgs/msg/UInt16MultiArray.idl
  data/ros/std_msgs/msg/Int32MultiArray.idl
  data/ros/std_msgs/msg/UInt32MultiArray.idl
  data/ros/std_msgs/msg/Int64MultiArray.idl
  data/ros/std_msgs/msg/UInt64MultiArray.idl
  data/ros/std_msgs/msg/Float32MultiArray.idl
  data/ros/std_msgs/msg/Float64MultiArray.idl
  data/ros/std_msgs/msg/MultiArrayDimension.idl
  data/ros/std_msgs/msg/MultiArrayLayout.idl
  data/ros/std_msgs/msg/ColorRGBA.idl
  data/ros/geometry_msgs/msg/Pose2D.idl
  data/ros/geometry_msgs/msg/Twist.idl
  data/ros/geometry_msgs/msg/QuaternionStamped.idl
  data/ros/geometry_msgs/msg/AccelStamped.idl
  data/ros/geometry_msgs/msg/PointStamped.idl
  data/ros/geometry_msgs/msg/PoseWithCovariance.idl
  data/ros/geometry_msgs/msg/PoseWithCovarianceStamped.idl
  data/ros/geometry_msgs/msg/Quaternion.idl
  data/ros/geometry_msgs/msg/PoseArray.idl
  data/ros/geometry_msgs/msg/TwistStamped.idl
  data/ros/geometry_msgs/msg/AccelWithCovarianceStamped.idl
  data/ros/geometry_msgs/msg/AccelWithCovariance.idl
  data/ros/geometry_msgs/msg/Accel.idl
  data/ros/geometry_msgs/msg/TwistWithCovarianceStamped.idl
  data/ros/geometry_msgs/msg/Vector3Stamped.idl
  data/ros/geometry_msgs/msg/Wrench.idl
  data/ros/geometry_msgs/msg/Transform.idl
  data/ros/geometry_msgs/msg/Pose.idl
  data/ros/geometry_msgs/msg/Polygon.idl
  data/ros/geometry_msgs/msg/TransformStamped.idl
  data/ros/geometry_msgs/msg/WrenchStamped.idl
  data/ros/geometry_msgs/msg/Inertia.idl
  data/ros/geometry_msgs/msg/PoseStamped.idl
  data/ros/geometry_msgs/msg/Point.idl
  data/ros/geometry_msgs/msg/Point32.idl
  data/ros/geometry_msgs/msg/TwistWithCovariance.idl
  data/ros/geometry_msgs/msg/PolygonStamped.idl
  data/ros/geometry_msgs/msg/InertiaStamped.idl
  data/ros/geometry_msgs/msg/Vector3.idl
  data/ros/nav_msgs/msg/Path.idl
  data/ros/nav_msgs/msg/MapMetaData.idl
  data/ros/nav_msgs/msg/OccupancyGrid.idl
  data/ros/nav_msgs/msg/GridCells.idl
  data/ros/nav_msgs/msg/Odometry.idl
  data/ros/nav_msgs/srv/GetMap_Request.idl
  data/ros/nav_msgs/srv/SetMap_Request.idl
  data/ros/nav_msgs/srv/GetPlan_Request.idl
  data/ros/nav_msgs/srv/GetMap_Response.idl
  data/ros/nav_msgs/srv/SetMap_Response.idl
  data/ros/nav_msgs/srv/GetPlan_Response.idl
  data/ros/sensor_msgs/msg/CompressedImage.idl
  data/ros/sensor_msgs/msg/Illuminance.idl
  data/ros/sensor_msgs/msg/MultiEchoLaserScan.idl
  data/ros/sensor_msgs/msg/BatteryState.idl
  data/ros/sensor_msgs/msg/PointCloud.idl
  data/ros/sensor_msgs/msg/NavSatStatus.idl
  data/ros/sensor_msgs/msg/ChannelFloat32.idl
  data/ros/sensor_msgs/msg/Imu.idl
  data/ros/sensor_msgs/msg/PointField.idl
  data/ros/sensor_msgs/msg/MultiDOFJointState.idl
  data/ros/sensor_msgs/msg/Image.idl
  data/ros/sensor_msgs/msg/Joy.idl
  data/ros/sensor_msgs/msg/JointState.idl
  data/ros/sensor_msgs/msg/CameraInfo.idl
  data/ros/sensor_msgs/msg/FluidPressure.idl
  data/ros/sensor_msgs/msg/NavSatFix.idl
  data/ros/sensor_msgs/msg/Range.idl
  data/ros/sensor_msgs/msg/LaserScan.idl
  data/ros/sensor_msgs/msg/PointCloud2.idl
  data/ros/sensor_msgs/msg/RelativeHumidity.idl
  data/ros/sensor_msgs/msg/JoyFeedbackArray.idl
  data/ros/sensor_msgs/msg/LaserEcho.idl
  data/ros/sensor_msgs/msg/TimeReference.idl
  data/ros/sensor_msgs/msg/RegionOfInterest.idl
  data/ros/sensor_msgs/msg/Temperature.idl
  data/ros/sensor_msgs/msg/JoyFeedback.idl
  data/ros/sensor_msgs/msg/MagneticField.idl
  data/ros/sensor_msgs/srv/SetCameraInfo_Request.idl
  data/ros/sensor_msgs/srv/SetCameraInfo_Response.idl
  data/ros/shape_msgs/msg/MeshTriangle.idl
  data/ros/shape_msgs/msg/SolidPrimitive.idl
  data/ros/shape_msgs/msg/Plane.idl
  data/ros/shape_msgs/msg/Mesh.idl
  data/ros/map_msgs/msg/ProjectedMap.idl
  data/ros/map_msgs/msg/PointCloud2Update.idl
  data/ros/map_msgs/msg/OccupancyGridUpdate.idl
  data/ros/map_msgs/msg/ProjectedMapInfo.idl
  data/ros/map_msgs/srv/GetPointMap_Request.idl
  data/ros/map_msgs/srv/GetPointMapROI_Request.idl
  data/ros/map_msgs/srv/GetPointMap_Response.idl
  data/ros/map_msgs/srv/GetMapROI_Request.idl
  data/ros/map_msgs/srv/GetMapROI_Response.idl
  data/ros/map_msgs/srv/ProjectedMapsInfo_Request.idl
  data/ros/map_msgs/srv/SaveMap_Response.idl
  data/ros/map_msgs/srv/GetPointMapROI_Response.idl
  data/ros/map_msgs/srv/ProjectedMapsInfo_Response.idl
  data/ros/map_msgs/srv/SaveMap_Request.idl
  data/ros/map_msgs/srv/SetMapProjections_Response.idl
  data/ros/map_msgs/srv/SetMapProjections_Request.idl
  data/ros/visualization_msgs/msg/Marker.idl
  data/ros/visualization_msgs/msg/MenuEntry.idl
  data/ros/visualization_msgs/msg/InteractiveMarkerInit.idl
  data/ros/visualization_msgs/msg/InteractiveMarker.idl
  data/ros/visualization_msgs/msg/ImageMarker.idl
  data/ros/visualization_msgs/msg/InteractiveMarkerUpdate.idl
  data/ros/visualization_msgs/msg/InteractiveMarkerControl.idl
  data/ros/visualization_msgs/msg/InteractiveMarkerPose.idl
  data/ros/visualization_msgs/msg/InteractiveMarkerFeedback.idl
  data/ros/visualization_msgs/msg/MarkerArray.idl
  data/ros/visualization_msgs/srv/GetInteractiveMarkers_Request.idl
  data/ros/visualization_msgs/srv/GetInteractiveMarkers_Response.idl
  data/ros/tf2_msgs/msg/TF2Error.idl
  data/ros/tf2_msgs/msg/TFMessage.idl
  data/ros/tf2_msgs/action/LookupTransform_GetResult_Request.idl
  data/ros/tf2_msgs/action/LookupTransform_GetResult_Response.idl
  data/ros/tf2_msgs/action/LookupTransform_FeedbackMessage.idl
  data/ros/tf2_msgs/action/LookupTransform_SendGoal_Request.idl
  data/ros/tf2_msgs/action/LookupTransform_Goal.idl
  data/ros/tf2_msgs/action/LookupTransform_SendGoal_Response.idl
  data/ros/tf2_msgs/action/LookupTransform_Result.idl
  data/ros/tf2_msgs/action/LookupTransform_Feedback.idl
  data/ros/tf2_msgs/srv/FrameGraph_Request.idl
  data/ros/tf2_msgs/srv/FrameGraph_Response.idl
  data/ros/lifecycle_msgs/msg/TransitionEvent.idl
  data/ros/lifecycle_msgs/msg/TransitionDescription.idl
  data/ros/lifecycle_msgs/msg/State.idl
  data/ros/lifecycle_msgs/msg/Transition.idl
  data/ros/lifecycle_msgs/srv/GetAvailableTransitions_Request.idl
  data/ros/lifecycle_msgs/srv/GetAvailableTransitions_Response.idl
  data/ros/lifecycle_msgs/srv/GetState_Request.idl
  data/ros/lifecycle_msgs/srv/GetState_Response.idl
  data/ros/lifecycle_msgs/srv/GetAvailableStates_Response.idl
  data/ros/lifecycle_msgs/srv/ChangeState_Request.idl
  data/ros/lifecycle_msgs/srv/ChangeState_Response.idl
  data/ros/lifecycle_msgs/srv/GetAvailableStates_Request.idl
  data/ros/rcl_interfaces/msg/FloatingPointRange.idl
  data/ros/rcl_interfaces/msg/IntegerRange.idl
  data/ros/rcl_interfaces/msg/ParameterDescriptor.idl
  data/ros/rcl_interfaces/msg/ParameterEvent.idl
  data/ros/rcl_interfaces/msg/ParameterType.idl
  data/ros/rcl_interfaces/msg/ParameterEventDescriptors.idl
  data/ros/rcl_interfaces/msg/Log.idl
  data/ros/rcl_interfaces/msg/ParameterValue.idl
  data/ros/rcl_interfaces/msg/ListParametersResult.idl
  data/ros/rcl_interfaces/msg/SetParametersResult.idl
  data/ros/rcl_interfaces/msg/Parameter.idl
  data/ros/rcl_interfaces/srv/ListParameters_Response.idl
  data/ros/rcl_interfaces/srv/SetParameters_Response.idl
  data/ros/rcl_interfaces/srv/GetParameterTypes_Response.idl
  data/ros/rcl_interfaces/srv/SetParametersAtomically_Response.idl
  data/ros/rcl_interfaces/srv/SetParametersAtomically_Request.idl
  data/ros/rcl_interfaces/srv/GetParameters_Request.idl
  data/ros/rcl_interfaces/srv/DescribeParameters_Response.idl
  data/ros/rcl_interfaces/srv/SetParameters_Request.idl
  data/ros/rcl_interfaces/srv/GetParameters_Response.idl
  data/ros/rcl_interfaces/srv/GetParameterTypes_Request.idl
  data/ros/rcl_interfaces/srv/DescribeParameters_Request.idl
  data/ros/rcl_interfaces/srv/ListParameters_Request.idl
  data/ros/libstatistics_collector/msg/DummyMessage.idl
  data/ros/std_srvs/srv/Empty_Response.idl
  data/ros/std_srvs/srv/SetBool_Response.idl
  data/ros/std_srvs/srv/Empty_Request.idl
  data/ros/std_srvs/srv/SetBool_Request.idl
  data/ros/std_srvs/srv/Trigger_Request.idl
  data/ros/std_srvs/srv/Trigger_Response.idl
  data/ros/diagnostic_msgs/msg/DiagnosticStatus.idl
  data/ros/diagnostic_msgs/msg/KeyValue.idl
  data/ros/diagnostic_msgs/msg/DiagnosticArray.idl
  data/ros/diagnostic_msgs/srv/SelfTest_Request.idl
  data/ros/diagnostic_msgs/srv/AddDiagnostics_Response.idl
  data/ros/diagnostic_msgs/srv/AddDiagnostics_Request.idl
  data/ros/diagnostic_msgs/srv/SelfTest_Response.idl
  data/ros/trajectory_msgs/msg/JointTrajectoryPoint.idl
  data/ros/trajectory_msgs/msg/JointTrajectory.idl
  data/ros/trajectory_msgs/msg/MultiDOFJointTrajectoryPoint.idl
  data/ros/trajectory_msgs/msg/MultiDOFJointTrajectory.idl
  data/ros/action_msgs/msg/GoalStatusArray.idl
  data/ros/action_msgs/msg/GoalInfo.idl
  data/ros/action_msgs/msg/GoalStatus.idl
  data/ros/action_msgs/srv/CancelGoal_Request.idl
  data/ros/action_msgs/srv/CancelGoal_Response.idl
  data/ros/test_rclcpp/msg/UInt32.idl
  data/ros/test_rclcpp/srv/AddTwoInts_Response.idl
  data/ros/test_rclcpp/srv/AddTwoInts_Request.idl
  data/ros/test_communication/msg/UInt32.idl
  data/ros/test_communication/msg/FieldsWithSameType.idl
  data/ros/logging_demo/srv/ConfigLogger_Request.idl
  data/ros/logging_demo/srv/ConfigLogger_Response.idl
  data/ros/rosgraph_msgs/msg/Clock.idl
  data/ros/actionlib_msgs/msg/GoalStatusArray.idl
  data/ros/actionlib_msgs/msg/GoalID.idl
  data/ros/actionlib_msgs/msg/GoalStatus.idl
  data/ros/rqt_py_common/msg/Val.idl
  data/ros/rqt_py_common/msg/ArrayVal.idl
  data/ros/rqt_py_common/srv/AddTwoInts_Response.idl
  data/ros/rqt_py_common/srv/AddTwoInts_Request.idl
  data/ros/statistics_msgs/msg/StatisticDataPoint.idl
  data/ros/statistics_msgs/msg/MetricsMessage.idl
  data/ros/statistics_msgs/msg/StatisticDataType.idl
  data/ros/stereo_msgs/msg/DisparityImage.idl
  data/ros/composition_interfaces/srv/LoadNode_Request.idl
  data/ros/composition_interfaces/srv/UnloadNode_Response.idl
  data/ros/composition_interfaces/srv/LoadNode_Response.idl
  data/ros/composition_interfaces/srv/UnloadNode_Request.idl
  data/ros/composition_interfaces/srv/ListNodes_Request.idl
  data/ros/composition_interfaces/srv/ListNodes_Response.idl
  data/ros/move_base_msgs/action/MoveBase_GetResult_Response.idl
  data/ros/move_base_msgs/action/MoveBase_Feedback.idl
  data/ros/move_base_msgs/action/MoveBase_GetResult_Request.idl
  data/ros/move_base_msgs/action/MoveBase_Result.idl
  data/ros/move_base_msgs/action/MoveBase_SendGoal_Response.idl
  data/ros/move_base_msgs/action/MoveBase_Goal.idl
  data/ros/move_base_msgs/action/MoveBase_FeedbackMessage.idl
  data/ros/move_base_msgs/action/MoveBase_SendGoal_Request.idl
  data/ros/rclcpp/msg/Header.idl
  data/ros/rclcpp/msg/MessageWithHeader.idl
  data/ros/rmw_dds_common/msg/NodeEntitiesInfo.idl
  data/ros/rmw_dds_common/msg/ParticipantEntitiesInfo.idl
  data/ros/rmw_dds_common/msg/Gid.idl
  data/ros/rosidl_generator_py/msg/MultiNested.idl
  data/ros/rosidl_generator_py/msg/Strings.idl
  data/ros/rosidl_generator_py/msg/UnboundedSequences.idl
  data/ros/rosidl_generator_py/msg/StringArrays.idl
  data/ros/rosidl_generator_py/msg/BoundedSequences.idl
  data/ros/rosidl_generator_py/msg/WStrings.idl
  data/ros/rosidl_generator_py/msg/BasicTypes.idl
  data/ros/rosidl_generator_py/msg/Arrays.idl
  data/ros/rosidl_generator_py/msg/Constants.idl
  data/ros/rosidl_generator_py/msg/Empty.idl
  data/ros/rosidl_generator_py/msg/Nested.idl
  data/ros/rosidl_generator_py/msg/Defaults.idl
  data/ros/test_msgs/msg/MultiNested.idl
  data/ros/test_msgs/msg/Strings.idl
  data/ros/test_msgs/msg/UnboundedSequences.idl
  data/ros/test_msgs/msg/Builtins.idl
  data/ros/test_msgs/msg/BoundedSequences.idl
  data/ros/test_msgs/msg/WStrings.idl
  data/ros/test_msgs/msg/BasicTypes.idl
  data/ros/test_msgs/msg/Arrays.idl
  data/ros/test_msgs/msg/Constants.idl
  data/ros/test_msgs/msg/Empty.idl
  data/ros/test_msgs/msg/Nested.idl
  data/ros/test_msgs/msg/Defaults.idl
  data/ros/test_msgs/action/NestedMessage_Feedback.idl
  data/ros/test_msgs/action/NestedMessage_Result.idl
  data/ros/test_msgs/action/NestedMessage_GetResult_Request.idl
  data/ros/test_msgs/action/Fibonacci_Result.idl
  data/ros/test_msgs/action/Fibonacci_SendGoal_Request.idl
  data/ros/test_msgs/action/NestedMessage_GetResult_Response.idl
  data/ros/test_msgs/action/Fibonacci_FeedbackMessage.idl
  data/ros/test_msgs/action/Fibonacci_GetResult_Request.idl
  data/ros/test_msgs/action/NestedMessage_Goal.idl
  data/ros/test_msgs/action/Fibonacci_Feedback.idl
  data/ros/test_msgs/action/NestedMessage_SendGoal_Request.idl
  data/ros/test_msgs/action/Fibonacci_Goal.idl
  data/ros/test_msgs/action/NestedMessage_SendGoal_Response.idl
  data/ros/test_msgs/action/NestedMessage_FeedbackMessage.idl
  data/ros/test_msgs/action/Fibonacci_GetResult_Response.idl
  data/ros/test_msgs/action/Fibonacci_SendGoal_Response.idl
  data/ros/test_msgs/srv/BasicTypes_Response.idl
  data/ros/test_msgs/srv/Arrays_Response.idl
  data/ros/test_msgs/srv/Empty_Response.idl
  data/ros/test_msgs/srv/Empty_Request.idl
  data/ros/test_msgs/srv/Arrays_Request.idl
  data/ros/test_msgs/srv/BasicTypes_Request.idl
  data/ros/example_interfaces/msg/String.idl
  data/ros/example_interfaces/msg/UInt64MultiArray.idl
  data/ros/example_interfaces/msg/Int64.idl
  data/ros/example_interfaces/msg/Int32MultiArray.idl
  data/ros/example_interfaces/msg/Byte.idl
  data/ros/example_interfaces/msg/Int16MultiArray.idl
  data/ros/example_interfaces/msg/UInt64.idl
  data/ros/example_interfaces/msg/Float32.idl
  data/ros/example_interfaces/msg/UInt32MultiArray.idl
  data/ros/example_interfaces/msg/MultiArrayLayout.idl
  data/ros/example_interfaces/msg/Int16.idl
  data/ros/example_interfaces/msg/UInt16MultiArray.idl
  data/ros/example_interfaces/msg/UInt32.idl
  data/ros/example_interfaces/msg/Float64MultiArray.idl
  data/ros/example_interfaces/msg/WString.idl
  data/ros/example_interfaces/msg/UInt16.idl
  data/ros/example_interfaces/msg/Int8.idl
  data/ros/example_interfaces/msg/Bool.idl
  data/ros/example_interfaces/msg/UInt8MultiArray.idl
  data/ros/example_interfaces/msg/MultiArrayDimension.idl
  data/ros/example_interfaces/msg/Float32MultiArray.idl
  data/ros/example_interfaces/msg/Empty.idl
  data/ros/example_interfaces/msg/Int8MultiArray.idl
  data/ros/example_interfaces/msg/Float64.idl
  data/ros/example_interfaces/msg/UInt8.idl
  data/ros/example_interfaces/msg/ByteMultiArray.idl
  data/ros/example_interfaces/msg/Char.idl
  data/ros/example_interfaces/msg/Int32.idl
  data/ros/example_interfaces/msg/Int64MultiArray.idl
  data/ros/example_interfaces/action/Fibonacci_Result.idl
  data/ros/example_interfaces/action/Fibonacci_SendGoal_Request.idl
  data/ros/example_interfaces/action/Fibonacci_FeedbackMessage.idl
  data/ros/example_interfaces/action/Fibonacci_GetResult_Request.idl
  data/ros/example_interfaces/action/Fibonacci_Feedback.idl
  data/ros/example_interfaces/action/Fibonacci_Goal.idl
  data/ros/example_interfaces/action/Fibonacci_GetResult_Response.idl
  data/ros/example_interfaces/action/Fibonacci_SendGoal_Response.idl
  data/ros/example_interfaces/srv/AddTwoInts_Response.idl
  data/ros/example_interfaces/srv/SetBool_Response.idl
  data/ros/example_interfaces/srv/SetBool_Request.idl
  data/ros/example_interfaces/srv/Trigger_Request.idl
  data/ros/example_interfaces/srv/Trigger_Response.idl
  data/ros/example_interfaces/srv/AddTwoInts_Request.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_Result.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_SendGoal_Request.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_FeedbackMessage.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_GetResult_Request.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_Feedback.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_Goal.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_GetResult_Response.idl
  data/ros/action_tutorials_interfaces/action/Fibonacci_SendGoal_Response.idl
  data/ros/pendulum_msgs/msg/RttestResults.idl
  data/ros/pendulum_msgs/msg/JointCommand.idl
  data/ros/pendulum_msgs/msg/JointState.idl
  data/ros/turtlesim/msg/Color.idl
  data/ros/turtlesim/msg/Pose.idl
  data/ros/turtlesim/action/RotateAbsolute_GetResult_Response.idl
  data/ros/turtlesim/action/RotateAbsolute_FeedbackMessage.idl
  data/ros/turtlesim/action/RotateAbsolute_SendGoal_Request.idl
  data/ros/turtlesim/action/RotateAbsolute_Goal.idl
  data/ros/turtlesim/action/RotateAbsolute_Result.idl
  data/ros/turtlesim/action/RotateAbsolute_SendGoal_Response.idl
  data/ros/turtlesim/action/RotateAbsolute_GetResult_Request.idl
  data/ros/turtlesim/action/RotateAbsolute_Feedback.idl
  data/ros/turtlesim/srv/SetPen_Request.idl
  data/ros/turtlesim/srv/SetPen_Response.idl
  data/ros/turtlesim/srv/Kill_Request.idl
  data/ros/turtlesim/srv/Spawn_Request.idl
  data/ros/turtlesim/srv/TeleportAbsolute_Request.idl
  data/ros/turtlesim/srv/TeleportRelative_Response.idl
  data/ros/turtlesim/srv/Kill_Response.idl
  data/ros/turtlesim/srv/TeleportRelative_Request.idl
  data/ros/turtlesim/srv/TeleportAbsolute_Response.idl
  data/ros/turtlesim/srv/Spawn_Response.idl
)

set(IDL_ROS2_GAZEBO
  # ROS2 data types for the Gazebo simulator
  data/ros/gazebo_msgs/msg/ODEPhysics.idl
  data/ros/gazebo_msgs/msg/ModelStates.idl
  data/ros/gazebo_msgs/msg/ODEJointProperties.idl
  data/ros/gazebo_msgs/msg/ContactsState.idl
  data/ros/gazebo_msgs/msg/ModelState.idl
  data/ros/gazebo_msgs/msg/LinkStates.idl
  data/ros/gazebo_msgs/msg/LinkState.idl
  data/ros/gazebo_msgs/msg/ContactState.idl
  data/ros/gazebo_msgs/msg/WorldState.idl
  data/ros/gazebo_msgs/srv/SpawnModel_Request.idl
  data/ros/gazebo_msgs/srv/Body_Request.idl
  data/ros/gazebo_msgs/srv/GetPhysicsProperties_Response.idl
  data/ros/gazebo_msgs/srv/SetJointProperties_Request.idl
  data/ros/gazebo_msgs/srv/ApplyBodyWrench_Request.idl
  data/ros/gazebo_msgs/srv/ApplyJointEffort_Request.idl
  data/ros/gazebo_msgs/srv/GetLinkProperties_Response.idl
  data/ros/gazebo_msgs/srv/SetPhysicsProperties_Request.idl
  data/ros/gazebo_msgs/srv/SetModelConfiguration_Request.idl
  data/ros/gazebo_msgs/srv/GetJointProperties_Request.idl
  data/ros/gazebo_msgs/srv/SetJointTrajectory_Request.idl
  data/ros/gazebo_msgs/srv/SetModelState_Request.idl
  data/ros/gazebo_msgs/srv/SetLightProperties_Request.idl
  data/ros/gazebo_msgs/srv/GetJointProperties_Response.idl
  data/ros/gazebo_msgs/srv/GetWorldProperties_Response.idl
  data/ros/gazebo_msgs/srv/GetLinkState_Response.idl
  data/ros/gazebo_msgs/srv/GetLightProperties_Request.idl
  data/ros/gazebo_msgs/srv/Default_Response.idl
  data/ros/gazebo_msgs/srv/DeleteModel_Request.idl
  data/ros/gazebo_msgs/srv/GetModelProperties_Request.idl
  data/ros/gazebo_msgs/srv/DeleteLight_Request.idl
  data/ros/gazebo_msgs/srv/GetLinkState_Request.idl
  data/ros/gazebo_msgs/srv/Joint_Request.idl
  data/ros/gazebo_msgs/srv/GetLightProperties_Response.idl
  data/ros/gazebo_msgs/srv/SetLinkProperties_Request.idl
  data/ros/gazebo_msgs/srv/GetModelState_Response.idl
  data/ros/gazebo_msgs/srv/GetModelState_Request.idl
  data/ros/gazebo_msgs/srv/GetModelProperties_Response.idl
  data/ros/gazebo_msgs/srv/GetLinkProperties_Request.idl
  data/ros/gazebo_msgs/srv/SetLinkState_Request.idl
)

set(IDL_ROS2_ASTUFF
  # ROS2 data types from the AutonomouStuff GitHub repository
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ScheduledReportRatesReq.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ConfigureOutputsKpKiCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/PositionReachErrorTimeConfigCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/SoftwareRevisionRpt.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/PositionRpt.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/PriorityConfigCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ActuatorUniqueIdReq.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/EnhancedPositionRpt.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/SoftwareVersionReq.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ResetCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ReportIndex.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ReassignCommandIdCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/MotorOverCurrentConfigCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/MotorCurrentRpt.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ConfigureOutputsPwmFreqCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ReassignReportIdCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ConfigureOutputsKdFreqDeadbandCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/AutoZeroCalCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ReportPollReq.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/PositionCmd.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/UniqueDeviceIdRpt.idl
  data/ros/astuff/astuff_sensor_msgs/kartech_linear_actuator_msgs/msg/ZeroingMessageRpt.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/Lane.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/TsrVisionOnly.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/FixedFoe.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/AftermarketLane.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/AwsDisplay.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/LkaLane.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/LkaNumOfNextLaneMarkersReported.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/AhbcGradual.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/LkaReferencePoints.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/ObstacleStatus.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/Tsr.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/ObstacleData.idl
  data/ros/astuff/astuff_sensor_msgs/mobileye_560_660_msgs/msg/Ahbc.idl
  data/ros/astuff/astuff_sensor_msgs/derived_object_msgs/msg/Lane.idl
  data/ros/astuff/astuff_sensor_msgs/derived_object_msgs/msg/ObjectArray.idl
  data/ros/astuff/astuff_sensor_msgs/derived_object_msgs/msg/ObjectWithCovariance.idl
  data/ros/astuff/astuff_sensor_msgs/derived_object_msgs/msg/ObjectWithCovarianceArray.idl
  data/ros/astuff/astuff_sensor_msgs/derived_object_msgs/msg/Object.idl
  data/ros/astuff/astuff_sensor_msgs/derived_object_msgs/msg/SolidPrimitiveWithCovariance.idl
  data/ros/astuff/astuff_sensor_msgs/derived_object_msgs/msg/LaneModels.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrStatusSwVersion.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrDetection.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrStatusCanVersion.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrHeaderSensorCoverage.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrStatusSerialNumber.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/ActiveFaultLatched2.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/VehicleStateMsg1.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrControlMsgFR.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/VehicleStateMsg2.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrStatusRadar.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrHeaderSensorPosition.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrControlMsgNR.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrHeaderTimestamps.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/VehicleStateMsg3.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrStatusTempVolt.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrHeaderInformationDetections.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/ActiveFaultLatched1.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_mrr_msgs/msg/MrrHeaderAlignmentState.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrDebug5.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrStatus2.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrStatus3.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrTrack.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrStatus5.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrFeatureSwVersion.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrStatus1.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrFeatureAlert.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrDebug4.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrStatus4.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_srr_msgs/msg/SrrDebug3.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ObjectData2225.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Velocity2D.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/DeviceStatus.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanPoint2204.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ObjectData2270.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Size2D.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanPoint2205.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Object2271.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/UntrackedProperties.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Object2270.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Point2Dui.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/HostVehicleState2805.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ErrorWarning.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanData2204.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanPoint2208.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Sigma2D.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Object2221.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/HostVehicleState2806.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/CameraImage.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/MountingPositionF.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Point2Df.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Object2225.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/IbeoDataHeader.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ObjectData2271.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScannerInfo2204.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanData2208.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ObjectData2221.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Point2Di.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ObjectData2280.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/TrackedProperties.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/HostVehicleState2807.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ResolutionInfo.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanData2205.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanPoint2202.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ContourPointSigma.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScanData2202.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/Object2280.idl
  data/ros/astuff/astuff_sensor_msgs/ibeo_msgs/msg/ScannerInfo2205.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus7.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrValid2.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrVehicle5.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrVehicle1.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrEthTx.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus8.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrTrackMotionPowerTrack.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrVehicle2.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus3.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus6.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus9.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus1.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrVehicle4.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus4.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrValid1.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrTrack.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrTrackMotionPowerGroup.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus2.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrStatus5.idl
  data/ros/astuff/astuff_sensor_msgs/delphi_esr_msgs/msg/EsrVehicle3.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/Sensors.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/AnsToCmdConnect.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/AnalogIn.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/Paraset.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/Command.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/AnsParasetToEEPROM.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/SensorData.idl
  data/ros/astuff/astuff_sensor_msgs/neobotix_usboard_msgs/msg/AnsWriteParaset.idl
)
set(IDL_ROS2_CARLA
  # ROS2 data types for the CARLA automotive simulator 
  data/ros/carla/carla_msgs/msg/CarlaWorldInfo.idl
  data/ros/carla/carla_msgs/msg/CarlaWeatherParameters.idl
  data/ros/carla/carla_msgs/msg/CarlaEgoVehicleInfoWheel.idl
  data/ros/carla/carla_msgs/msg/CarlaBoundingBox.idl
  data/ros/carla/carla_msgs/msg/CarlaControl.idl
  data/ros/carla/carla_msgs/msg/CarlaTrafficLightInfo.idl
  data/ros/carla/carla_msgs/msg/CarlaEgoVehicleControl.idl
  data/ros/carla/carla_msgs/msg/CarlaActorInfo.idl
  data/ros/carla/carla_msgs/msg/CarlaLaneInvasionEvent.idl
  data/ros/carla/carla_msgs/msg/CarlaTrafficLightInfoList.idl
  data/ros/carla/carla_msgs/msg/CarlaEgoVehicleStatus.idl
  data/ros/carla/carla_msgs/msg/CarlaActorList.idl
  data/ros/carla/carla_msgs/msg/CarlaWalkerControl.idl
  data/ros/carla/carla_msgs/msg/CarlaStatus.idl
  data/ros/carla/carla_msgs/msg/CarlaTrafficLightStatus.idl
  data/ros/carla/carla_msgs/msg/CarlaEgoVehicleInfo.idl
  data/ros/carla/carla_msgs/msg/CarlaTrafficLightStatusList.idl
  data/ros/carla/carla_msgs/msg/CarlaCollisionEvent.idl
  data/ros/carla/carla_msgs/srv/DestroyObject.idl
  data/ros/carla/carla_msgs/srv/GetBlueprints.idl
  data/ros/carla/carla_msgs/srv/SpawnObject.idl
  data/ros/carla/carla_ros_scenario_runner_types/msg/CarlaScenario.idl
  data/ros/carla/carla_ros_scenario_runner_types/msg/CarlaScenarioList.idl
  data/ros/carla/carla_ros_scenario_runner_types/msg/CarlaScenarioRunnerStatus.idl
  data/ros/carla/carla_ros_scenario_runner_types/srv/ExecuteScenario.idl
  data/ros/carla/carla_waypoint_types/msg/CarlaWaypoint.idl
  data/ros/carla/carla_waypoint_types/srv/GetActorWaypoint.idl
  data/ros/carla/carla_waypoint_types/srv/GetWaypoint.idl
  data/ros/carla/carla_ackermann_msgs/msg/EgoVehicleControlMaxima.idl
  data/ros/carla/carla_ackermann_msgs/msg/EgoVehicleControlCurrent.idl
  data/ros/carla/carla_ackermann_msgs/msg/EgoVehicleControlStatus.idl
  data/ros/carla/carla_ackermann_msgs/msg/EgoVehicleControlInfo.idl
  data/ros/carla/carla_ackermann_msgs/msg/EgoVehicleControlTarget.idl
)

set(IDL_ROS2_LGSVL
  # ROS2 data types for the LGSVL automotive simulator 
  data/ros/lgsvl_msgs/msg/BoundingBox3D.idl
  data/ros/lgsvl_msgs/msg/VehicleStateData.idl
  data/ros/lgsvl_msgs/msg/Detection3D.idl
  data/ros/lgsvl_msgs/msg/Ultrasonic.idl
  data/ros/lgsvl_msgs/msg/CanBusData.idl
  data/ros/lgsvl_msgs/msg/DetectedRadarObject.idl
  data/ros/lgsvl_msgs/msg/Detection2D.idl
  data/ros/lgsvl_msgs/msg/BoundingBox2D.idl
  data/ros/lgsvl_msgs/msg/Detection3DArray.idl
  data/ros/lgsvl_msgs/msg/SignalArray.idl
  data/ros/lgsvl_msgs/msg/Signal.idl
  data/ros/lgsvl_msgs/msg/VehicleControlData.idl
  data/ros/lgsvl_msgs/msg/Detection2DArray.idl
  data/ros/lgsvl_msgs/msg/DetectedRadarObjectArray.idl
  data/ros/lgsvl_msgs/msg/VehicleOdometry.idl
)

# build the list of user-selected type groups to include in the libraries
set(IDLs)
list(FIND TYPES_TO_BUILD "TYPES_RTI_AUTOMOTIVE" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_RTI_AUTOMOTIVE to Library")
  list(APPEND IDLs ${IDL_RTI_AUTOMOTIVE})
  endif()
list(FIND TYPES_TO_BUILD "TYPES_COVESA_VSS" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_COVESA_VSS to Library")
  list(APPEND IDLs ${IDL_COVESA_VSS})
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_CORE" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_CORE to Library")
  list(APPEND IDLs ${IDL_ROS2_CORE})
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_CARLA" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_CARLA to Library")
  list(APPEND IDLs ${IDL_ROS2_CARLA})
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_GAZEBO" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_GAZEBO to Library")
  list(APPEND IDLs ${IDL_ROS2_GAZEBO})
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_LGSVL" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_LGSVL to Library")
  list(APPEND IDLs ${IDL_ROS2_LGSVL})
endif()
list(FIND TYPES_TO_BUILD "TYPES_ROS2_ASTUFF" _idx)
if(${_idx} GREATER -1)
  message(" - Adding group TYPES_ROS2_ASTUFF to Library")
  list(APPEND IDLs ${IDL_ROS2_ASTUFF})
endif()

list(LENGTH IDLs IDLs_length)
math(EXPR length "${IDLs_length}-1")

if (${RTI_CONNEXT_SDK} STREQUAL "pro")
  set(LANGUAGES C C++ C++11)
elseif (${RTI_CONNEXT_SDK} STREQUAL "micro2cert")
  set(LANGUAGES C)
else()
  set(LANGUAGES C C++)
endif()

set(types_lib_list)

foreach(language ${LANGUAGES})

  add_library(${language}_${RTI_CONNEXT_SDK}_types_lib)
  list(APPEND types_lib_list ${language}_${RTI_CONNEXT_SDK}_types_lib)

  foreach(i RANGE ${length})

    list(GET IDLs ${i} idl)
    get_filename_component(idl_relative_location ${idl} DIRECTORY)

    connextdds_rtiddsgen_run(
      IDL_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/${idl}"
      VAR
        codegen_files
      LANG
        ${language}
      OUTPUT_DIRECTORY
        "${CODEGEN_OUTPUT_DIR}/${language}/res/types/${idl_relative_location}"
      INCLUDE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}/../.."
      ${CODEGEN_FLAGS}
    )

    if (${language} STREQUAL "C")
      target_sources(${language}_${RTI_CONNEXT_SDK}_types_lib 
            PRIVATE ${codegen_files_C_SOURCES})
    elseif(${language} STREQUAL "C++")
      target_sources(${language}_${RTI_CONNEXT_SDK}_types_lib 
            PRIVATE ${codegen_files_CXX_SOURCES})
    elseif(${language} STREQUAL "C++11")
      target_sources(${language}_${RTI_CONNEXT_SDK}_types_lib 
            PRIVATE ${codegen_files_CXX11_SOURCES})
    endif()

  endforeach()

  target_include_directories(${language}_${RTI_CONNEXT_SDK}_types_lib
    PUBLIC
      "${CODEGEN_OUTPUT_DIR}/${language}"
  )

  if("${RTI_CONNEXT_SDK}" MATCHES "pro")
      target_include_directories(${language}_${RTI_CONNEXT_SDK}_types_lib
          PUBLIC
          "${RTI_CONNEXT_SDK_DIR}/include"
          "${RTI_CONNEXT_SDK_DIR}/include/ndds"
      )

    if (${language} STREQUAL "C")
      target_link_libraries(${language}_${RTI_CONNEXT_SDK}_types_lib
            RTIConnextDDS::c_api)
    elseif(${language} STREQUAL "C++")
      target_link_libraries(${language}_${RTI_CONNEXT_SDK}_types_lib
            RTIConnextDDS::cpp_api)
    elseif(${language} STREQUAL "C++11")
      target_link_libraries(${language}_${RTI_CONNEXT_SDK}_types_lib
            RTIConnextDDS::cpp2_api)
    endif()

  elseif("${RTI_CONNEXT_SDK}" MATCHES "micro")
    target_link_libraries(${language}_${RTI_CONNEXT_SDK}_types_lib
            RTIConnextDDSMicro::rti_me)
  endif()

  # export targets, so that they can be IMPORTED by other projects (components)
  export(TARGETS ${language}_${RTI_CONNEXT_SDK}_types_lib APPEND 
         FILE ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-exports.cmake
    )
endforeach()

#-----------------------------------------------------------------------------

install(
    TARGETS ${types_lib_list}
    CONFIGURATIONS Debug Release
    RUNTIME DESTINATION "${INSTALL_RUNTIME_OUTPUT_DIRECTORY}"
    ARCHIVE DESTINATION "${INSTALL_ARCHIVE_OUTPUT_DIRECTORY}"
    LIBRARY DESTINATION "${INSTALL_LIBRARY_OUTPUT_DIRECTORY}"
)

#-----------------------------------------------------------------------------
