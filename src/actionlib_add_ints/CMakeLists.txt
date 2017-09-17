# Originally from: https://github.com/ros/actionlib/blob/indigo-devel/CMakeLists.txt
cmake_minimum_required(VERSION 2.8.3)
project(actionlib_add_ints)

find_package(catkin REQUIRED COMPONENTS actionlib_msgs message_generation roscpp std_msgs)
find_package(Boost REQUIRED COMPONENTS thread)

include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

add_action_files(DIRECTORY action FILES TwoInts.action)
generate_messages(DEPENDENCIES actionlib_msgs std_msgs)

catkin_package(
  LIBRARIES actionlib
  CATKIN_DEPENDS actionlib_msgs message_runtime roscpp std_msgs
  DEPENDS Boost
)

add_executable(server src/add_two_ints_server.cpp)
add_dependencies(server actionlib_add_ints_generate_messages_cpp ${catkin_EXPORTED_TARGETS})
target_link_libraries(server actionlib ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(client src/add_two_ints_client.cpp)
add_dependencies(client actionlib_add_ints_generate_messages_cpp ${catkin_EXPORTED_TARGETS} )
target_link_libraries(client actionlib ${catkin_LIBRARIES} ${Boost_LIBRARIES})

install(TARGETS server client
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})

