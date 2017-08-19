#!/usr/bin/env python
# Copyright (c) 2017, David Ball
# License: BSD 3-clause. (See LICENSE file.)
import rospy

def hello_world():
  rospy.init_node('hello_world', anonymous=True)
  rospy.sleep(1.0)
  rospy.logdebug("Hello world! (debug)") # Won't be displayed
  rospy.logwarn("Hello world! (warn)")
  rospy.loginfo("Hello world! (info)")
  rospy.logerr("Hello world! (error)")
  rospy.logfatal("Hello world! (fatal)")

if __name__ == '__main__':
  hello_world()
