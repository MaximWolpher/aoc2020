#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;


int main()
{
    string line;
    int val;
    vector<int> vec;
    unordered_map<int, int> um;

    ifstream myfile ("day15/example");
    if (myfile.is_open())
    {
        getline(myfile, line);
        istringstream iss(line);
        int line_counter = 0;
        while(getline(iss, line, ',')){
            vec.push_back(stoi(line));
            line_counter++;
        }
        myfile.close();
    }
    for (size_t i = 0; i < vec.size() - 1; i++){
        um[vec[i]] = i;
    }
    int idx = vec.size() - 1;
    size_t find = 2020;
    while (vec.size() < find){
        val = vec.back();
        if (um.find(val) == um.end()){
            vec.push_back(0);
            um[val] = idx;
        }
        else {
            int new_val = idx - um.at(val);
            vec.push_back(new_val);
            um[val] = idx;
        }
        idx++;
    }

    cout << vec[find - 1] << endl;

    return 0;
}

