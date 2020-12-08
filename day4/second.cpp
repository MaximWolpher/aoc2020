#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <regex>

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
        m["iyr"] = 2;
        m["eyr"] = 3;
        m["hgt"] = 4;
        m["hcl"] = 5;
        m["ecl"] = 6;
        m["pid"] = 7;
        m["cid"] = 0;
        string unit;
        int height;
        int counter;
        int valid = 0;
        int year;
        string value;
        string key;
        while (getline(myfile, line)){
            if (line == ""){
                istringstream iss(passport);
                counter = 0;
                while(getline(iss, field, ' ')){
                    key = field.substr(0, 3);  
                    value = field.substr(4);
                    auto map_int = m.find(key);
                    if (map_int != m.end()){
                        switch (map_int->second){
                            case 1: year = stoi(value);
                                        if(year >= 1920 && year <= 2002){
                                            counter++;
                                        }
                                        break;
                            case 2: year = stoi(value);
                                        if(year >= 2010 && year <= 2020){
                                            counter++;
                                        }
                                        break;
                            case 3: year = stoi(value);
                                        if(year >= 2020 && year <= 2030){
                                            counter++;
                                        }
                                        break;
                            case 4: unit = value.substr(value.length() - 2);
                                    if (unit != "cm" && unit != "in") break;
                                    height = stoi(value.substr(0, value.length() - 2));
                                    if (unit == "in"){
                                        if (height >= 59 && height <= 76){
                                            counter++;
                                        }
                                    }
                                    if (unit == "cm"){
                                        if (height >= 150 && height <= 193){
                                            counter++;
                                        }
                                    }
                                    break;
                            case 5: if (regex_match(value, regex("^#[0-9a-f]{6}$"))){
                                        counter++;
                                    }
                                    break;
                            case 6: if (regex_match(value, regex("^(amb|blu|brn|gry|grn|hzl|oth)$"))){
                                        counter++;
                                    }
                                    break;
                            case 7: if (regex_match(value, regex("^[0-9]{9}$"))){
                                        counter++;
                                    } 
                                    break;
                        }
                    }
                }
                if (counter == 7){
                    valid++;
                }
                passport = ""; 
            }
            else{
                if (passport.length() == 0) passport += line;
                else passport += " " + line;
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
