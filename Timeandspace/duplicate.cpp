#include<iostream>  
#include<vector>
#include<unordered_map>
using namespace std;
//Using hashmaps
vector<int> duplicate(vector<int>arr){
    unordered_map<int,bool>seen;
    vector<int>duplicate;
    for(int i =0;i<arr.size();i++){
        if(seen.count(arr[i]>0)){
            duplicate.push_back(arr[i]);
            continue;
        }
       seen[arr[i]]=true;
    }
    return duplicate;
}
//Second Approach
#include <algorithm>
int findDuplicate(int *arr, int n)
{
    //Write your code here
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];

        }
    }
}
