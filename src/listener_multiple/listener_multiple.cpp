/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system, with
 * multiple callbacks for the same topic.  See the "listener" tutorial for more
 * information.
 */

class Listener
{
public:
  void chatter1(const std_msgs::String::ConstPtr& msg) { ROS_INFO("chatter1: [%s]", msg->data.c_str()); }
  void chatter2(const std_msgs::String::ConstPtr& msg) { ROS_INFO("chatter2: [%s]", msg->data.c_str()); }
  void chatter3(const std_msgs::String::ConstPtr& msg) { ROS_INFO("chatter3: [%s]", msg->data.c_str()); }
};

void chatter4(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("chatter4: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  Listener l;
  ros::Subscriber sub1 = n.subscribe("chatter", 10, &Listener::chatter1, &l);
  ros::Subscriber sub2 = n.subscribe("chatter", 10, &Listener::chatter2, &l);
  ros::Subscriber sub3 = n.subscribe("chatter", 10, &Listener::chatter3, &l);
  ros::Subscriber sub4 = n.subscribe("chatter", 10, chatter4);

  ros::spin();

  return 0;
}

