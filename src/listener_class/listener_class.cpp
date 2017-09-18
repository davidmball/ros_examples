/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial demonstrates subscribing to a topic using a class method as the callback.
 */

class Listener
{
public:
  void callback(const std_msgs::String::ConstPtr& msg);
};

void Listener::callback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_class");
  ros::NodeHandle n;

  Listener listener;
  ros::Subscriber sub = n.subscribe("chatter", 1000, &Listener::callback, &listener);

  ros::spin();

  return 0;
}
