# Project 1 - Build My World

## Install

The build directory is already included in the repo, so the code does not need to be compiled again.

If the build directory was deleted or not cloned with the repo, create one:
```
$ cd ~/RoboNDProjects/Project1
$ mkdir build
$ cd build/
$ cmake ../
$ make
```

## Usage

Export the path of your build directory
`$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/RoboNDProjects/Project1/build`

Navigate to the world directory and launch `myWorld`:
```
$ cd ~/RoboNDProjects/Project1/world/
$ gazebo myWorld
```
A gazebo world modelled after my apartment should launch, with some robots scatted through the environment.

One of the robots will move in a straight line until colliding with a wall, and a welcome message will be displayed on the terminal. Both actions are implemented as Gazebo plugins.
