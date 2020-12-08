#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;


int main()
{
    string line;
    string op;
    int value;
    vector<string> arr = {};
    vector<string> orig_arr = {};
    ifstream myfile ("day8/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            orig_arr.push_back(line);
        }
        myfile.close();
    }
    bool failed = true;
    int prog_size = orig_arr.size();
    for (int i = 0; i < prog_size; i++){
        int index = 0;
        int accumulator = 0;
        unordered_map<int, int> um;

        // Copy to new array
        arr = orig_arr;
        line = arr[i];
        op = line.substr(0,3);
        value = stoi(line.substr(4));
        if (op == "acc") continue;
        if (op == "nop"){
            arr[i] = "jmp " + to_string(value);
        }
        if (op == "jmp"){
            arr[i] = "nop " + to_string(value);
        }
        
        while(true){
            if (um.find(index) != um.end()){
                break;
            }
            if (index == prog_size){ 
                failed = false;
                break;
            }

            um[index] = 1;
            line = arr[index];
            op = line.substr(0,3);
            value = stoi(line.substr(4));
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
        if (!failed){
            cout << accumulator;
            break;
        }
    }
    if (failed){
        cout << "Couldnt find a solution" << endl;
    }

}
