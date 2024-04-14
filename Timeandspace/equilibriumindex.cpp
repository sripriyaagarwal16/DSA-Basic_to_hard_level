#include<iostream>  
#include<vector>
using namespace std; 
//Basic Approach 
void index_1(vector<int>arr){
    int i =0; 
    while(i<arr.size()){
        int ls=0;
        int j =i-1;
        while(j<i&&j>=0){
            ls+=arr[j];
            j--;
        }
        int k =i+1;
        int rs=0;
        while(k<arr.size()){
             rs+=arr[k];
             k++;
        }
        if(rs==ls){
            cout<<i<<endl;
        }
    }
}

void index_2(vector<int>arr){
    int ls=0;
    int rs=0;
   for(int i =0;i<arr.size();i++){
       rs+=rs+arr[i];
   }
   for(int k=0;k<arr.size();k++){
    ls=ls-arr[k];
    rs=rs+arr[k];
     if(rs==ls){
        cout<<k<<endl;
     }
   }
}
