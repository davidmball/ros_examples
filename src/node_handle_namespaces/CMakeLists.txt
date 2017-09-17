cmake_minimum_required(VERSION 2.8.3)
project(node_handle_namespaces)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(node_handle_namespaces node_handle_namespaces.cpp)
target_link_libraries(node_handle_namespaces ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS node_handle_namespaces
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
