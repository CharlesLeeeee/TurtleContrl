# turtlecontrl
This program allows you to easily control the robot in third person mode without the need to be in the robot's perspective, unlike the other teleop keys.

# Running and setting up the third-person controller for Turtlesim Bot
### To set up the third-person controller for Turtlesim Bot, run the following commands on the terminal:
1. Build a catkin workspace
    ```bash
    $ mkdir -p custom_ws/src  
    $ cd custom_ws  
    $ catkin_make
    ```
    
1. Clone this repo
    ```bash
    $ cd ~/custom_ws/src
    $ git clone https://github.com/CharlesLeeeee/turtlecontrl
    ```
    
2. Build
    ```bash
    $ cd ~/custom_ws
    $ source ./devel/setup.bash
    $ catkin_make
    ```
    
### To run the controller, run the following commands on the terminal:
1. Run ROS
     ```bash
     $ roscore
     ```
2. Open up a new terminal and run Turtlesim Bot
     ```bash
     $ rosrun turtlesim turtlesim_node
     ```
3. Open up a new terminal to run the controller
     ```bash
     $ cd ~/custom_ws
     $ source ./devel/setup.bash
     $ rosrun turtlecontrl moverobot
     ```
     To run the Python version type
     ```bash
     $ rosrun turtlecontrl moverobot.py
     ```
4. Use "W, A, S, D" to move control the TurtleBot. Press "W" to move the turtle directly up with respect to the screen, press "S" to move the turtle directly down with respect to the screen, press "D" to move the turtle directly to the right with respect to the screen, and press "A to move the turtle directly to the left with respect to the screen. You must press "Enter" after each keyboard input.
