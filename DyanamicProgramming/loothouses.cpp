#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//brute force approach
int loothouses_helper(vector<int>&houses,int maxloot,int start){
    int n =houses.size();
    if(start>=n){
        return maxloot;
    }
    //if we choose the first element
    int x=INT_MIN;
    if(start+1<=n){
     x=loothouses_helper(houses,maxloot+houses[start],start+2);
    }
    //if we include the second element
    int y =INT_MIN;
    if(start+2<=n){
     y=loothouses_helper(houses,maxloot+houses[start+1],start+3);
    }
    int result=max(x,y);
    return result;
}
int loothouses(vector<int>&houses){
    int result=loothouses_helper(houses,0,0);
    return result;
}
//Memoization 
int loothouses_helper_1(vector<int>&houses,int maxloot,int start,vector<int>&ans){
    int n =houses.size();
    if(start>=n){
        return maxloot;
    }
    //if we choose the first element
    if(ans[n]!=-1){
        return ans[n];
    }
    int x=INT_MIN;
    if(start+1<=n){
     x=loothouses_helper(houses,maxloot+houses[start],start+2);
    }
    //if we include the second element
    int y =INT_MIN;
    if(start+2<=n){
     y=loothouses_helper(houses,maxloot+houses[start+1],start+3);
    }
    int result=max(x,y);
    ans[n]=result;
    return ans[n];
}
int loothouses_1(vector<int>&houses){
    int n =houses.size();
    int result=loothouses_helper(houses,0,0);
    vector<int>ans(n+1,-1);
    return loothouses_helper_1(houses,0,0,ans) ;
}

//DP
int loothouses_2(vector<int>&houses){
    int n=houses.size();
    vector<int>ans(n+1,0);
    ans[1]=houses[0];
    for(int i =2;i<=n;i++){
        ans[i]=max(houses[i-1]+ans[i-2],ans[i-1]);
    }
    return ans[n];

}
int main(){
    int n ;
    cin>>n;
    vector<int>houses(n);
    for(int i =0;i<n;i++){
        cin>>houses[i];
    }
    int result=loothouses_2(houses);
    cout<<"the maximum number of houses thief can loot is: "<<result<<endl;
}