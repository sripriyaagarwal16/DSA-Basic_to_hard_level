#include<iostream>  
#include<vector>
#include<unordered_map>
using namespace std; 
//hashmaps with tc O(n)
vector<int> unique_1 (vector<int>arr){
    unordered_map<int,bool>seen;
    vector<int>unique;
    for(int i =0;i<arr.size();i++){
    if(seen.count(arr[i])>1){
      continue;
    }
    seen[arr[i]]=true;
    unique.push_back(arr[i]);
}
 return unique;
}

//2nd approach 
#include <algorithm>
int findUnique(int *arr, int n) {
    // Write your code here
    sort(arr, arr + n);
    for (int i = 0; i < n; i+=2) {
        if (arr[i] != arr[i + 1]) {
            return arr[i];
            break;
        }
    }

}
