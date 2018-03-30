#include <stdio.h>
#include <iostream>
#include <fstream>
#include "pose.pb.h"

using namespace std;
using namespace vr;

string send()
{
	Pose pose;
	pose.set_pos_x(1.1f);
	pose.set_pos_y(2.2f);
	pose.set_pos_z(3.3f);
	pose.set_euler_x(4.1f);
	pose.set_euler_y(4.2f);
	pose.set_euler_z(4.3f);

	string data;
	pose.SerializeToString(&data);

	return data;
}

void recv(const string &data)
{
	Pose pose;
	if (pose.ParseFromString(data)) {
		printf("%f, %f, %f, %f, %f, %f\n",
			pose.pos_x(), pose.pos_y(), pose.pos_z(),
			pose.euler_x(), pose.euler_y(), pose.euler_z());
	}
}

int main(int argc, char* argv[])
{
	string data = send();

	printf("send:\n%s\n", data.c_str());

	printf("recv:\n");
	recv(data);

	return 0;
}
