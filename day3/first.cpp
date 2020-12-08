#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    vector<vector<char>>  arr;
    string line;
    ifstream myfile ("day3/example");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){

            vector<char> c_vec(line.begin(), line.end());
            arr.push_back(c_vec);
        }

        myfile.close();
    }
    else
    {
        cout << "Didnt work bro";
    }

    int height = arr.size();
    int width = arr[0].size();
    int right = 3;
    int down = 1;
    int pos_h = 0;
    int pos_w = 0;
    char cur_pos;
    int trees = 0;

    while (pos_h < height - down){
        pos_h += down;
        pos_w = (pos_w + right) % width;
        cur_pos = arr[pos_h][pos_w];
        if (cur_pos == '#') trees++;

    }
    cout << trees;

}
