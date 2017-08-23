// Copyright (c) Author: Eitan Marder-Eppstein
// License: BSD 3-clause. (See LICENSE file.)
// https://github.com/ros/actionlib/blob/indigo-devel/test/add_two_ints_client.cpp
#include <ros/ros.h>
#include <actionlib/server/service_server.h>
#include <actionlib_add_ints/TwoIntsAction.h>

bool add(const actionlib_add_ints::TwoIntsGoal & req, actionlib_add_ints::TwoIntsResult & res)
{
  res.sum = req.a + req.b;
  ROS_INFO("Server request from client: x=%ld, y=%ld", (int64_t)req.a, (int64_t)req.b);
  ROS_INFO("Server sending back response: [%ld]", (int64_t)res.sum);
  return true;
}

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  actionlib::ServiceServer service = actionlib::advertiseService<actionlib_add_ints::TwoIntsAction>(n,
      "add_two_ints",
      boost::bind(add, _1, _2));

  ros::spin();

  return 0;
}
