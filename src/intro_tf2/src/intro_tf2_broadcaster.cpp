#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

class BroadcasterNode
{
public:
  BroadcasterNode()
    : tf2_br_() {}

  void broadcast_robot_pose(double x, double y, double theta)
  {
    geometry_msgs::TransformStamped transform_stamped;

    transform_stamped.header.stamp = ros::Time::now();
    transform_stamped.header.frame_id = "map";
    transform_stamped.child_frame_id = "base_link";
    transform_stamped.transform.translation.x = x;
    transform_stamped.transform.translation.y = y;
    transform_stamped.transform.translation.z = 0.0;
    tf2::Quaternion q;
    q.setRPY(0, 0, theta);
    transform_stamped.transform.rotation.x = q.x();
    transform_stamped.transform.rotation.y = q.y();
    transform_stamped.transform.rotation.z = q.z();
    transform_stamped.transform.rotation.w = q.w();

    tf2_br_.sendTransform(transform_stamped);
  }

  void spin()
  {
    ros::Rate rate(5);
    while (ros::ok())
    {
      broadcast_robot_pose(0,0,0);
      ros::spinOnce();
      rate.sleep();
    }
  }

private:
  tf2_ros::TransformBroadcaster tf2_br_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "tf2_broadcaster_node");
  BroadcasterNode node;
  node.spin();

  return EXIT_SUCCESS;
}
