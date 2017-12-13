#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "turtlesim/Color.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>

using namespace std;
ros::Publisher pub1;

// Topic messages callback
//pose_callback
void UI(){

int option;
std_msgs::String msg;
stringstream ss;

cout << "Introduction to what the user can do here"<<endl;
  cout << "Choose one of the following options:"<<endl;
   cout << "Press 1 for circle " <<endl;
    cout << "Press 2 for square " <<endl;
  cout << "Press 3 for star " <<endl;
   cout << "Press 4 for triangle" <<endl;

cin >> option;


     switch(option)
     {
case (1):
    ss << "1";
    msg.data = ss.str();

         break;

case (2):

     ss << "2";
     msg.data = ss.str();

         break;

 case (3):

     ss << "3";
     msg.data = ss.str();

        break;

case (4):

     ss << "4";
     msg.data = ss.str();

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


 pub1 = node.advertise<std_msgs::String>("Commands", 1);



    // Enter a loop.
    while(ros::ok()){


UI();

ros::spinOnce();
}
    return 0;
}
