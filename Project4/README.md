# Project 4 - Map My World

## Description

To be completed.

## Install

Clone the repo:
```
git clone ________
```

Install the RTAB-Map binary:
```
sudo apt-get install ros-kinetic-rtabmap-ros
```

In the source directory clone the teleop-twist package
```
cd ~/Robotics-Nano-Degree/Project4/src
git clone https://github.com/ros-teleop/teleop_twist_keyboard
```

Compile the project:
```
cd ~/Robotics-Nano-Degree/Project4
catkin_make
```


## Launch

Open a terminal and lauch the world:
```
roslaunch my_robot world.launch
```

In another terminal launch the teleop node:
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

Finally, in a third terminal launch the mapping node:
```
roslaunch my_robot mapping.launch
```

Be sure to source the setup.bash file in each terminal before launching then nodes:
```
source devel/setup.bash
```
The generated map (db file) will be located in the /root/.ros/ folder

The map db file can be viewed/analyzed in the `rtabmap-databaseViewer`
```
rtabmap-databaseViewer ~/.ros/rtabmap.db
```
