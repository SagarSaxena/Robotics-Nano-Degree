# Project 4 - Map My World

## Description

The database file can be downloaded [here](https://drive.google.com/open?id=1cTToWuMNFxYuCTSdDx6bDi9gL-te_gg-). (It's too large to host on github)

## Install

Clone the repo:
```
$ git clone https://github.com/SagarSaxena/Robotics-Nano-Degree.git
```

Install the RTAB-Map binary:
```
$ sudo apt-get install ros-kinetic-rtabmap-ros
```

In the source directory for Project 4 clone the teleop-twist package
```
cd ~/Robotics-Nano-Degree/Project4/src
$ git clone https://github.com/ros-teleop/teleop_twist_keyboard
```

Compile the project:
```
$ cd ~/Robotics-Nano-Degree/Project4
$ catkin_make
```


## Launch

Open a terminal and launch the world:
```
$ cd ~/Robotics-Nano-Degree/Project4/
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

In another terminal launch the teleop node:
```
$ cd ~/Robotics-Nano-Degree/Project4/
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

Finally, in a third terminal launch the mapping node:
```
$ cd ~/Robotics-Nano-Degree/Project4/
$ source devel/setup.bash
$ roslaunch my_robot mapping.launch
```

## Ouput

The generated map (db file) will be located in the `/root/.ros/` folder

The map db file can be viewed/analyzed in the `rtabmap-databaseViewer`
```
$ rtabmap-databaseViewer ~/.ros/rtabmap.db
```
