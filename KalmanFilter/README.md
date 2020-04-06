# Lab: Kalman Filter

## Description
This lab assignment pulls together 5 different ROS packages to control a robot in Gazebo using an EKF (extended kalman filter) to estimate its pose. The EKF performs sensor fusion on data from an IMU, rotary encoders (odometry). The use of each package is summarized below:
* `turtlebot_gazebo` to launch a robot in gazebo. [Link](http://wiki.ros.org/turtlebot_gazebo)
* `robot_pose_ekf` to estimate the position and orientation of the robot. [Link](http://wiki.ros.org/robot_pose_ekf#Subscribed_Topics)
* `odom_to_trajectory` to create trajectory paths for visualization. [Link](https://github.com/udacity/odom_to_trajectory)
* `turtlebot_teleop` to drive the robot using keyboard commands. [Link](http://wiki.ros.org/turtlebot_teleop)
* `rviz` to visualize the unfiltered and filtered trajectory of the robot

## Install
These instructions assume that the entire repo has been cloned. If not, refer to the repo README [here](https://github.com/SagarSaxena/Robotics-Nano-Degree/blob/master/README.md).

There are five ROS packages that need to be installed first:

#### Clone the packages
```
$ cd ~/Robotics-Nano-Degree/KalmanFilter/src
$ git clone https://github.com/turtlebot/turtlebot_simulator
$ git clone https://github.com/udacity/robot_pose_ekf
$ git clone https://github.com/udacity/odom_to_trajectory
$ git clone https://github.com/turtlebot/turtlebot
```

#### Build packages
```
$ cd ~/Robotics-Nano-Degree/KalmanFilter
$ catkin_make
```

#### Install dependencies
```
$ source devel/setup.bash
$ rosdep -i install turtlebot_gazebo
$ catkin_make

```

## Usage
Open a terminal, navigate to the KalmanFilter directory, source the setup script, and launch `main.launch`
```
$ cd ~/Robotics-Nano-Degree/KalmanFilter
$ source devel/setup.bash 
$ roslaunch main main.launch
```
This will launch the Gazebo world and an Rviz configuration.

You can move the turtlebot around from the same terminal per the `turtlebot_teleop` documentation:

Moving around:
* i / ' : up / down
* j / l : left / right
* u / . : up-left / down-right (diagonals)
* o / m : up-right / down-left (diagonals)

Velocity:
* q/z : increase/decrease max speeds by 10%
* w/x : increase/decrease only linear speed by 10%
* e/c : increase/decrease only angular speed by 10%
* space key, k : force stop
* anything else : stop smoothly
