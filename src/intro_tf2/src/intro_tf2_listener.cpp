#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

class ListenerNode
{
public:
  ListenerNode()
    : source_frame_("base_link") //
    , target_frame_("map")
  { }

  bool configure()
  {
    tf2_buffer_.reset(new tf2_ros::Buffer);
    tf2_listener_.reset(new tf2_ros::TransformListener(*tf2_buffer_));
    return true;
  }

  void get_robot_pose(const ros::Time& stamp = ros::Time(0))
  {
    tf2::Transform tf; // useful if you want to work with your transform
    try
    {
      tf2::fromMsg( // convert geometry_msgs::Transform to tf2::Transform
        tf2_buffer_->lookupTransform(
          target_frame_,
          source_frame_,
          stamp).transform,
        tf);
    }
    catch (tf2::TransformException &ex)
    {
      ROS_WARN_THROTTLE(1, "%s", ex.what());
      return;
    }
    ROS_INFO_STREAM(tf.getOrigin().x() << " " <<
                    tf.getOrigin().y() << " " <<
                    tf.getOrigin().z());
  }

  void spin()
  {
    ros::Rate rate(2);
    while (ros::ok())
    {
      get_robot_pose();
      ros::spinOnce();
      rate.sleep();
    }
  }

private:
  boost::shared_ptr<tf2_ros::Buffer> tf2_buffer_;
  boost::shared_ptr<tf2_ros::TransformListener> tf2_listener_;
  std::string source_frame_, target_frame_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "tf2_listener_node");
  ListenerNode node;
  node.configure();
  node.spin();

  return EXIT_SUCCESS;
}
