#!/usr/bin/env python
import rospy

# Because of transformations
import tf

import tf2_ros
import geometry_msgs.msg


class BroadcasterNode(object):
    def __init__(self):
        self._tf2_br = tf2_ros.TransformBroadcaster()

    def broadcast_robot_pose(self, x, y, theta):
        t = geometry_msgs.msg.TransformStamped()

        t.header.stamp = rospy.Time.now()
        t.header.frame_id = "map"
        t.child_frame_id = "base_link"
        t.transform.translation.x = x
        t.transform.translation.y = y
        t.transform.translation.z = 0.0
        q = tf.transformations.quaternion_from_euler(0, 0, theta)
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]

        self._tf2_br.sendTransform(t)

    def spin(self):
        rate = rospy.Rate(5)
        while not rospy.is_shutdown():
            self.broadcast_robot_pose(0,0,0);
            rate.sleep()

if __name__ == '__main__':
    rospy.init_node('tf2_broadcaster_node')
    node = BroadcasterNode()
    node.spin()
