#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <image_geometry/pinhole_camera_model.h>
#include <cv_bridge/cv_bridge.h>

class CameraSubscriberNode
{
public:
  CameraSubscriberNode(const ros::NodeHandle& nh=ros::NodeHandle(),
                       const ros::NodeHandle& nh_private=ros::NodeHandle("~"))
    : active_(false)
    , nh_(nh)
    , nh_priv_(nh_private)
  {}

  // We follow the design for managed nodes:
  // http://design.ros2.org/articles/node_lifecycle.html
  bool configure();
  bool cleanup();
  bool activate();
  bool deactivate();

  void imageCb(const sensor_msgs::ImageConstPtr& img_msg,
               const sensor_msgs::CameraInfoConstPtr& info_msg);

private:
  bool active_;

  ros::NodeHandle nh_;
  ros::NodeHandle nh_priv_;
  std::unique_ptr<image_transport::ImageTransport> it_;
  image_transport::CameraSubscriber sub_img_;
  image_transport::Publisher pub_img_;
  image_geometry::PinholeCameraModel camera_model_;
};

// Definitions

bool CameraSubscriberNode::configure()
{
  it_.reset( new image_transport::ImageTransport(nh_) );
  sub_img_ = it_->subscribeCamera("image_input", 5, &CameraSubscriberNode::imageCb, this);
  pub_img_ = it_->advertise("image_output", 1);

  return true;
}

bool CameraSubscriberNode::cleanup()
{
  sub_img_.shutdown();
  it_.reset();

  return true;
}

bool CameraSubscriberNode::activate()
{
  return active_ = true;
}

bool CameraSubscriberNode::deactivate()
{
  return !(active_ = false);
}

void CameraSubscriberNode::imageCb(
  const sensor_msgs::ImageConstPtr& img_msg,
  const sensor_msgs::CameraInfoConstPtr& info_msg)
{
  if (!active_) return;

  camera_model_.fromCameraInfo(info_msg);
  // do somthing read only
  const cv::Mat img = cv_bridge::toCvShare(img_msg)->image;
  // ..

  // modifiy the image
  cv::Mat img_modified;
  img.copyTo(img_modified);
  pub_img_.publish(
    cv_bridge::CvImage(
      img_msg->header,
      img_msg->encoding,
      img_modified).toImageMsg());
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "camera_subscriber_node");
  CameraSubscriberNode node;
  // because there is no lifecycle manager, we need to trigger
  // transitions manually
  node.configure();
  node.activate();
  ros::spin();
}
