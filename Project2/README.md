# Project 2 - Go Chase It!

## Description
This project creates two ROS packages `drive_bot` and `ball_chaser` to drive a robot around in the Gazebo world from Project 1.

The `drive_bot` package launches the gazebo world, a robot with lidar and camera sensors, as well as a white ball. The package uses three gazebo plugins:
* Camera controller (libgazebo_ros_camera.so)
* Hokuyo LIDAR controller (libgazebo_ros_laser.so) 
* Differential drive controller (libgazebo_ros_diff_drive.so)

The `ball_chaser` package implements two ROS nodes:
* `drive_bot`: Provides a ROS service to drive the robot around
* `process_image`: Subscribes to the robots camaera and determines the position of the white ball in the scene. Then requests the service in `drive_bot` to move towards the ball


## Install and Usage
These instructions assume that the entire repo has been cloned. If not, refer to the repo README [here](https://github.com/SagarSaxena/Robotics-Nano-Degree/blob/master/README.md).

Open a terminal, navigate to the Project2 directory, source the setup script, and launch `world.launch`
```
$ cd ~/RoboNDProjects/Project2
$ source devel/setup.bash 
$ roslaunch my_robot world.launch
```
This will launch the Gazebo world and an Rviz configuration to visualize the LIDAR and camera readings.

In another terminal, launch `ball_chaser.launch`. This will start the `drive_bot` and `process_image` nodes.
```
$ cd ~/RoboNDProjects/Project2
$ source devel/setup.bash 
$ roslaunch ball_chaser ball_chaser.launch
```

You can now use the translate tool in Gazebo to move the white ball to different positions and the robot will follow it (as long as its in its camera's field of view).

![Go Chase It! demo](GIF/GoChaseIt_Demo.gif)


