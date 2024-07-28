#include<iostream>
#include<vector>
using namespace std;
//brute force approach 
//time complexity:O(n*2^n)
int fibonacci_1(int n){
   if(n<=1){
    return n;
   }
   int a=fibonacci_1(n-1);
   int b =fibonacci_1(n-2);
   int c=a+b;
   return c;
}
//Memoization
//1.if the number already exist in the array then return 
//2.if it doesnt exist then calculate and then save it in the array and then return
//time complexity :O(n)
//top-down approach 
int fibbonacii_helper(int n ,int * ans){
    if(n<=1){
        return n ;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=fibbonacii_helper( n-1 , ans);
    int b=fibbonacii_helper( n-2 , ans);
    int c=a+b;
    ans[n]=c;
    return ans[n];



}
int fibbonacii_2(int n ){
    int *ans=new int[n+1];
    for(int i =0;i<n;i++){
        ans[i]=-1;
    }
    fibbonacii_helper(n ,ans);

}

//dynamaic programming 
//botton up approach 
//time complexity:O(n)
int fibbonacii_3(int n){
    int *ans=new int[n+1];
    //base case
    ans[0]=0;
    ans[1]=1;
    for(int i =2;i<=n;i++){
       ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}