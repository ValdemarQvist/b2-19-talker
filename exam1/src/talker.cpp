#include "ros/ros.h"
#include <iostream>
#include "std_msgs/String.h"
#include <sstream>
using namespace std;

ros::Publisher pub1;
ros::Subscriber sub1;
// Topic messages callback
//pose_callback
string done;

void UI(){
  std_msgs::String msg;
  stringstream ss;
  int option;

  cout << "Introduction to what the user can do here"<<endl;
  cout << "Choose one of the following options:"<<endl;
  cout << "Press 1 for square " <<endl;
  cout << "Press 2 for circle " <<endl;
  cout << "Press 3 for star " <<endl;
  cout << "Press 4 for triangle" <<endl;
  option = 0;
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
void doneCallback(const std_msgs::String::ConstPtr& data){
	done = data->data;
  //ROS_INFO("The turtlesim is say: [%s]", done);
}
int main(int argc, char **argv)
{
 ros::init(argc, argv, "talker");

 ros::NodeHandle node;
 ros::Publisher pub1;

 pub1 = node.advertise<std_msgs::String>("Commands", 1);



 pub1 = node.advertise<std_msgs::String>("Commands", 10);
 sub1 = node.subscribe("Done",100 , doneCallback);

while(ros::ok())
  {

  for(int i = 0; i < 5; i++)
      {
      cout << done;
      UI();
      cout << done;
      ros::spinOnce();
      }
  }
  return 0;
}
