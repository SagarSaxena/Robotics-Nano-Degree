#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the DriveToTarget service and pass the request velocities
    	if (!client.call(srv))
        	ROS_ERROR("Failed to call service DriveToTarget");

}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    bool ball_found = false;
    float linear_vel;
    float angular_vel;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    
    int pixel_index = 0;
    for (; pixel_index < img.height*img.step; pixel_index++) {
      if (img.data[pixel_index] == white_pixel) {
        ball_found = true;
	ROS_INFO_STREAM("Yes!");
	break; 
      }
    }


    if (ball_found == true) {
        if (pixel_index % img.step < (img.step/3)) {
	    // turn left
            linear_vel = 0;
	    angular_vel = 0.5;
        }
        else if (pixel_index % img.step < (img.step/3*2)) {
            // go stright
            linear_vel = 0.5;
	    angular_vel = 0;
        }
        else {
            // turn right
            linear_vel = 0;
	    angular_vel = -0.5;
        } 
    }
    else {
            // stop
            linear_vel = 0;
	    angular_vel = 0;
    }

    drive_robot(linear_vel, angular_vel);
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
