#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


vector<int> diff(const vector<int> &arr){
    int L = arr.size();
    vector<int> diff(L - 1);
    for (int i = 0; i < L - 1; i++){
        diff[i] = arr[i + 1] - arr[i];
    }

    return diff;
}

int main()
{
    string line;
    string op;
    vector<int> arr;

    ifstream myfile ("day10/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            arr.push_back(stoi(line));
        }
        myfile.close();
    }

    arr.push_back(0);
    sort(arr.begin(), arr.end());
    arr.push_back(arr.back() + 3);

    vector<int> diff_arr = diff(arr);
    int L = diff_arr.size();
    unordered_map<int, int> um;
    for (int i = 0; i < L; i++){
        if(um.find(diff_arr[i]) == um.end()){
            um[diff_arr[i]] = 1;
        }
        else{
            um[diff_arr[i]]++;
        }
    }
    
    cout << um[1] << " - " <<  um[2] << " - " << um[3] << endl;
    cout << um[1] * um[3];
    return 0;

}
