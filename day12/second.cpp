#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Ship{
    public:
    long x_coord = 0;
    long y_coord = 0;
    int waypoint[2] = {10, 1}; 
    int x_dir[4] = {1, 0, -1, 0};
    int y_dir[4] = {0, -1, 0, 1};

    void move(string command);
    void show();

};

void Ship::show(){
    cout << "Location: (" << this->x_coord << ", " << this->y_coord << ")" << endl;
    cout << "Waypoint: " << this->waypoint[0] << ", " << this->waypoint[1] << endl; 
}

void Ship::move(string command){
    char letter = command.at(0);
    int number = stoi(command.substr(1));
    int dir;
    if (letter == 'L'){
        int nr_turns = (number / 90);
        for (int i = 0; i < nr_turns; i++){
            swap(this->waypoint[0], this->waypoint[1]);
            this->waypoint[0] = -this->waypoint[0];
        }
    }
    else if (letter == 'R'){
        int nr_turns = (number / 90);
        for (int i = 0; i < nr_turns; i++){
            swap(this->waypoint[0], this->waypoint[1]);
            this->waypoint[1] = -this->waypoint[1]; 
        }
    }
    else if (letter == 'F'){
        this->x_coord += number * this->waypoint[0];
        this->y_coord += number * this->waypoint[1];
    }
    else{
        switch(letter){
            case 'E':
                dir = 0;
                break;
            case 'S':
                dir = 1;
                break;
            case 'W':
                dir = 2;
                break;
            case 'N':
                dir = 3;
                break;
        }
        this->waypoint[0] += number * this->x_dir[dir];
        this->waypoint[1] += number * this->y_dir[dir];
    }
}

void get_data(vector<string> &arr){
    string line;

    ifstream myfile ("day12/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            arr.push_back(line);
        }
        myfile.close();
    }
}


int main()
{
    vector<string> arr;
    get_data(arr);
    Ship ship;
    for (string s: arr){
        ship.move(s);
    }
    cout << abs(ship.x_coord) + abs(ship.y_coord) << endl;
    return 0;
}

