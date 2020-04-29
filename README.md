# Robotics Software Engineer Nanodegree
This repo contains completed labs and projects from the [Udacity Robotics Software Engineer Nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209). Each sub folder is a lab or project from the course, described below.

## Install
Clone the repo to your machine:
```
$ git clone https://github.com/SagarSaxena/Robotics-Nano-Degree.git
```
To run individual projects/labs refer to the install/usage section in the respective folder's README.

## Projects

### Project 1 - Build My World
A 3D model of my apartment made in Gazebo along with a simple robot model. A Gazebo script written in C++ displays a welcome message to the terminal and another script drives one of the robots in a straight line.

For more details see the Project1 [README](https://github.com/SagarSaxena/Robotics-Nano-Degree/tree/master/Project1)

### Project 2 - Go Chase It!
Models a more advanced robot model that has a LIDAR and camera sensor and houses it in the world model from project 1. Implements two ROS packages:
* `drive_bot`: Holds the robot and world models, with gazebo plugins for the LIDAR, camera, and differenial drive for the robot.
* `ball_chaser`: provides a service to drive the robot towards a white ball that can be repositioned throughout the environment

For more details see the Project2 [README](https://github.com/SagarSaxena/Robotics-Nano-Degree/tree/master/Project2)

### Lab: Kalman Filter
A lab assignemnt to learn about Kalman filters, and integrating several ROS packages:
* `turtlebot_gazebo` to launch a robot in gazebo 
* `robot_pose_ekf` to estimate the position and orientation of the robot
* `odom_to_trajectory` to create trajectory paths for visualization
* `turtlebot_teleop` to drive the robot using keyboard commands
* `rviz` to visualize the unfiltered and filtered trajectory of the robot

For more details see the KalmanFilter [README](https://github.com/SagarSaxena/Robotics-Nano-Degree/tree/master/KalmanFilter)

### Project 3 - Where Am I?
Uses the ROS `amcl` and `move_base` packages to localize a robot (from Project 2) in a map and navigate through a Gazebo world. The `amcl` node uses the Adaptive Monte Carlo Localization method, which uses a particle filter to track the pose of the robot against a known map.

For more details see the Project3 [README](https://github.com/SagarSaxena/Robotics-Nano-Degree/tree/master/Project3)

### Project 4 - Map My World
Uses the [rtabmap_ros](http://wiki.ros.org/rtabmap_ros) package to implement Simultaneous Localization and Mapping (SLAM) of a simulated environment. RTAB-Map stands for Real Time Appearance Based Mapping, which is an implementation of the GraphSLAM algorithm that uses vision sensors.

For more details see the Project4 [README](https://github.com/SagarSaxena/Robotics-Nano-Degree/tree/master/Project4)

## Dependencies
All projects/labs used ROS Kinetic, they have not been tested on other distros.
