#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
 
 int  pairsumk(vector<int>arr,int k){
 unordered_map<int,int>freq;
    for(int i =0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    int count=0;
    for (int i = 0; i < arr.size(); i++) {
        if (freq.find(arr[i] - k) != freq.end() && arr[i] - k != arr[i]) {
            count += freq[arr[i] - k];
        }
    }
    return count;
 
 }
 int main(){
        int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cout<<"Enter the element:";
        cin>>arr[i];
    }
    int k ;
    cout<<"Enter the value of K :";
    cin>>k;
    int count= pairsumk(arr, k);
    cout<<"The count of pairs is :"<<count<<endl;
 }