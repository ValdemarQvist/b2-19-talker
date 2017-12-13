#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "turtlesim/Color.h"
#include <iostream>

using namespace std;

// Topic messages callback
//pose_callback
void UI(){

int option;

 cout << "Introduction to what the user can do here"<<endl;
  cout << "Choose one of the following options:"<<endl;
   cout << "Press 1 for square " <<endl;
    cout << "Press 2 for circle " <<endl;
  cout << "Press 3 for star " <<endl;
   cout << "Press 4 for triangle" <<endl;

    cin >> option;

     switch(option)
     {
        case '1':
        std_msgs::String msg;

    std::stringstream ss;
    ss=1;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
         break;
         case '2':
         std_msgs::String msg;

     std::stringstream ss;
     ss=2;
     msg.data = ss.str();

     ROS_INFO("%s", msg.data.c_str());
         break;
         case '3':
         std_msgs::String msg;

     std::stringstream ss;
     ss=3;
     msg.data = ss.str();

     ROS_INFO("%s", msg.data.c_str());
        break;
         case '4':
         std_msgs::String msg;

     std::stringstream ss;
     ss=4;
     msg.data = ss.str();

     ROS_INFO("%s", msg.data.c_str());
          break;
        }
    pub1.publish(msg);
    ros::spinOnce();    
return;
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "talker");
 ros::NodeHandle node;
 ros::Publisher pub1;

 pub1 = node.advertise<std_msgs::String>("Commands", 1);



    // Enter a loop.
    while(ros::ok());
    ros::spin();

UI();


    return 0;
}
