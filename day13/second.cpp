#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void get_data(vector<string> &data){
    string line;
    string bus_id;
    ifstream myfile ("day13/data");
    if (myfile.is_open())
    {
        getline(myfile, line);
        getline(myfile, line);

        istringstream iss(line);
        while(getline(iss, bus_id, ',')){
            data.push_back(bus_id);
        }
        myfile.close();
    }
}

int main()
{
    vector<string> data;
    get_data(data);
    unsigned long timestamp = 0;
    unsigned long step = stoi(data[0]);

    for (size_t i = 1; i < data.size(); i++){
        if (data[i] == "x") continue;
        while ((timestamp + i) % stoi(data[i]) != 0){
            timestamp += step;
        }
        step *= stoi(data[i]);
    }
    cout << timestamp << endl;
    return 0;
}

