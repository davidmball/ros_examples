/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial demonstrates a simple use of Boost.Bind to pass arbitrary data into a subscription
 * callback.  For more information on Boost.Bind see the documentation on the boost homepage,
 * http://www.boost.org/
 */


class Listener
{
public:
  ros::NodeHandle node_handle_;
  ros::V_Subscriber subs_;

  Listener(const ros::NodeHandle& node_handle)
  : node_handle_(node_handle)
  {
  }

  void init()
  {
    subs_.push_back(node_handle_.subscribe<std_msgs::String>("chatter", 1000, boost::bind(&Listener::chatterCallback, this, _1, "User 1")));
    subs_.push_back(node_handle_.subscribe<std_msgs::String>("chatter", 1000, boost::bind(&Listener::chatterCallback, this, _1, "User 2")));
    subs_.push_back(node_handle_.subscribe<std_msgs::String>("chatter", 1000, boost::bind(&Listener::chatterCallback, this, _1, "User 3")));
  }

  void chatterCallback(const std_msgs::String::ConstPtr& msg, std::string user_string)
  {
    ROS_INFO("I heard: [%s] with user string [%s]", msg->data.c_str(), user_string.c_str());
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_with_userdata");
  ros::NodeHandle n;

  Listener l(n);
  l.init();

  ros::spin();

  return 0;
}
