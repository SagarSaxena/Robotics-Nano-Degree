#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"


class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher_ = n_.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
  }

  ros::NodeHandle n() {
    return n_;
  }

  // handle_drive_request callback function that executes whenever a drive_bot service is requested
  // This function publishes the requested linear x and angular velocities to the robot wheel joints
  // After publishing the requested velocities, a message feedback is returned with the requested wheel velocities

  bool handle_drive_request(ball_chaser::DriveToTarget::Request& req, ball_chaser::DriveToTarget::Response& res)  
  {
    ROS_INFO("DriveToTargetRequest received - linear_x:%1.2f, angular_z:%1.2f", (float)req.linear_x, (float)req.angular_z);

    // Create a motor_command object of type geometry_msgs::Twist
    geometry_msgs::Twist motor_command;

    // Set wheel velocities, to requested values
    motor_command.linear.x = req.linear_x;
    motor_command.angular.z = req.angular_z;

    // Publish angles to drive the robot
    motor_command_publisher_.publish(motor_command);

    // Return a response message
    res.msg_feedback = "Velocities set to - linear_x: " + std::to_string(motor_command.linear.x) + " angular_z: " + std::to_string(motor_command.angular.z);
    ROS_INFO_STREAM(res.msg_feedback);

    return true;
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher motor_command_publisher_;

}; //End of class SubscribeAndPublish


int main(int argc, char** argv)
{
  // Initialize a ROS node
  ros::init(argc, argv, "drive_bot");

  // Create Sub/Pub object
  SubscribeAndPublish SAPObject;

  // Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function. See http://wiki.ros.org/roscpp/Overview/Services section 3.3.2 for syntax
  ros::ServiceServer service = SAPObject.n().advertiseService("/ball_chaser/command_robot", &SubscribeAndPublish::handle_drive_request, &SAPObject);

  // Handle ROS communication events
  ros::spin();

  return 0;
}
