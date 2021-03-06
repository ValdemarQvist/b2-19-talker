#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>

using namespace std;

ros::Publisher pub;	//declaring a publisher
ros::Publisher pub1;	//declaring a publisher
ros::Subscriber pose_subscriber;  //declaring a Subscriber
ros::Subscriber UI_sub;//declaring a Subscriber

const double PI =3.14159265359; // sets a constant for PI

bool done = false; //helps stop the loop in func square
int xr;	// x coordinate of the turtle in turtlesim
int yr;	// y coordinate of the turtle in turtlesim
int dr;	// looking direction of the turtle in turtlesim
string ans;

void randomwalk();//prototyping the function
void circle();//prototyping the function
void square();//prototyping the function
// publishes on the topic "Done" and uses the std_msgs::String msg
void needNew(){

	std_msgs::String msg;
	stringstream ss;
	ss << "I'am ready for your commad";
	msg.data = ss.str();
	pub1.publish(msg);
	ros::spinOnce();
	return;
}
// publishes on the topic "Done" and uses the std_msgs::String msg
void moving(){

	std_msgs::String msg;
	stringstream ss;
	ss << "I'am moving";
	msg.data = ss.str();
	pub1.publish(msg);
	ros::spinOnce();
	return;
}
//subscribes to the topic "/turtle1/pose" and updates xr,yr,dr
//every time a new msg is published
void poseCallback(const turtlesim::Pose::ConstPtr& msg){
	xr = msg->x;
	yr = msg->y;
	dr = ((msg->theta*180)/PI)*100;
  ROS_INFO("x: [%i], y: [%i] looking: [%i]", xr, yr, dr);

}
//subscribes to the topic "Done" and updates xr,yr,dr
//every time a new msg is published
void chatterCallback(const std_msgs::String::ConstPtr& data){
	ans = data->data;
  //ROS_INFO("I heard:[%s]", ans);
}

int main(int argc, char**argv){

	ros::init(argc, argv, "Mover");

	ros::NodeHandle n;

	UI_sub = n.subscribe("Commands", 1000, chatterCallback);
  pose_subscriber = n.subscribe("/turtle1/pose",100 , poseCallback);
  pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  pub1 = n.advertise<std_msgs::String>("Done", 1);

	ros::Rate rate(10);

	while(ros::ok())
		{
			moving();
			if(ans == "1") {
				moving();
				circle();
				ros::spinOnce();
				ans = "hej";
			}
			else if(ans == "2"){
				moving();
			  square();
				ros::spinOnce();
				ans = "hej";
			}
			else if(ans == "3"){
				moving();
				randomwalk();
				ros::spinOnce();
				ans = "hej";
			}
			else
				needNew();
			  ros::spinOnce();

		}

		rate.sleep();
		return 0;
};

void circle(){
	ros::Rate rate(1);
 	while (dr < 35900)
	{
		ros::Rate rate(1);
			geometry_msgs::Twist msg;
			msg.linear.x = 1;
			msg.angular.z = 1;
			pub.publish(msg);
			ros::spinOnce();
	}
	rate.sleep();
	return;
};


void square(){
	ros::Rate rate(1);
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
				while(yr <= 5 )  {
					geometry_msgs::Twist msg;
					msg.linear.x =1;
					pub.publish(msg);
					ros::spinOnce();

			  }

		rate.sleep();
		return;
};


void randomwalk(){
	ros::Rate rate(1);
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
	rate.sleep();
	return;
};
