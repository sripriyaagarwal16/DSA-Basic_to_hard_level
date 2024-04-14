#include<iostream>
#include<climits>
#include<string>
using namespace std;
//using brute force method9rescut=rsion )
int lcs (string s ,string t){
    //Base case
    if(s.size()==0||t.size()==0){
        return 0 ; 
    }
    if(s[0]==t[0]){
        return 1+lcs (s.substr(1) , t.substr(1));
    }
    else{
        int a = lcs (s.substr(1) ,t);
        int b=  lcs (s , t.substr(1));
        int c= lcs (s.substr(1) , t.substr(1));
        return max(a,max(b,c));
    }
}

//Memoization
int lcshelper(string s ,string t,int ** arr){
      if(s.size()==0||t.size()==0){
        return 0 ; 
    }
    int m= s.size();
    int n= t.size();
    if(arr[m][n]!=-1){
        return arr[m][n];
    }
    if(s[0]==t[0]){
        int ans =lcshelper(s.substr(1) , t.substr(1),arr)+1;
        arr[m][n]=ans;
    }
    
    else{
    int a = lcshelper (s.substr(1) ,t,arr);
    int b=  lcshelper(s , t.substr(1),arr);
    int c= lcshelper(s.substr(1) , t.substr(1),arr);
    arr[m][n]=max(a,max(b,c));
    }
     return arr[m][n];
}
int lcs_2(string s ,string t){
    int m =s.size();
    int n =t.size();
    int **arr=new int*[m+1];
    for(int i =0;i<=m;i++){
        arr[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            arr[i][j]=-1;
        } 
    }
    return lcshelper(s , t,arr);
}
//DP 
int lcs_3(string s , string t){
    int m =s.size();
    int n =t.size();
    int ** output=new int*[m+1];
    for(int i =0;i<=m;i++){
        output[i]=new int[n+1];
    }
    //Filling row
    for(int i =0;i<=0;i++){
        for(int j =0;j<=n;j++){
          output[i][j]=0;
        }
    }
    //filling column 
    for(int j =0;j<=0;j++){
        for(int i=0;i<=m;i++){
            output[i][j]=0;
        }
    }
    //filling remaining cell 
    for(int i =1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                output[i][j]=output[i-1][j-1]+1;
            }
            else{
                int a = output[i][j-1];
                int b=output[i-1][j];
                int c =output[i-1][j-1];
                output[i][j]=max(a,max(b,c));

            }

        }
    }
    return output[m][n];
}

