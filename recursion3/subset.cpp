#include<iostream>
#include<vector>
using namespace std;

int subset(int input[],int n,int output[][20]){
     if(n==0){
        output[0][0]=0;
        return 1;
     }
     
     int smalloutputsize=subset(input+1,n-1,output);
     for(int i =0;i<smalloutputsize;i++){
        output[i+smalloutputsize][0]=input[0];
        for(int j =1;j<smalloutputsize+1;j++){
            output[i+smalloutputsize][j]=output[i][j-1];
        }
     }
     return smalloutputsize*2;
}