#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void printsubsetsumhelper(int input[],int n ,int index,int k ,int current[],int count){
    if (k==0){
        for(int i=0;i<count;i++){
            cout<<current[i]<<" ";
        }
    }
   for(int i =index;i<n;i++){
     current[count++]=input[i];
     printsubsetsumhelper(input, n ,i+1, k-input[i] ,current,count);
     count--;//backtrack
   }
    
}
void printSubsetSumToK(int input[], int size, int k) {
    int current[50];  // Assuming the maximum size of a subset is 50
   printsubsetsumhelper(input,size ,0, k ,current,0);
}

   
   



int main() {
    // Example usage
    int input[9] = {5 ,12, 3, 17, 1, 18 ,15, 3 ,17 };
    int k = 6;

    // Get subsets with sum equal to k
    printSubsetSumToK(input, 9, k) ;
   

    return 0;
}