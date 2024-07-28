#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isvalid(vector<vector<char>>&board,int x,int y){
    int m =board.size();
    int n =board[0].size();
    if(x<0||x>m||y<0||y>n){
        return false;
    }
    //upward condition
    for(int i =x;i>=0;i--){
        if(board[i][y]=='Q'){
            return false;
        }
    }
    //topleft diagonal
    for(int i =x;int j=y;i>=0&&j>=0,i--,j--){
        if(board[x][y]=='Q'){
            return false;
        }


    }
    //toprightdiagonal
    for(int i =x;int j=y;i>=0&&j>n,i--,j++){
        if(board[x][y]=='Q'){
            return false;
        }
        

    }

}

void printsolution(vector<vector<char>>&board){
    int m =board.size();
    int n =board[0].size();
     for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<endl;
        }
        cout<<endl;
     }
   return ;
}

void solve(int row,vector<vector<char>>&board){
    int m= board.size();//row
    int n =board[0].size();//column
    if(row==m){
        printsolution(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(isvalid(board,row,j)){
            board[row][j]='Q';//assigning q to the particular row and column
            solve(row+1,board);
            board[row][j]='X';//backtrack
        }
    }

}