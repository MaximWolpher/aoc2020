#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define MAXN 1000
vector<int> graph[MAXN];


vector<int> diff(const vector<int> &arr){
    int L = arr.size();
    vector<int> diff(L - 1);
    for (int i = 0; i < L - 1; i++){
        diff[i] = arr[i + 1] - arr[i];
    }

    return diff;
}

void add_edge(int a, int b, int fre[]){
    graph[a].push_back(b); 
    fre[b]++; 
}

vector<int> topological_sorting(int fre[], int n) 
{ 
    queue<int> q; 
  
    for (int i = 0; i < n; i++){
        if (fre[i] == 0){
            q.push(i); 
        }
    }
    vector<int> l; 
    int g_size;
  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
  
        l.push_back(u); 

        g_size = graph[u].size();
  
        for (int i = 0; i < g_size; i++) { 
            fre[graph[u][i]]--; 
  
            if (!fre[graph[u][i]]) 
                q.push(graph[u][i]); 
        } 
    } 
    return l; 
} 

long numberofPaths(int source, int destination, int n, int fre[]) 
{ 
  
    vector<int> s = topological_sorting(fre, n); 
    long dp[n]; 
    for (int i = 0; i < n; i++){
        dp[i] = 0;
    }

  
    dp[destination] = 1; 
    int g_size; 
    for (int i = s.size() - 1; i >= 0; i--) { 
        g_size = graph[s[i]].size();
        for (int j = 0; j < g_size; j++) { 
            dp[s[i]] += dp[graph[s[i]][j]]; 
        } 
    } 
  
    return dp[source]; 
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
    int source = 0;
    int destination = L;
    int fre[L];

    for (int i = 0; i < L; i++){
        fre[i] = 0;
    }

    for (int i = 0; i < L; i++){
        if ((diff_arr[i] + diff_arr[i + 1]) <= 3 && (i + 1) < L){
            add_edge(i, i + 2, fre);
        }
        if ((diff_arr[i] + diff_arr[i + 1] + diff_arr[i + 2]) <= 3 && (i + 2) < L){
            add_edge(i, i + 3, fre);
        }
        
        add_edge(i, i + 1, fre);
         
    }

    cout << numberofPaths(source, destination, L, fre);

    return 0;

}
