cmake_minimum_required(VERSION 2.8.3)
project(exam1)

#find other catkin packages.
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  turtlesim

)

find_package(catkin REQUIRED)

add_message_files(
DIRECTORY
msg
FILES
string_msg_talker.msg

)





catkin_package(

CATKIN_DEPENDS
roscpp
rospy
turtlesim

)




include_directories(
${catkin_INCLUDE_DIRS}
)


add_executable(talker src/talker.cpp)
target_link_libraries (talker ${catkin_LIBRARIES})
add_dependencies(talker exam1_generate_message_cpp)

add_executable(listener src/listener1.cpp)
target_link_libraries (listener ${catkin_LIBRARIES})
add_dependencies(listener exam1_generate_message_cpp)


