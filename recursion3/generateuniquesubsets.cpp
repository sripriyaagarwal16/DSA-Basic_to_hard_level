#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void getuniquesubsethelper(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);

    for (int i = index; i < arr.size(); i++) {
       
        if (i > index && arr[i] == arr[i - 1]) {
            continue;
        }
        
        current.push_back(arr[i]);
       
        getuniquesubsethelper(arr, i + 1, current, result);
     
        current.pop_back();
    }
}

vector<vector<int>> getuniquesubset(vector<int>&arr){
    vector<int>current;
    vector<vector<int>>result;
    sort(arr.begin(),arr.end());
    getuniquesubsethelper(arr,0,current,result);
    return result;
}