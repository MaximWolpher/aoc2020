#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;


int main()
{
    string line;
    int index = 0;
    int accumulator = 0;
    string op;
    int value;
    unordered_map<int, int> um;
    vector<string> arr = {};
    ifstream myfile ("day8/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            arr.push_back(line);
        }
        myfile.close();
    }
    while(true){
        if (um.find(index) != um.end()) break;

        um[index] = 1;
        line = arr[index];
        op = line.substr(0,3);
        value = stoi(line.substr(4));
        //cout << line << endl;
        //cout << op << "-" << value << "-" << index << endl;
        //cout << endl;
        if (op == "acc"){
            accumulator += value;
            index++;
        }
        if (op == "jmp"){
            index += value;
        }
        if (op == "nop"){
            index++;
        }
    }
    cout << accumulator;

}
