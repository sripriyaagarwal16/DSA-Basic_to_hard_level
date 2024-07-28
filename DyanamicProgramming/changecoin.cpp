
#include <iostream>
#include <vector>
#include<algorithm>
#include<climits>
using namespace std;

//Brute Force Approach :O(K^n+1) where k=no of unique coins, n =amount
    // int changehelper(vector<int>&coins,int amount){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(amount<0){
    //         return -1;
    //     }
    //     int mincoin=INT_MAX;
    //     for(int coin:coins){
    //         int result=changehelper(coins,amount-coin);
    //         if(result!=-1){
    //            mincoin=min(mincoin,result+1);
    //         }
    //     }
    //     if(mincoin!=INT_MAX){
    //         return mincoin;
    //     }else{
    //         return -1;
    //     }
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int result=changehelper(coins,amount);
    //     return result;
    // }
    //Memoization
    //Time Complexity:O(k.n) where k =no of unique coins and n=amount
    //  int changehelper(vector<int>&coins,int amount,vector<int>&ans){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(amount<0){
    //         return -1;
    //     }

    //     int mincoin=INT_MAX;
    //     if(ans[amount]!=-1){
    //         return ans[amount];
    //     }
    //     for(int coin:coins){
    //         int result=changehelper(coins,amount-coin,ans);
    //         if(result!=-1){
    //            mincoin=min(mincoin,result+1);
    //         }
    //     }
        
    //     if(mincoin!=INT_MAX){
    //         ans[amount]=mincoin;
    //         return ans[amount];
    //     }
        
    //     return -1;
       
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int>ans(amount+1,-1);
    //     int result=changehelper(coins,amount,ans);
    //     return result;
    // }

    //DP
       int coinChange(vector<int>& coins, int amount) {

        vector<int>ans(amount+1,INT_MAX);
        ans[0]=0;
        for(int i =1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0&&ans[i-coins[j]]!=INT_MAX){
                    ans[i]=min(ans[i],1+ans[i-coins[j]]);
                }
            }
        }

        return  ans[amount]!=INT_MAX?ans[amount]:-1;

        
    }

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    int value;
    cin >> value;
    
    int ways = coinChange(coins, value);
    cout << ways << endl;
    
    return 0;
}
