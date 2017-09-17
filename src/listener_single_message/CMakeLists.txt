cmake_minimum_required(VERSION 2.8.3)
project(listener_single_message)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(listener_single_message listener_single_message.cpp)
target_link_libraries(listener_single_message ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS listener_single_message
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
