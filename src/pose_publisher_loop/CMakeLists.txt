cmake_minimum_required(VERSION 2.8.3)
project(pose_publisher_loop)

find_package(catkin REQUIRED COMPONENTS 
  rostime
  roscpp
  rosconsole
  geometry_msgs)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS)

add_executable(pose_loop src/pose_loop.cpp)
target_link_libraries(pose_loop ${catkin_LIBRARIES})
install(TARGETS pose_loop
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

