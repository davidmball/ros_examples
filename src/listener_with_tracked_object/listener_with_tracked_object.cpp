/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <boost/shared_ptr.hpp>

/**
 * This tutorial demonstrates a tracked object on a subscription.
 */

class Object
{
public:
  void chatterCallback(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO("This should never be printed: [%s]", msg->data.c_str());
  }
};
typedef boost::shared_ptr<Object> ObjectPtr;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Only this version should print: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  ObjectPtr obj(new Object);
  ros::Subscriber sub = n.subscribe("chatter", 1, &Object::chatterCallback, obj);
  ros::Subscriber sub2 = n.subscribe("chatter", 1, chatterCallback);

  // Delete the object.
  // Because we've passed in the object to be tracked as a shared pointer,
  // this is safe.  The callback inside the Object class should never get called,
  // because its pointer is no longer valid.
  obj.reset();

  ros::spin();

  return 0;
}
