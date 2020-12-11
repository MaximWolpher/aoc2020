#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void get_data(vector<vector<char>> &arr){
    string line;
    vector<char> row;

    ifstream myfile ("day11/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            row = {};
            for (char c: line){
                row.push_back(c);
            }
            arr.push_back(row);
        }
        myfile.close();
    }
}

bool step(vector<vector<char>> &arr){
    char seat;
    int adj_r[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int adj_c[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<vector<char>> copy = arr;
    bool found;
    int counter;
    bool change = false;
    size_t check_r;
    size_t check_c;
    for (size_t row = 0; row < arr.size(); row++){
        for (size_t col = 0; col < arr[row].size(); col++){
            seat = arr[row][col];
            // Rule 1
            if (seat == 'L'){
                found = false;
                for (int i = 0; i < 8; i++){
                    check_r = row + adj_r[i];
                    check_c = col + adj_c[i];
                    while (check_r >= 0 && check_r < arr.size() && check_c >= 0 && check_c <= arr[row].size()){
                        if (arr[check_r][check_c] == '#'){
                            found = true;
                            break;
                        }
                        if (arr[check_r][check_c] == 'L'){
                            break;
                        }
                        check_r += adj_r[i];
                        check_c += adj_c[i];
                    }
                }
                if (!found){
                    copy[row][col] = '#';
                    change = true;
                }
            }
            // Rule 2
            if (seat == '#'){
                counter = 0;
                for (int i = 0; i < 8; i++){
                    check_r = row + adj_r[i];
                    check_c = col + adj_c[i];
                    while (check_r >= 0 && check_r < arr.size() && check_c >= 0 && check_c <= arr[row].size()){
                        if (arr[check_r][check_c] == '#'){
                            counter++;
                            break;
                        }
                        if (arr[check_r][check_c] == 'L'){
                            break;
                        }
                        check_r += adj_r[i];
                        check_c += adj_c[i];
                    }
                }
                if (counter >= 5){
                    copy[row][col] = 'L';
                    change = true;
                }
            }
        }
    }
    arr = copy;
    return change;
}

void print_seats(vector<vector<char>> &arr){
    for(size_t c = 0; c < arr.size(); c++){
        for (size_t d = 0; d <  arr[c].size(); d++){
            cout << arr[c][d];
        }
        cout  << endl;
    }
    cout << endl;
}

int count_seats(vector<vector<char>> &arr, const char seat){
    int counter = 0;
    for(size_t c = 0; c < arr.size(); c++){
        for (size_t d = 0; d <  arr[c].size(); d++){
            if (arr[c][d] == seat) counter++;
        }
    }
    return counter;
}

int main()
{
    vector<vector<char>> arr;
    bool change = true;
    get_data(arr);
    while (change){
        change = step(arr);
    }
    cout << count_seats(arr, '#') << endl;
    return 0;
}

