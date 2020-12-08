#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    vector<vector<char>>  arr;
    string line;
    ifstream myfile ("day3/data");
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
    int right[] = {1, 3, 5, 7, 1};
    int down[] = {1, 1, 1, 1, 2};
    int pos_h;
    int pos_w;
    int trees;
    long result = 1;
    for (int i = 0; i < 5; i++){
        pos_h = 0;
        pos_w = 0;
        trees = 0;
        while (pos_h < height - down[i]){
            pos_h += down[i];
            pos_w = (pos_w + right[i]) % width;
            if (arr[pos_h][pos_w]== '#') trees++;
        }
        cout << trees << endl;
        result *= trees;
    }
    cout << result;
}
