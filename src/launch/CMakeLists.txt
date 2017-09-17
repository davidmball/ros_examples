cmake_minimum_required(VERSION 2.8.3)
project(launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(launch launch/launch.cpp)
target_link_libraries(launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(launch launch/launch.cpp)
target_link_libraries(launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(launch roscpp_tutorials_gencpp)
install(TARGETS launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(launch launch/launch.cpp)
target_link_libraries(launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(launch roscpp_tutorials_gencpp)
install(TARGETS launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(launch launch/launch.cpp)
target_link_libraries(launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(launch roscpp_tutorials_gencpp)
install(TARGETS launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(launch launch/launch.cpp)
target_link_libraries(launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(launch roscpp_tutorials_gencpp)
install(TARGETS launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(launch launch/launch.cpp)
target_link_libraries(launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(launch roscpp_tutorials_gencpp)
install(TARGETS launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch//home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch.cpp)
target_link_libraries(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch roscpp_tutorials_gencpp)
install(TARGETS /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch//home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch.cpp)
target_link_libraries(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch roscpp_tutorials_gencpp)
install(TARGETS /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch//home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch.cpp)
target_link_libraries(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch roscpp_tutorials_gencpp)
install(TARGETS /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)project(AAA)find_package(Boost REQUIRED COMPONENTS date_time thread)find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)include_directories(${catkin_INCLUDE_DIRS})link_directories(${catkin_LIBRARY_DIRS})catkin_package(CATKIN_DEPENDS message_runtime std_msgs)add_executable(AAA AAA/AAA.cpp)target_link_libraries(AAA ${catkin_LIBRARIES} ${Boost_LIBRARIES})add_dependencies(AAA roscpp_tutorials_gencpp)install(TARGETS AAARUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})cmake_minimum_required(VERSION 2.8.3)
project(AAA)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(AAA AAA/AAA.cpp)
target_link_libraries(AAA ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(AAA roscpp_tutorials_gencpp)
install(TARGETS AAA
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)
project(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch//home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch.cpp)
target_link_libraries(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(/home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch roscpp_tutorials_gencpp)
install(TARGETS /home/maurice/catkin_ws2/src/ros_tutorials/roscpp_tutorials/launch
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
cmake_minimum_required(VERSION 2.8.3)project(AAA)find_package(Boost REQUIRED COMPONENTS date_time thread)find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)include_directories(${catkin_INCLUDE_DIRS})link_directories(${catkin_LIBRARY_DIRS})catkin_package(CATKIN_DEPENDS message_runtime std_msgs)add_executable(AAA AAA/AAA.cpp)target_link_libraries(AAA ${catkin_LIBRARIES} ${Boost_LIBRARIES})add_dependencies(AAA roscpp_tutorials_gencpp)install(TARGETS AAARUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})cmake_minimum_required(VERSION 2.8.3)
project(AAA)

find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(AAA AAA/AAA.cpp)
target_link_libraries(AAA ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(AAA roscpp_tutorials_gencpp)
install(TARGETS AAA
RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
