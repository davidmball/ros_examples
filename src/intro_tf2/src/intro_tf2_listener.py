#!/usr/bin/env python
import rospy

import tf
import tf2_ros

class ListenerNode(object):
    def __init__(self):
        self._source_frame = 'base_link'
        self._target_frame = 'map'

    def configure(self):
        self._tf2_buffer = tf2_ros.Buffer()
        self._tf2_listener = tf2_ros.TransformListener(self._tf2_buffer)
        return True;

    def get_robot_pose(self, stamp=rospy.Time(0)):
        try:
            tf = self._tf2_buffer.lookup_transform(
                self._target_frame,
                self._source_frame,
                stamp).transform
        except tf2_ros.TransformException as ex:
            rospy.logwarn_throttle(1, '%s' % ex)
            return

        rospy.loginfo("%s %s %s" % (tf.translation.x,
                                    tf.translation.y,
                                    tf.translation.z))

    def spin(self):
        rate = rospy.Rate(2)
        while not rospy.is_shutdown():
            self.get_robot_pose()
            rate.sleep()


if __name__ == '__main__':
    rospy.init_node('tf2_listener_node')
    node = ListenerNode()
    node.configure()
    node.spin()
