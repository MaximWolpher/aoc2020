#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;


int main()
{
    string line;
    string group;
    string person;
    int result = 0;
    ifstream myfile ("day6/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            if (line == ""){
                unordered_map<char, int> m;
                int l = group.length();
                for (int i=0; i < l; i++){
                    m[group[i]]++;
                }
                result += m.size();
                group = "";
            }
            else{
                group += line;
            }
        }
        cout << result;
        myfile.close();
    }
    else
    {
        cout << "Didnt work bro";
    }
}
