#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <regex>

using namespace std;


int main()
{
    string line;
    string mask;
    string temp_mask;
    unsigned long mask_1;
    unsigned long mask_0;
    int mem_loc;
    unsigned long mem_val;
    regex mem_loc_rgx("([0-9]+)");
    regex mem_val_rgx("= ([0-9]+)");
    smatch match;
    unordered_map<int, unsigned long> um;

    ifstream myfile ("day14/data");
    if (myfile.is_open())
    {
        while(getline(myfile, line)){
            if (line.at(1) == 'a'){
                // mask
                mask = line.substr(7);
                temp_mask = mask; 
                replace(temp_mask.begin(), temp_mask.end(), 'X', '0');
                mask_1 = stoul(temp_mask, nullptr, 2);
                temp_mask = mask;
                replace(temp_mask.begin(), temp_mask.end(), 'X', '1');
                mask_0 = stoul(temp_mask, nullptr, 2);
            }
            else{
                // mem
                regex_search(line, match, mem_loc_rgx);
                mem_loc = stoi(match[0]);
                regex_search(line, match, mem_val_rgx);
                mem_val = stoul(match[1]);

                um[mem_loc] = (mem_val & mask_0) |  mask_1;
            }
        }
        myfile.close();
    }

    unsigned long sum = 0;
    for (auto& it: um){
        sum += it.second;
    }
    cout << sum << endl;

    return 0;
}

