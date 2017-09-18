/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <boost/thread.hpp>

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system, using
 * an asynchronous Spinner object to receive callbacks in multiple threads at the same time.
 */

ros::Duration d(0.01);

class Listener
{
public:
  void chatter1(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO_STREAM("chatter1: [" << msg->data << "] [thread=" << boost::this_thread::get_id() << "]");
    d.sleep();
  }
  void chatter2(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO_STREAM("chatter2: [" << msg->data << "] [thread=" << boost::this_thread::get_id() << "]");
    d.sleep();
  }
  void chatter3(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO_STREAM("chatter3: [" << msg->data << "] [thread=" << boost::this_thread::get_id() << "]");
    d.sleep();
  }
};

void chatter4(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO_STREAM("chatter4: [" << msg->data << "] [thread=" << boost::this_thread::get_id() << "]");
  d.sleep();
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

  /**
   * The AsyncSpinner object allows you to specify a number of threads to use
   * to call callbacks.  If no explicit # is specified, it will use the # of hardware
   * threads available on your system.  Here we explicitly specify 4 threads.
   */
  ros::AsyncSpinner s(4);
  s.start();

  ros::Rate r(5);
  while (ros::ok())
  {
    ROS_INFO_STREAM("Main thread [" << boost::this_thread::get_id() << "].");
    r.sleep();
  }

  return 0;
}

