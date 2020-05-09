#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/tf.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // initialize goal positions
  float goalPose[2][3] = {{-1, 1.75, 0}, {-0.75, -3.5, 1.57}};
  int numGoals = 2; 

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  for (int i = 0; i < numGoals; i++) {

    // Define goal pose
    goal.target_pose.pose.position.x = goalPose[i][0];
    goal.target_pose.pose.position.y = goalPose[i][1];
    goal.target_pose.pose.orientation = tf::createQuaternionMsgFromYaw(goalPose[i][2]);

    // Send the goal pose of the pickup zone
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its goal
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
      ROS_INFO("Successfully reached pick up zone");

      ros::Duration(5.0).sleep();
    }
    else {
      ROS_INFO("Robot failed to reach pick up zone");
    }

  } 

  return 0;
}
