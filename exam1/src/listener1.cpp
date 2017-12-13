#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include "turtlesim/Pose.h"
#include <iostream>
ros::Publisher pub;
ros::Subscriber pose_subscriber;
ros::Subscriber UI;

using namespace std;

const double PI =3.14159265359;

bool done = false;
int xr;	// x coordinate of the turtle in turtlesim
int yr;	// y coordinate of the turtle in turtlesim
int dr;	// looking direction of the turtle in turtlesim
int ans;
void cirkle();
void square();
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
	xr = msg->x;
	yr = msg->y;
	dr = ((msg->theta*180)/PI)*100;
  ROS_INFO("x: [%i], y: [%i] looking: [%i]", xr, yr, dr);



}
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ans = msg->x;
  ROS_INFO("I heard:[%i]", ans);



}
  int main(int argc, char**argv){
  ros::init(argc, argv, "publish_velocity");


  ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("Commands", 1000, chatterCallback);
  pose_subscriber = n.subscribe("/turtle1/pose",100 , poseCallback);
  pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  ros::Rate rate(10);
  while(ros::ok()){

if(ans == 1) {
cirkle();
}
else if(ans == 2){
 square();
}
else

  ros::spinOnce();
  rate.sleep();
  }
return 0;
};

	void cirkle(){
 	while (dr < 35900) {


			geometry_msgs::Twist msg;
			msg.linear.x = 1;
			msg.angular.z = 1;
			pub.publish(msg);
			ros::spinOnce();
		}
return;
};


	void square(){
bool d= false;

		for(int i = 0; 1 > i; i++) {
ros::Rate rate(10);

				while(xr != 10 && done ==false) {
					geometry_msgs::Twist msg;
					msg.linear.x = 1;
					pub.publish(msg);
					ros::spinOnce();
				}

				while(dr <= 9000 && done == false)  {
					geometry_msgs::Twist msg;
					msg.angular.z = 0.3;
					pub.publish(msg);
					ros::spinOnce();
				}

				while(yr != 10 && done == false) {
					geometry_msgs::Twist msg;
					msg.linear.x = 1;
					pub.publish(msg);
					ros::spinOnce();
				}
				while(dr <= 18000 && done == false)  {
					geometry_msgs::Twist msg;
					msg.angular.z = 0.3;
					pub.publish(msg);
					ros::spinOnce();
				}
				while(xr != 2 && done == false) {
					geometry_msgs::Twist msg;
					msg.linear.x = 1;
					pub.publish(msg);
					ros::spinOnce();
				}
				while(dr <= 27000 && done == false)  {
					geometry_msgs::Twist msg;
					msg.angular.z = 0.3;
					pub.publish(msg);
					ros::spinOnce();
				}
				while(yr != 2 && done == false) {
					geometry_msgs::Twist msg;
					msg.linear.x = 1;
					pub.publish(msg);
					ros::spinOnce();
				}
				while(dr <= 35979 && done == false)  {
					geometry_msgs::Twist msg;
					msg.angular.z =0.2;
					pub.publish(msg);
					ros::spinOnce();
				}
				while(xr != 10 && done == false) {
					geometry_msgs::Twist msg;
					msg.linear.x = 1;
					pub.publish(msg);
					ros::spinOnce();
				}
				while( dr < 8990 || dr > 9020 && done == false)  {
					geometry_msgs::Twist msg;
					msg.angular.z =0.3;
					pub.publish(msg);
					ros::spinOnce();
				}
				while(yr != 5 )  {
					geometry_msgs::Twist msg;
					msg.linear.x =1;
					pub.publish(msg);
					ros::spinOnce();

			  }
				rate.sleep();
				d = true;
		}
return;
};
