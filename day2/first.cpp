#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    vector<int>  arr;
    string line;
    string section;
    int counter = 0;
    int lower;
    int upper;
    int matches;
    ifstream myfile ("day2/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            istringstream iss(line);
            vector<string> rule;
            while (getline(iss, section, ' ')){
                rule.push_back(section);
            }
            istringstream issrule(rule[0]);
            string rule_section;
            for (int i=0;i<2;i++){
                getline(issrule, rule_section, '-');
                if (i == 0) lower = stoi(rule_section); 
                if (i == 1) upper = stoi(rule_section); 
            }
            matches = count(rule[2].begin(), rule[2].end(), rule[1][0]);
            if (matches >= lower && matches <= upper){
                counter++;
            }
        }
        cout << counter << endl;

        myfile.close();
    }
    else
    {
        cout << "Didnt work bro";
    }
}
