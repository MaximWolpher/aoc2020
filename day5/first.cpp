#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    string line;
    int seat_id;
    int row;
    int column;
    int max_id = 0;
    int min_id = 100000;
    string row_str;
    string col_str;
    ifstream myfile ("day5/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
           row_str = line.substr(0,8);
           col_str = line.substr(8);
           replace(row_str.begin(), row_str.end(), 'F', '0');
           replace(row_str.begin(), row_str.end(), 'B', '1');
           replace(col_str.begin(), col_str.end(), 'R', '1');
           replace(col_str.begin(), col_str.end(), 'L', '0');
           row = stoi(row_str, nullptr, 2);
           column = stoi(col_str, nullptr, 2);
           seat_id = row * 8 + column;
           if (seat_id > max_id){
               max_id = seat_id;
           }
           if (seat_id < min_id){
               min_id = seat_id;
           }
        }
        cout << min_id << " - " << max_id << endl;
        myfile.close();
    }
    else
    {
        cout << "Didnt work bro";
    }
}
