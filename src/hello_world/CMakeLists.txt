cmake_minimum_required(VERSION 2.8.3)
project(hello_world)

find_package(catkin REQUIRED COMPONENTS 
  roscpp
  rosconsole)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS)

add_executable(hello_world src/hello_world.cpp)
target_link_libraries(hello_world ${catkin_LIBRARIES})
install(TARGETS hello_world
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

