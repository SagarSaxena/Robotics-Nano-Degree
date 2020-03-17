#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    sub1_ = n_.subscribe("/camera/rgb/image_raw", 10, &SubscribeAndPublish::process_image_callback, this);

    // Define a client service capable of requesting services from command_robot
    client_ = n_.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");
  }

  // This callback function continuously executes and reads the image data, looks for a white ball and command the robot to move towards it
  void process_image_callback(const sensor_msgs::Image img)
  {

    // loop through image to identify first (if any) white pixels  
    int pixel_index = 0;
    for (; pixel_index < img.height*img.step; pixel_index++) {

      // all 3 channels (RGB) have to be 255 to recognize a white pixel
      if ((img.data[pixel_index] & img.data[pixel_index+1] & img.data[pixel_index+2])  == white_pixel) {
        ball_found = true;
	ROS_INFO_STREAM("Yes!");
	break; 
      }

      else
        ball_found = false;
    }

    // drive robot based on position of found white pixel
    if (ball_found == true) {
        if (pixel_index % img.step < (img.step/3)) 

	    drive_robot(0, cmd_angular_vel);			// turn left

        else if (pixel_index % img.step < (img.step/3*2)) 
            
            drive_robot(cmd_linear_vel, cmd_angular_vel);	// go stright
            
        else 
            
	    drive_robot(0, -cmd_angular_vel);			// turn right
        
    }
    else {
            drive_robot(0,0);					// stop
    }

  }

private:

  ros::ServiceClient client_;
  ros::NodeHandle n_; 
  ros::Subscriber sub1_;

  int white_pixel = 255;
  bool ball_found = false;
  const float cmd_linear_vel = 1.0;
  const float cmd_angular_vel = 1.0;

  // This function calls the command_robot service to drive the robot in the specified direction
  void drive_robot(float lin_x, float ang_z)
  {
    // Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the DriveToTarget service and pass the request velocities
    	if (!client_.call(srv))
        	ROS_ERROR("Failed to call service DriveToTarget");
  }

}; //End of class SubscribeAndPublish


int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");

    // Create a Sub/Pub objects
    SubscribeAndPublish SAPObject;

    // Handle ROS communication events
    ros::spin();

    return 0;
}
