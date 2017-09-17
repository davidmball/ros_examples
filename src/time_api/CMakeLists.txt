cmake_minimum_required(VERSION 2.8.3)
project(time_api)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(time_api time_api/time_api.cpp)
target_link_libraries(time_api ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS time_api
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
add_subdirectory(sleep)

