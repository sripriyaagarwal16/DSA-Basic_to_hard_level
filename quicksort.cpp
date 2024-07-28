#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr,int low,int high){
    int count=0;
    int pivot=arr[low];
    for(int i=low+1;i<=high;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotindex=low+count;
    arr[pivotindex]=pivot;
    int i =low;
    int j=high;
    while(i<pivotindex&&j>pivotindex){
         while(arr[i]<=pivot){
            i++;
         }
         while(arr[j]>pivot){
            j++;
         }
         if(i<pivotindex&&j>pivotindex){
            swap(arr[i++],arr[j++]);
         }
    }
}
void quicksort(vector<int>&arr,int low,int high){
   if(low>=high){
    return;
   }
   int p=partition(arr,low,high);
   quicksort(arr,p+1,high);
   quicksort(arr,low,p-1);


}
