#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;


int main()
{
    string line;
    ifstream myfile ("day4/data");
    if (myfile.is_open())
    {
        string passport = "";
        string field;
        unordered_map<string, int> m;
        m["byr"] = 1;
        m["iyr"] = 1;
        m["eyr"] = 1;
        m["hgt"] = 1;
        m["hcl"] = 1;
        m["ecl"] = 1;
        m["pid"] = 1;
        int counter;
        int valid = 0;
        string key;
        // m["cid"] = 1;
        while (getline(myfile, line)){
            if (line == ""){
                istringstream iss(passport);
                counter = 0;
                while(getline(iss, field, ' ')){
                    key = field.substr(0, 3);  
                    if (m.find(key) != m.end()){
                        counter++;
                    }
                }
                if (counter == 7){
                    valid++;
                }
                passport = ""; 
            }
            else{
                passport += " " + line;
            }

        }
        cout << valid;

        myfile.close();
    }
    else
    {
        cout << "Didnt work bro";
    }
}
