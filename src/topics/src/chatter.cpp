// Copyright (c) 2017, David Ball
// License: BSD 3-clause. (See LICENSE file.)

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "babbler");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>(std::string("chatter"), 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = std::string("Hello World!");
    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
