#!/bin/sh

export ROBOT_INITIAL_POSE="-x 4 -y 1.5 -Y 1.57"
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find my_robot)/worlds/myWorld " &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/map.yaml " &
sleep 5 
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " rosrun pick_objects pick_objects "
