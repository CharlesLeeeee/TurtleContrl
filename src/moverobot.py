#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import String
import math
import time

x=0
y=0
theta=0

def posecallback(pose_message):
    global x
    global y
    global theta
    x = pose_message.x
    y = pose_message.y
    theta = pose_message.theta

def move(distance_needed):
    pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    sub = rospy.Subscriber("/turtle1/pose", Pose, posecallback)
    vel_msg = Twist()
    vel_msg.linear.x = 10
    loop_rate = rospy.Rate(10)
    x0 = x
    y0 = y
    distance_atm = 0
    
    while distance_atm < distance_needed:    
        pub.publish(vel_msg)
        loop_rate.sleep()
        distance_atm = math.sqrt(((x-x0) ** 2) + ((y-y0) ** 2))
    
    vel_msg.linear.x = 0
    pub.publish(vel_msg)
    sub.unregister()


def rotate(angle):
    pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    sub = rospy.Subscriber("/turtle1/pose", Pose, posecallback)
    vel_msg = Twist()
    angle0 = theta
    angle_needed = angle - angle0
    print(angle_needed)
    angle_moved = 0
    loop_rate = rospy.Rate(100)
    dt = 0.01
    kp = 7.5
    ki=0.5
    kd=0.5
    e_tot = 0
    e_old = 0
    vel_msg.angular.z = 0.2

    while abs(vel_msg.angular.z) >= 0.1:
        e = angle_needed - angle_moved
        e_tot = e_tot + e*dt
        vel_msg.angular.z = kp*e + ki*e_tot + kd*(e - e_old)/dt
        e_old = e
        pub.publish(vel_msg)
        print(angle_moved)
        loop_rate.sleep()
        angle_moved = theta - angle0

    vel_msg.angular.z = 0
    pub.publish(vel_msg)
    sub.unregister()

def main():
    try:
        print("Enter W, A, S, D to move the turtle.")
        rospy.init_node('moverobot', anonymous=True)
        while(True):
            control = raw_input()
            if control == 'd':
                rotate(0)
                move(2)
            elif control == 's':
                rotate(-3.14/2)
                move(2)
            elif control == 'a':
                rotate(3.14)
                move(2)
            elif control == 'w':
                rotate(3.14/2)
                move(2)
            elif control == 'q':
                break
            else:
                print("Please enter an existing command!")

    except rospy.ROSInterruptException:
        rospy.loginfo("node terminated.")
    



if __name__ == '__main__':
    main()