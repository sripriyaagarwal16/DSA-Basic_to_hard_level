#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

//brute force
//if n=6;
// // 6   
//  /  |  \
// 5   2   3
// /   /\  /\
// 4  1  1 2 1

int minsteps(int n) {
    if(n==1){
        return 0;
    }
    int a= minsteps( n-1);
    int b=INT_MAX;
    if(n%2==0){
        b= minsteps( n/2);
    }
    int c=INT_MAX;
    if(n%3==0){
        c= minsteps( n/3);
    }
    int finalresult=min(a,min(b,c))+1;
    return finalresult;
} 

//Memoization 
 int minstepsto1_helper(int n ,int *ans){
    if(n==1){
        return 0;
    }
    //check if it already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    //if answer doesnt exists
     int a= minstepsto1_helper( n-1,ans);
    int b=INT_MAX;
    if(n%2==0){
        b= minstepsto1_helper( n/2,ans);
    }
    int c=INT_MAX;
    if(n%3==0){
        c= minstepsto1_helper( n/3,ans);
    }
    int finalresult=min(a,min(b,c))+1;
    ans[n]=finalresult;
    return ans[n];
    
 }
int minstepsto1_2(int n ){
    int *ans=new int[n];
    for(int i =1;i<=n;i++){
        ans[i]=-1;
    }
    int finalresult=minstepsto1_helper(n ,ans);
    return finalresult;
}
 //Dynamic programming
 int minstepsto1_3(int n ){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=0;
    for(int i=2;i<=n;i++){
        int x=ans[i-1];
        int y =INT_MAX;
        if(i%2==0){
            y=ans[i/2];
        }
        int z=INT_MAX;
        if(i%3==0){
            z=ans[i/3];
        }
        ans[i]=min(x,min(y,z));
    }
    int result=ans[n];
    delete []ans;
    return result;



 }
 