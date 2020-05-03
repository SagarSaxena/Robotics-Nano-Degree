# Project 5 - Home Service Robot

## Description

## Results

## Install
```
$ git clone https://github.com/SagarSaxena/Robotics-Nano-Degree.git



## Generating a Map

`turtlebot_world.launch` launches the turtlebot at X=0, Y=0, Yaw = 0 by default. This will collide with a wall in the custom Gazebo world used. Update the spawn position:
```
export ROBOT_INITIAL_POSE="-x 1 -y -1.5 -Y 1.57"
```
then launch the script:
```
$ cd ~/Robotics-Nano-Degree/Project5/
$ source devel/setup.bash
$ ./test_slam.sh
```
after mapping the environment open a terminal and save the map:
```
rosrun map_server map_saver
```
Note this will save two files, map.pgm and map.yaml in the current directory


