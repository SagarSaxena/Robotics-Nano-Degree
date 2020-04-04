# Project 3 - Where Am I?

## Description
This project uses the ROS AMCL (Adaptive Monte Carlo Localization) package to localize a mobile robot inside a map and the ROS navigation stack to move towards user defined goal positions. The robot and world were modelled in Gazebo. The map was generated from the Gazebo world using the ROS package [pgm_map_creator](https://github.com/udacity/pgm_map_creator).

The robot can optionally be teleoperated using the `ros_teleop` package

![Where Am I? demo](GIF/WhereAmI_Demo1.gif)
**Shown above:** The particle cloud (red arrows) surrounding the robot are initially dispersed since the robot is uncertain of its pose. As it moves, it gathers more information from Odometry and its LIDAR sensor, so the particles converge as its certainty increases. 

![Where Am I? demo](GIF/WhereAmI_Demo3.gif)
**Shown above:** The robot navigates through some narrow doors to its goal position. The ROS navigation stack plans a global trajectory from start to goal pose (green line). A local planner ([base_local_planner](http://wiki.ros.org/base_local_planner)) creates a local plan to follow the global trajectory while avoiding obstacles. The local planning algorithm creates a grid around the robot and maps the global path onto this area. This is best visualized as the robots passes through doors. Several local trajectories are generated and ranked against a tunable cost function and the trajectory with the lowest (best) cost is used.

## Install and Usage
These instructions assume that the entire repo has been cloned. If not, refer to the repo README [here](https://github.com/SagarSaxena/Robotics-Nano-Degree/blob/master/README.md).

Then, open a terminal, navigate to the Project3 directory, source the setup script, and launch `world.launch`
```
$ cd ~/RoboNDProjects/Project3
$ source devel/setup.bash 
$ roslaunch my_robot world.launch
```
This will launch the Gazebo world and an Rviz configuration.

In another terminal, launch `amcl.launch`
```
$ cd ~/RoboNDProjects/Project3
$ source devel/setup.bash 
$ roslaunch my_robot amcl.launch
```

To move the robot using the ROS navigation stack select "2D Nav Goal" in Rviz and select a pose on the map.

To instead move the robot using teleop, clone the `ros-teleop` package to the `src` folder
```
$ cd ~/RoboNDProjects/Project3/src
$ git clone https://github.com/ros-teleop/teleop_twist_keyboard
```

Build the pacakge and source the setup script
```
cd ..
catkin_make
source devel/setup.bash
```

Finally run the teleop script:
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```





