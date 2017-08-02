// Copyright (c) 2017, David Ball
// License: BSD 3-clause. (See LICENSE file.)
// Inspirations from https://github.com/ros-visualization/visualization_tutorials/blob/kinetic-devel/visualization_marker_tutorials/src/basic_shapes.cpp

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "marker_publisher");
  ros::NodeHandle nh;

  ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("markers", 1);

  visualization_msgs::Marker marker;
  marker.header.frame_id = "/the_frame";
  marker.ns = "shape_namespace";
  marker.id = 0;
  marker.type = visualization_msgs::Marker::ARROW;
  marker.pose.position.x = 0;
  marker.pose.position.y = 0;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;
  marker.scale.x = 1.0;
  marker.scale.y = 1.0;
  marker.scale.z = 1.0;
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;
  marker.lifetime = ros::Duration();

  marker.action = visualization_msgs::Marker::ADD;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    marker.header.stamp = ros::Time::now();
    marker.pose.position.x += 0.015;

    marker_pub.publish(marker);

    loop_rate.sleep();
  }
}
