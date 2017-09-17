cmake_minimum_required(VERSION 2.8.3)
project(add_two_ints_server)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

add_service_files(DIRECTORY srv FILES TwoInts.srv)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(add_two_ints_server add_two_ints_server.cpp)
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS add_two_ints_server
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
