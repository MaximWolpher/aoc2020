#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    string line;
    string bus_id;
    int timestamp;
    int departure;
    int best_time = 100000;
    int best_id = 0;


    ifstream myfile ("day13/data");
    if (myfile.is_open())
    {
        getline(myfile, line);
        timestamp = stoi(line);
        getline(myfile, line);

        istringstream iss(line);
        while(getline(iss, bus_id, ',')){
            if (bus_id == "x") continue;
            departure = stoi(bus_id) - (timestamp % stoi(bus_id));
            if (departure < best_time) {
                best_time = departure;
                best_id = stoi(bus_id);
            }
        }
        myfile.close();
    }

    cout << best_time * best_id << endl;
    return 0;
}

