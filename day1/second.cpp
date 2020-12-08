#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    vector<int>  arr;
    string line;
    ifstream myfile ("day1/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            int line_int = stoi(line);
            arr.push_back(line_int);
        }
        myfile.close();
    }
    else
    {
        cout << "Didnt work bro";
    }
    int arr_size = arr.size();
    for (int i = 0; i < arr_size; i++){
        for (int j = 0; j < i; j++){
            if (arr[i] + arr[j] > 2020)
            {
                continue;
            }
            for (int k = 0; k < j; k++){
                // cout << arr[i] + arr[j] << endl;
                if (arr[i] + arr[j] + arr[k] == 2020)
                {
                    cout << arr[i] * arr[j] * arr[k]<< endl;
                }
            }
        }
    }
}
