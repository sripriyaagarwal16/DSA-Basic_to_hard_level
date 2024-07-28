#include<iostream>
#include<vector>
using  namespace std;

void merge(vector<int>&arr,int left,int right,int mid){
    int length1=mid-left+1;
    int length2=right-mid;
    vector<int>leftarray(length1);
    vector<int>rightarray(length2);
    for(int i =0;i<length1;i++){
        leftarray[i]=arr[left+i];
    }
    for(int i=0;i<length2;i++){
        rightarray[i]=arr[mid+i+1];
    }
    int leftarrayindex=0;
    int rightarrayindex=0;
    int mergedarrayindex=0;
    while(leftarrayindex<length1&&rightarrayindex<length2){
        if(leftarray[leftarrayindex]<=rightarray[rightarrayindex]){
            arr[mergedarrayindex]=leftarray[leftarrayindex];
            leftarrayindex++;
            mergedarrayindex++;
        }
        if(leftarray[leftarrayindex]>rightarray[rightarrayindex]){
            arr[mergedarrayindex]=rightarray[rightarrayindex];
            rightarrayindex++;
            mergedarrayindex++;
        }
    }
    while(leftarrayindex<length1){
        arr[mergedarrayindex]=leftarray[leftarrayindex];
    }
      while(rightarrayindex<length2){
        arr[mergedarrayindex]=rightarray[rightarrayindex];
    }


} 
void mergesort(vector<int>&arr,int begin,int end){
    if(begin>=end){
        return;
    }
    int mid=begin+(end-begin)/2;
    mergesort(arr,mid+1, end);
    mergesort(arr, begin,mid-1 );
    merge(arr,begin,end,mid);

}