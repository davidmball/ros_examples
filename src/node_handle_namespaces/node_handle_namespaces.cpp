/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial shows the use of NodeHandle namespaces.
 */

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node_handle_namespaces");

  /**
   * Each NodeHandle can be assigned a namespace the same way every node can be assigned
   * a namespace (this is usually done through the environment variable ROS_NAMESPACE).
   *
   * A namespace per NodeHandle allows you to separate different pieces of your application
   * into different namespaces.
   */
  ros::NodeHandle node1("level1");
  std::string s = node1.resolveName("a");
  /// This prints /level1/a
  ROS_INFO_STREAM(s);

  /**
   * If another NodeHandle is provided as the first argument to the constructor, it uses
   * that NodeHandle's namespace as a parent namespace.  Therefore, this NodeHandle will be
   * in the /level1/level2 namespace.
   */
  ros::NodeHandle node2(node1, "level2");
  s = node2.resolveName("a");
  /// This prints /level1/level2/a
  ROS_INFO_STREAM(s);

  /**
   * Accessing private names (inside the nodes' name) is possible by creating a NodeHandle whose name starts with a
   * tilde (~).
   */
  ros::NodeHandle node3("~");
  s = node3.resolveName("a");
  /// This prints /node_handle_namespaces/a
  ROS_INFO_STREAM(s);

  return 0;
}
