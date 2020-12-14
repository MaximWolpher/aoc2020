#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <regex>
#include <bitset>

using namespace std;


void float_mask(string bit_mask, unordered_map<unsigned long, unsigned long> &um, unsigned long mem_val){
    size_t match;
    match = bit_mask.find_first_of('X');
    if (match == string::npos){
        um[stoul(bit_mask, nullptr, 2)] = mem_val; 
    }
    else{
        bit_mask[match] = '0';
        float_mask(bit_mask, um, mem_val);
        bit_mask[match] = '1';
        float_mask(bit_mask, um, mem_val);
    }
}

int main()
{
    string line;
    string mask;
    unsigned long mem_loc;
    unsigned long mem_val;
    regex mem_loc_rgx("([0-9]+)");
    regex mem_val_rgx("= ([0-9]+)");
    string mem_bit;
    unordered_map<unsigned long, unsigned long> um;
    smatch match;

    ifstream myfile ("day14/data");
    if (myfile.is_open())
    {
        while(getline(myfile, line)){
            if (line.at(1) == 'a'){
                // mask
                mask = line.substr(7);
            }
            else{
                // mem
                regex_search(line, match, mem_loc_rgx);
                mem_loc = stoul(match[0]);
                regex_search(line, match, mem_val_rgx);
                mem_val = stoul(match[1]);
                mem_bit = bitset<36>(mem_loc).to_string();

                for (size_t i = 0; i < mask.size(); i++){
                    if (mask[i] == '1') mem_bit[i] = '1';
                    else if (mask[i] == 'X') mem_bit[i] = 'X';
                }
                float_mask(mem_bit, um, mem_val);
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

