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
    vector<int> vec;
    unordered_map<int, int> um;

    ifstream myfile ("day15/data");
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
    int find = 30000000;
    int last = vec[vec.size() - 1];

    while (idx < find - 1){
        if (um.find(last) == um.end()){
            um[last] = idx;
            last = 0;
        }
        else {
            int new_val = idx - um.at(last);
            um[last] = idx;
            last = new_val;
        }
        idx++;
    }

    cout << last << endl;

    return 0;
}

