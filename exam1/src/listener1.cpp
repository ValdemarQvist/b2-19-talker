#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>

using namespace std;

ros::Publisher pub;
ros::Publisher pub1;
ros::Subscriber pose_subscriber;
ros::Subscriber UI_sub;

const double PI =3.14159265359;

bool done = false;
int xr;	// x coordinate of the turtle in turtlesim
int yr;	// y coordinate of the turtle in turtlesim
int dr;	// looking direction of the turtle in turtlesim
string ans;

void randomwalk();
void cirkle();
void square();
void needNew(){

	std_msgs::String msg;
	stringstream ss;
	ss << "I'am ready for your commad";
	msg.data = ss.str();
	pub1.publish(msg);
	ros::spinOnce();
	return;
}
void moving(){

	std_msgs::String msg;
	stringstream ss;
	ss << "I'am moving";
	msg.data = ss.str();
	pub1.publish(msg);
	ros::spinOnce();
	return;
}

void poseCallback(const turtlesim::Pose::ConstPtr& msg){
	xr = msg->x;
	yr = msg->y;
	dr = ((msg->theta*180)/PI)*100;
  ROS_INFO("x: [%i], y: [%i] looking: [%i]", xr, yr, dr);



}


void chatterCallback(const std_msgs::String::ConstPtr& data){
	ans = data->data;
  ROS_INFO("I heard:[%s]", ans);
}
int main(int argc, char**argv){

	ros::init(argc, argv, "publish_velocity");

	ros::NodeHandle n;

	UI_sub = n.subscribe("Commands", 1000, chatterCallback);
  pose_subscriber = n.subscribe("/turtle1/pose",100 , poseCallback);
  pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  pub1 = n.advertise<std_msgs::String>("Done", 1);

	if(ans == "1") {
		cirkle();
	}
	else if(ans == "2"){
 		square();
	}
	else

	while(ros::ok())
		{

			if(ans == "1") {
				moving();
				cirkle();

			}
			else if(ans == "2"){
				moving();
			  square();

			}
			else if(ans == "3"){
				randomwalk();
			  square();

			}
			else
				needNew();
			  ros::spinOnce();
			  rate.sleep();
		}

		return 0;
};

void cirkle(){
 	while (dr < 35900)
	{
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
	ros::Rate rate(1000);
		for(int i = 0; 1 > i; i++)
		{
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
void randomwalk(){
	int count = 0;
	srand (time(NULL));
	while(count < 20){
		geometry_msgs::Twist msg;
		msg.linear.x =(double)(rand() % 10 +1)/4.0;
		msg.angular.z =(double)(rand() % 10 - 5)/2.0;
		pub.publish(msg);
		ros::spinOnce();
		count++;

	}

	return;
}
