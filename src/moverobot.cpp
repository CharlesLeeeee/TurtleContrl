#include "ros/ros.h"
#include <stdio.h>
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>

using namespace std;

namespace states{
    ros::Publisher move;
    ros::Subscriber state;
    turtlesim::Pose pose;
} 


void PoseCallBack(const turtlesim::Pose::ConstPtr & PoseMessage);
void rotate(double desired_angle);
void go(double distance);


int main(int argc, char **argv)
{
    ros::init(argc, argv, "moverobot");
    ros::NodeHandle n;
    states::move = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    states::state = n.subscribe("/turtle1/pose", 1000, PoseCallBack);
    ROS_INFO("Use W,A,S,D to move the turtle \n");
    
    
    string direction;  

    while(true){

        system ("/bin/stty raw");
        direction = getchar();
        
        if (direction == "w"){
            rotate(3.14159/2);
            go(2);
        }
        else if (direction == "d"){
            rotate(0);
            go(2);
        }
        else if (direction == "s"){
            rotate(-3.14159/2);
            go(2);
        }
        else if (direction == "a"){
            rotate(3.14159);
            go(2);
        }
        else if (direction == "q"){
            break;
        }
        else {
            ROS_INFO("Please enter valid keys \n");
        }    
    }
    return 0;
}

// y=11, y=0, x=0, x=11
void PoseCallBack(const turtlesim::Pose::ConstPtr & PoseMessage){
    states::pose.x = PoseMessage->x;
    states::pose.y = PoseMessage->y;
    states::pose.theta = PoseMessage->theta;
}

void rotate(double desired_angle){
    geometry_msgs::Twist vel_msg;
    ros::Rate loop_rate(1000);
    vel_msg.linear.x = 0;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;
    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = 0.2;

    double angle_moved = 0;
    double theta0 = states::pose.theta;
    double kp = 5;
    double ki = 0.5;
    double kd = 0.5;
    double dt = 0.01;
    double e;
    double e_old = 0;
    double e_tot = 0;

    
    double angle_needed = desired_angle - theta0;

        while((std::abs(vel_msg.angular.z) >= 0.1) ^ (e < 6.2) == 0){
            e = angle_needed - angle_moved;
            e_tot += e * dt; 
            vel_msg.angular.z = kp*e + ki*e_tot + kd*(e - e_old)/dt;
	        states::move.publish(vel_msg);
            angle_moved = states::pose.theta - theta0;
            ros::spinOnce();
	        loop_rate.sleep();
        }

    vel_msg.angular.z = 0;
    states::move.publish(vel_msg);
}

void go(double distance){
    ros::Rate loop_rate(1000);
    geometry_msgs::Twist vel_msg;
    double x0 = states::pose.x;
    double y0 = states::pose.y;
    vel_msg.linear.x = 10;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;
    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = 0;
    
    double distance_moved = 0;

    while (distance_moved < distance){
        states::move.publish(vel_msg);
        ros::spinOnce();
	    loop_rate.sleep();
        distance_moved = sqrt(pow(states::pose.x-x0,2) + pow(states::pose.y-y0,2));
    }
    
    vel_msg.linear.x = 0;
    states::move.publish(vel_msg); 
}
