# Robotics Software Engineer Nanodegree
This repo contains completed labs and projects from the [Udacity Robotics Software Engineer Nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209). Each sub folder is a lab or project from the course, described below.

## Projects

### Project 1 - Build My World
A 3D model of my apartment made in Gazebo along with a simple robot model. A Gazebo script written in C++ displays a welcome message to the terminal and another script drives one of the robots in a straight line.

### Project 2 - Go Chase It!
Modelled a more advanced robot model that has a LIDAR and camera sensor and housed it in the world model from project 1. Wrote two ROS packages:
* `drive_bot`: Holds the robot and world models, with gazebo plugins for the LIDAR, camera, and differenial drive for the robot.
* `ball_chaser`: provides a service to drive the robot towards a white ball that can be repositioned throughout the environment

### Lab: Kalman Filter
A lab assignemnt to learn about Kalman filters, and integrating several ROS packages:
* `turtlebot_gazebo` to launch a robot in gazebo 
* `robot_pose_ekf` to estimate the position and orientation of the robot
* `odom_to_trajectory` to create trajectory paths for visualization
* `turtlebot_teleop` to drive the robot using keyboard commands
* `rviz` to visualize the unfiltered and filtered trajectory of the robot

### Project 3 - Where Am I?
To be completed.

## Install
Clone the repo to your machine:
`$ git clone https://github.com/SagarSaxena/Robotics-Nano-Degree.git`
To run individual projects/labs refer to the install/usage section in the respective folder's README.

## Dependencies
All projects/labs used ROS Kinetic, they have not been tested on other distros.
