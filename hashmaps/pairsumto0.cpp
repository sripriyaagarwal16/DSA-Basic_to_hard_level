#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std; 

int pairsumto0(vector<int>arr){
    unordered_map<int,int>freq;
    for(int i =0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    int count=0;
    for(int i =0;i<arr.size();i++){
        if(freq[arr[i]]>0){
            count+=freq[-arr[i]];
        }
        if(arr[i]==0){
            count--;
        }
    }
    return count/2;
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
    int count=pairsumto0(arr);
    cout<<"The count of the nubmer sumiing upto 0 is : "<<count<<endl;
    

}