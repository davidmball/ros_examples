cmake_minimum_required(VERSION 2.8.3)
project(intro_publisher_subscriber)

find_package(catkin REQUIRED COMPONENTS 
  rostime
  roscpp
  rosconsole)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS)

add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})

add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})

install(TARGETS subscriber publisher
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

