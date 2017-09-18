/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

/**
 * This tutorial demonstrates how to get a callback when a new subscriber connects
 * to an advertised topic, or a subscriber disconnects.
 */

uint32_t g_count = 0;

void chatterConnect(const ros::SingleSubscriberPublisher& pub)
{
  std_msgs::String msg;
  std::stringstream ss;
  ss << "chatter connect #" << g_count++;
  ROS_INFO("%s", ss.str().c_str());
  msg.data = ss.str();

  pub.publish(msg);  // This message will get published only to the subscriber that just connected
}

void chatterDisconnect(const ros::SingleSubscriberPublisher&)
{
  ROS_INFO("chatter disconnect");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "notify_connect");
  ros::NodeHandle n;

  /**
   * This version of advertise() optionally takes a connect/disconnect callback
   */
  ros::Publisher pub = n.advertise<std_msgs::String>("chatter", 1000, chatterConnect, chatterDisconnect);

  ros::spin();

  return 0;
}

