// Copyright (c) 2017, David Ball
// License: BSD 3-clause. (See LICENSE file.)

#include "ros/ros.h"
#include "std_msgs/String.h"

void cbChatter(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO_NAMED("subscriber", "Received: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh;

  ros::Subscriber chatter_sub = nh.subscribe(std::string("chatter"), 1000, cbChatter);

  ros::Rate loop_rate(10);

  ros::spin();

  return EXIT_SUCCESS;
}
