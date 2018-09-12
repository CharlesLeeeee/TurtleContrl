# mylittleprojects
This program allows you to easily control the robot in third person mode without the need to be in the robot's perspective, unlike the other teleop keys.

# Running and setting up the third-person controller for Turtlesim Bot
### To set up the third-person controller for Turtlesim Bot, run the following commands on the terminal:
    
1. Clone this repo
    ```bash
    $ cd ~
    $ git clone https://github.com/CharlesLeeeee/TurtleContrl
    ```
    
2. Build
    ```bash
    $ cd ~/TurtleContrl
    $ source ./devel/setup.bash
    $ catkin_make
    ```
    
After compiling from source, don't forget to source your workspace:  
    ``` bash
    $ source ./devel/setup.bash
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
     $ cd ~/TurtleContrl
     $ source ./devel/setup.bash
     $ rosrun charles_package moverobot
     ```
     To run the Python version type
     ```bash
     $ rosrun charles_package moverobot.py
     ```
4. Use "W, A, S, D" to move control the TurtleBot. Press "W" to move the turtle directly up, press "S" to move the turtle directly down, press "D" to move the turtle directly to the right, and press "A to move the turtle directly to the left. You must press "Enter" after each keyboard input.
