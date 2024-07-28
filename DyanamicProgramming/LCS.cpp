#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int LCS(string S,string T){
    //base case 
    if(T.size()==0||S.size()==0){
        return 0;
    }
    //If the first character matches
    if(S[0]==T[0]){
      return 1+LCS(S.substr(1),T.substr(1));
    }
    //Of the first character do not matches
    int a =LCS(S.substr(1),T);
    int b=LCS(S,T.substr(1));
    // int c=LCS(S.substr(1),T.substr(1));
    int result=max(a,b);
    return result;
}

//memoization
int LCS_helper(string S,string T,vector<vector<int>>&ans){
    if(S.size()==0||T.size()==0){
        return 0;
    }
    int m =S.size();
    int n= T.size();
    if(ans[m][n]!=-1){
        return ans[m][n];
    }
    if(S[0]==T[0]){
      int result=1+LCS_helper(S.substr(1),T.substr(1),ans);
      ans[m][n]=result;
      return ans[m][n];
    }
    int a=LCS_helper(S.substr(1), T,ans);
    int b=LCS_helper(S, T.substr(1),ans);
    int result=max(a,b);
    ans[m][n]=result;
    return ans[m][n];
  
}
int LCS_1(string S,string T){
    int m =S.size();
    int n =T.size();
    vector<vector<int>>ans(m+1,vector<int>(n+1,-1));
    return LCS_helper(S, T,ans);

}
//DP
int LCS_3(string S,string T){
    int m =S.size();
    int n =T.size();
    vector<vector<int>>ans(m+1,vector<int>(n+1,-1));
    //we will fill the 1st column
    for(int i =0;i<=m;i++){
        for(int j =0;j<=0;j++){
            ans[i][j]=0;
        }
    }
    //filling the 1st row
    for(int i =0;i<=0;i++){
        for(int j=0;j<=n;j++){
            ans[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j =1;j<=n;j++){
            if(S[m-i]==T[n-i]){
                ans[i][j]=1+ans[i-1][j-1];
            }
            else{
                int a =ans[i][j-1];
                int b =ans[i-1][j];
                ans[i][j]=max(a,b);
            }
        }
    }
   return ans[m][n];
}
int main(){
    string S;
    cin>>S;
    string T;
    cin>>T;
    int result=LCS_3(S,T);
    cout<<"The LCS for "<<" "<<S<<" and "<<T<<" is: "<<result<<endl;
}

