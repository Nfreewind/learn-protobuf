#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "msg.pb.h"

using namespace std;
using namespace protobuf;

int write(const string &filename)
{
    Msg msg;
    msg.set_id(101);
    msg.set_str("hello");

    printf("write to %s\n", filename.c_str());

    // Write the data to disk.
    fstream output(filename, ios::out | ios::trunc | ios::binary);

    if (!msg.SerializeToOstream(&output)) {
        cerr << "Failed to write." << endl;
        return -1;
    }
}

int read(const string &filename)
{
    Msg msg;

    printf("read from %s\n", filename.c_str());
    {
        fstream input(filename, ios::in | ios::binary);
        if (!msg.ParseFromIstream(&input)) {
            cerr << "Failed to parse." << endl;
            return -1;
        }
    }

    cout << "id: " << msg.id() << endl;
    cout << "str: " << msg.str() << endl;

    return 0;
}

int main(int argc, const char *argv[])
{
    write("msg.data");

    read("msg.data");

	return 0;
}
