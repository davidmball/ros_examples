// Copyright (c) 2017 David Ball
// License: BSD 3-clause. (See LICENSE file.)
// Author: Eitan Marder-Eppstein
// https://github.com/ros/actionlib/blob/indigo-devel/test/add_two_ints_client.cpp
#include <ros/ros.h>
#include <actionlib/client/service_client.h>
#include <actionlib_add_ints/TwoIntsAction.h>

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "add_two_ints_client");

  ros::NodeHandle nh;
  actionlib::ServiceClient client = actionlib::serviceClient<actionlib_add_ints::TwoIntsAction>(nh,
                                      "add_two_ints");

  client.waitForServer();

  actionlib_add_ints::TwoIntsGoal req;
  actionlib_add_ints::TwoIntsResult resp;
  req.a = 42;
  req.b = 8;

  sleep(6); // provide some time for the web client to connect to the topic

  if (client.call(req, resp))
  {
    ROS_INFO("Client: Sum = %ld", (int64_t)resp.sum);
    return EXIT_SUCCESS;
  }
  else
  {
    ROS_INFO("Client: Action service client failed");
    return EXIT_SUCCESS;
  }
}
