#include<iostream>
#include<queue>
using namespace std; 

bool checkmaxheap(int arr[],int n ){
    for(int i =0;i<n;i++){
        int leftchildindex=2*i+1;
        int rightchildindex=2*i+2;
        if(leftchildindex<n&&arr[leftchildindex]>arr[i]){
            return false;
        }
        if(rightchildindex<n&&arr[rightchildindex]>arr[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n ;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
       cin>>arr[i];
    }
    bool maxheap=checkmaxheap(arr, n );
    cout<<maxheap;

}