#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

class ListenerNode
{
public:
  ListenerNode() {}

  bool init(const ros::NodeHandle& nh_priv = ros::NodeHandle("~"))
  {
    tf2_buffer_.reset(new tf2_ros::Buffer);
    tf2_listener_.reset(new tf2_ros::TransformListener(*tf2_buffer_));
    nh_priv.param<std::string>("robot_frame_id", source_frame_, "base_link");
    nh_priv.param<std::string>("world_frame_id", target_frame_, "map");
    return true;
  }

  bool cleanup()
  {
    tf2_listener_.reset();
    tf2_buffer_.reset();
    return true;
  }

  void get_robot_pose(const ros::Time& stamp = ros::Time(0))
  {
    tf2::Transform tf; // Transform class is good for calculating stuff
    try
    {
      tf2::fromMsg(
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
    tf2::Vector3 origin = tf * tf2::Vector3(0,0,0);
    ROS_INFO_STREAM(origin.x() << " " << origin.y() << " " << origin.z());
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

int main(int argc, char** argv){
  ros::init(argc, argv, "tf2_listener_node");
  ListenerNode node;
  node.init();
  node.spin();

  return EXIT_SUCCESS;
}
