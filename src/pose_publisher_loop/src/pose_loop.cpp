// Copyright (c) 2017, David Ball
// License: BSD 3-clause. (See LICENSE file.)

#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_loop");
  ros::NodeHandle nh;

  ros::Publisher pose_pub = nh.advertise<geometry_msgs::PoseStamped>(std::string("robot_pose"), 1000);

  geometry_msgs::PoseStamped msg;
  msg.pose.position.x = 0;
  msg.pose.position.y = 0;
  msg.pose.position.z = 0;
  msg.pose.orientation.x = 0;
  msg.pose.orientation.y = 0;
  msg.pose.orientation.z = 0;
  msg.pose.orientation.w = 1;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    msg.header.stamp == ros::Time::now();
    msg.header.frame_id = std::string("the_frame");

    msg.pose.position.x += 1.0;

    pose_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return EXIT_SUCCESS;
}
