#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;


int main()
{
    string line;
    stack<string> st;
    st.push("shiny gold");
    long counter = 0;
    string delim = "bags contain";
    string bag;
    string contents;
    string current_bag;
    unordered_map<string, int> um;
    um["shiny gold"] = 1;
    while(!st.empty()){
        ifstream myfile ("day7/data");
        current_bag = st.top();
        st.pop();
        if (myfile.is_open())
        {
            while (getline(myfile, line)){
                bag = line.substr(0, line.find(delim));
                contents = line.substr(line.find(delim) + delim.length());
                if (contents.find(current_bag) != string::npos && um.find(bag) == um.end()){
                    st.push(bag);
                    um[bag] = 1;
                    counter++;
                }
            }
            myfile.close();
        }
    }
    cout << counter;
}
