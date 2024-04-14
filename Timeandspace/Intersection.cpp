#include<iostream>
#include<vector>
#include <algorithm>  
using namespace std; 
//Linear Search Method
vector<int>intersection_1(vector<int>arr1,vector<int>arr2){
    vector<int>output;
    for(int i =0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            if(arr2[j]==arr1[i]){
                output.push_back(arr1[i]);

            }

        }
    }
     return output; 

}
//Sorting both arrays
vector<int>intersection_2(vector<int>arr1,vector<int>arr2){
    vector<int>output;
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    int i =0;//for arr1 
    int j =0;//for arr2
     while(i<arr1.size()&&j<arr2.size()){
        if(arr1[i]==arr2[j]){
            output.push_back(arr1[i]);
        }
        else if(arr2[j]>arr1[i]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
     }
     return output; 
}

//Sorting and using binary search method
vector<int>intersection_3(vector<int>arr1,vector<int>arr2){
    vector<int>output;
    if(arr1.size()<arr2.size()){
       sort(arr1.begin(),arr1.end());//sorting on arr1
       for(int i =0;i<arr1.size();i++){
        int start=0;
        int end=arr2.size()-1;
        int mid=(start+mid)/2;
        while(start<=end){
            if(arr2[mid]==arr1[i]){
                output.push_back(arr1[i]);
            }
            else if(arr2[mid]>arr1[i]){
                end=mid-1;

            }
            else{
                start=mid+1;
            }
        }
    }
  }
   if(arr1.size()>arr2.size()){
       sort(arr2.begin(),arr2.end());//sorting on arr2
       for(int i =0;i<arr2.size();i++){
        int start=0;   //binary search on arr1
        int end=arr1.size()-1;
        int mid=(start+mid)/2;
        while(start<=end){
            if(arr1[mid]==arr2[i]){
                output.push_back(arr1[i]);
            }
            else if(arr1[mid]>arr2[i]){
                end=mid-1;

            }
            else{
                start=mid+1;
            }
        }
    }
  }

}
