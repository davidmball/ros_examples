cmake_minimum_required(VERSION 2.8.3)
project(intro_publisher_loop)

find_package(catkin REQUIRED COMPONENTS 
  rostime
  roscpp
  rosconsole)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS)

add_executable(chatter src/chatter.cpp)
target_link_libraries(chatter ${catkin_LIBRARIES})
install(TARGETS chatter
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

