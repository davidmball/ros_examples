/* From https://github.com/ros/ros_tutorials. See LICENSE file for license information. */
#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "parameters");
  ros::NodeHandle n;

  {
    std::string s;
    n.getParam("my_param", s);
  }

  {
    std::string s;
    if (n.getParam("my_param", s))
    {
      ROS_INFO("Got param: %s", s.c_str());
    }
    else
    {
      ROS_ERROR("Failed to get param 'my_param'");
    }
  }

  int i;
  n.param("my_num", i, 42);

  std::string s;
  n.param<std::string>("my_param", s, "default_value");

  n.setParam("my_param", "hello there");

  n.deleteParam("my_param");

  if (!n.hasParam("my_param"))
  {
    ROS_INFO("No param named 'my_param'");
  }

  std::string param_name;
  if (n.searchParam("b", param_name))
  {
    // Found parameter, can now query it using param_name
    int i = 0;
    n.getParam(param_name, i);
  }
  else
  {
    ROS_INFO("No param 'b' found in an upward search");
  }
}
