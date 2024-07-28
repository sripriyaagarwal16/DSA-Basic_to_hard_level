#include<iostream>
#include<vector>
using namespace std;

//brute force approach 
int staircase(int n ){
    //base case 
    if(n==0||n==1){
        return 1;
    }
    int a = staircase( n-1);
    int b =0;
    if(n>=2){
     b=staircase(n-2);
    }
    int c=0;
    if(n>=3){
     c=staircase(n-3);
    }
    return a+b+c;
}
int  staircase_helper(int n ,int*ans){
    //base case 
    if(n==0||n==1){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];

    }
    int a = staircase( n-1);
    int b =0;
    if(n>=2){
     b=staircase(n-2);
    }
    int c=0;
    if(n>=3){
     c=staircase(n-3);
    }
    int result=a+b+c;
    ans[n]=result;
    return ans[n];
}
int staircase_2(int n ){
    int *ans=new int[n+1];
    for(int i =0;i<=n;i++){
        ans[i]=-1;
    }
    int result=staircase_helper(n ,ans);
    return result;
}
//DP  Approach 
int staircase_3(int n) {
    if (n == 0) return 1; // Base case: there's one way to stay at the ground step

    int *ans = new int[n + 1]();
    
    ans[0] = 1; // There's one way to stay at the ground step (doing nothing)
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i - j >= 0) {
                ans[i] += ans[i - j];
            }
        }
    }
    
    int result = ans[n];
    delete[] ans; // Free the dynamically allocated memory
    
    return result;
}

int main(){
    int n ;
    cin>>n;
    int result=staircase_3(n );
    cout<<result;
    
}