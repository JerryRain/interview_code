#include <iostream>
#include "ros/ros.h"
#include "number_input/senddata.h"
using namespace std;


int main(int argc, char **argv)
{
   ros::init(argc, argv, "send_data_client");
   ros::NodeHandle nh;
   ros::ServiceClient client = nh.serviceClient<number_input::senddata>("senddata");
   number_input::senddata srv;
   cout << "Please input a number" << endl;
   cin >> srv.request.senddata;

   while(srv.request.senddata<0 || srv.request.senddata>100)
   {
	ROS_INFO("Invalid number!\n");
	ROS_INFO("Please input a valid number: ");
        cin >> srv.request.senddata;
   }


   if(client.call(srv))
   {	
	ROS_INFO("Response from server success");
   }
   else 
   {
	ROS_INFO("Failed to call service number_input");
	return 1;
   }
   return 0;
}
