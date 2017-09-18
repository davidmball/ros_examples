/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial demonstrates simplified syntax for receiving a single message on a topic.  This is generally only useful for latched topics, as the overhead of subscribing to a topic is relatively significant
 */

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line. For programmatic
   * remappings you can use a different version of init() which takes remappings
   * directly, but for most command-line programs, passing argc and argv is the easiest
   * way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "listener_single_message");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  std_msgs::StringConstPtr msg = ros::topic::waitForMessage<std_msgs::String>("chatter");

  ROS_INFO("Received message [%s]", msg->data.c_str());

  return 0;
}
