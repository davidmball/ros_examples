/*
 * Copyright (C) 2010, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

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
