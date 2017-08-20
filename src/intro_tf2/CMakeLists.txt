cmake_minimum_required(VERSION 2.8.3)
project(intro_tf2)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs tf2 tf2_ros
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(intro_tf2_broadcaster src/intro_tf2_broadcaster.cpp)
target_link_libraries(intro_tf2_broadcaster ${catkin_LIBRARIES})
if(catkin_EXPORTED_TARGETS)
  add_dependencies(intro_tf2_broadcaster ${catkin_EXPORTED_TARGETS})
endif()

add_executable(intro_tf2_listener src/intro_tf2_listener.cpp)
target_link_libraries(intro_tf2_listener ${catkin_LIBRARIES})
if(catkin_EXPORTED_TARGETS)
  add_dependencies(intro_tf2_listener ${catkin_EXPORTED_TARGETS})
endif()

## Install Python Examples
#install(PROGRAMS
#  nodes/dynamic_tf2_broadcaster.py
#  nodes/fixed_tf2_broadcaster.py
#  nodes/intro_tf2_broadcaster.py
#  nodes/intro_tf2_listener.py
#  nodes/intro_tf2_listener_wait.py
#  nodes/intro_tf2_message_broadcaster.py
#  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

## Install C++ Examples
install(TARGETS intro_tf2_broadcaster intro_tf2_listener
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Install Other Resources
install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
