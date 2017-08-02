cmake_minimum_required(VERSION 2.8.3)
project(intro_marker_publisher)

find_package(catkin REQUIRED COMPONENTS 
  roscpp
  visualization_msgs)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS 
  roscpp
  visualization_msgs)

add_executable(marker_publisher src/marker_publisher.cpp)
target_link_libraries(marker_publisher ${catkin_LIBRARIES})
install(TARGETS marker_publisher
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

