#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;


void erase_all(string & contents, const string & to_erase){
    size_t pos = string::npos;
    while ((pos = contents.find(to_erase)) != string::npos){
        contents.erase(pos, to_erase.length());
    }
}

long search(string current_bag, unordered_map<string, string> & um){
    string contents;
    int value;
    string new_bag;
    long result = 0;
    if (um.find(current_bag) != um.end()){
        auto contents_obj = um.find(current_bag);
        istringstream iss(contents_obj->second);
        if (contents_obj->second.find("no other") != string::npos){
            return 0;
        }
        while (getline(iss, contents, ',')){
            value = contents.at(1) - '0';
            new_bag = contents.substr(3);
            result += value * (search(new_bag, um) + 1);
        }
    }
    return result;

}

int main()
{
    string line;
    string delim = " bags contain";
    string bag;
    string contents;
    string current_bag;
    string rules[] = {};
    unordered_map<string, string> um;
    ifstream myfile ("day7/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            bag = line.substr(0, line.find(delim));
            contents = line.substr(line.find(delim) + delim.length());
            
            erase_all(contents, " bags");
            erase_all(contents, " bag");
            erase_all(contents, ".");

            um[bag] = contents;
        }
        myfile.close();
    }
    
           
    long result = search("shiny gold", um);
    cout << result;
}
