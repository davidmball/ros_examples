cmake_minimum_required(VERSION 2.8.3)
project(image_transport_snippets)

add_definitions(-std=c++11)
find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  image_geometry
  roscpp
  tf2_ros
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(camera_subscriber_snippet src/camera_subscriber_snippet.cpp)
target_link_libraries(camera_subscriber_snippet ${catkin_LIBRARIES})

## Install C++ Examples
install(TARGETS camera_subscriber_snippet
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Install Other Resources
install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
