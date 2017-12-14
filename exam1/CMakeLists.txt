cmake_minimum_required(VERSION 2.8.3)
project(exam1)
add_compile_options(-std=c++11)
#find other catkin packages.
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  turtlesim
  geometry_msgs
  message_generation
  std_msgs
)

find_package(catkin REQUIRED)

catkin_package(

CATKIN_DEPENDS
std_msgs
roscpp
rospy
turtlesim
geometry_msgs
message_generation

)

include_directories(
${catkin_INCLUDE_DIRS}
)

add_executable(UI_turtlesim_mover_node src/talker.cpp)
target_link_libraries (UI_turtlesim_mover_node ${catkin_LIBRARIES})
add_dependencies(UI_turtlesim_mover_node exam1_generate_message_cpp)

add_executable(turtlesim_mover_node src/listener1.cpp)
target_link_libraries (turtlesim_mover_node ${catkin_LIBRARIES})
add_dependencies(turtlesim_mover_node exam1_generate_message_cpp)
