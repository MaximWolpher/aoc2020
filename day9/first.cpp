#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;


bool find_sum(queue<long> &q, const long candidate){
    int qs = q.size();
    long arr[qs];
    long s;
    bool flag = false;
    for (int i = 0; i < qs; i++){
        arr[i] = q.front();
        q.pop();
    }
    for (int i = 0; i < qs; i++){
        for (int j = i; j < qs; j++){
            s = arr[i] + arr[j];
            if(s == candidate){
                flag = true;
                break;
            }

        }
        if(flag) break;
    }
    return flag;

}


int main()
{
    string line;
    string op;
    vector<long> arr;
    queue<long> q;
    queue<long> qc;
    int preamble = 25;

    ifstream myfile ("day9/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            arr.push_back(stol(line));
        }
        myfile.close();
    }

    for (int i = 0; i < preamble; i++){
        q.push(arr[i]);
    }
    
    int L = arr.size();
    for (int i = preamble; i < L; i++){
        qc = q;
        if(!find_sum(qc, arr[i])){
            cout << arr[i];
            break;
        }
        else{
            q.pop();
            q.push(arr[i]);
        }
        
    }
    return 0;

}
