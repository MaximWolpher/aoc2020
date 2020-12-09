#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <numeric>
#include <algorithm>

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

vector<long> get_data(){
    string line;
    vector<long> arr;
    ifstream myfile ("day9/data");
    if (myfile.is_open())
    {
        while (getline(myfile, line)){
            arr.push_back(stol(line));
        }
        myfile.close();
    }
    return arr;

}

long find_invalid(vector<long> arr, int preamble){
    int L = arr.size();
    queue<long> q;
    queue<long> qc;
    long result = 0;
    for (int i = 0; i < preamble; i++){
        q.push(arr[i]);
    }
    for (int i = preamble; i < L; i++){
        qc = q;
        if(!find_sum(qc, arr[i])){
            result = arr[i];
            break;
        }
        else{
            q.pop();
            q.push(arr[i]);
        }
    }
    return result;
}

long find_contig(vector<long> arr, long invalid){
    int L = arr.size();
    long result = 0;
    long current_sum;
    bool found = false;
    long max_elem;
    long min_elem;
    for (int lower = 0; lower < L - 1; lower++){
        current_sum = arr[lower];
        for (int upper = lower + 1; upper < L; upper++ ){
            //current_sum = accumulate(arr.begin() + lower, arr.begin() + upper, decltype(arr)::value_type(0));
            current_sum += arr[upper];
            if (current_sum > invalid) break;
            if (current_sum == invalid){
                max_elem = *max_element(arr.begin() + lower, arr.begin() + upper);
                min_elem = *min_element(arr.begin() + lower, arr.begin() + upper);
                result = min_elem + max_elem;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    return result;
}


int main()
{
    string line;
    string op;
    vector<long> arr;
    queue<long> q;
    queue<long> qc;
    int preamble = 25;

    arr = get_data();
    long invalid = find_invalid(arr, preamble);
    cout << invalid << endl;
    long result = find_contig(arr, invalid);
    cout << result;
    
    return 0;

}
