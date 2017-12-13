#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "turtlesim/Color.h"
#include <iostream>

using namespace std;

// Topic messages callback
//pose_callback
void pose_callback(const turtlesim::Pose& msgIn){

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
        case '1': cout << '1';
         break;
         case '2': cout << '2';
         break;
         case '3': cout << '3';
        break;
         case '4': cout << '4';
          break;
        }
return 0;
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "talker");
 ros::NodeHandle node;

    ros::Subscriber subscriber_pose=node.subscribe("turtle1/pose", 1, pose_callback);
    // Enter a loop.
    while(ros::ok());
    ros::spin();

    return 0;
}
