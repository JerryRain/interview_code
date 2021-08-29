#include <iostream>
#include <ros/ros.h>
#include <number_input/senddata.h>
using namespace std;
vector<int> output_data;

bool handle_function(number_input::senddata::Request &req,number_input::senddata::Response &res){
    ROS_INFO("Request from client %d",req.senddata );
    res.feedback = "Success!";
    ros::Rate rate_loop(0.5);

    while(ros::ok)
    {
	for(int i=0; i<=100; i++)
	{
           output_data.push_back(i);
	   cout << i << endl;
           rate_loop.sleep();
	}
        output_data.clear();
    }
    return true;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "receive_data_server");
    ros::NodeHandle nd;
    ros::ServiceServer service=nd.advertiseService("senddata",handle_function);
    ros::spin();
    return  0;
}
