// Copyright (c) 2017, David Ball
// License: BSD 3-clause. (See LICENSE file.)

#include "ros/ros.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "hello_world");
  ros::NodeHandle n;

  ROS_DEBUG("Hello world! (debug)"); // won't appear
  ROS_INFO("Hello world! (info)");
  ROS_WARN("Hello world! (warn)");
  ROS_ERROR("Hello world! (error)");

  return EXIT_SUCCESS;
}
