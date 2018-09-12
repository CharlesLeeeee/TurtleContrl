cmake_minimum_required(VERSION 2.8.3)
project(turtlecontrl)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)


## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES 
#   AddTwoInts.srv
#   )

## Generate actions in the 'action' folder
#add_action_files(
#  DIRECTORY action
#  FILES Fibonacci.action
#)

## Generate added messages and services with any dependencies listed here
#generate_messages(
#   DEPENDENCIES
#   std_msgs
#   actionlib_msgs
#)


###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES charles_package
  CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs message_runtime
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)




add_executable(moverobot src/moverobot.cpp)
target_link_libraries (moverobot ${catkin_LIBRARIES})




