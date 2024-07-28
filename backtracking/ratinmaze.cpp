#include<iostream>
#include<vector>
using namespace std;
bool checkvalid(vector<vector<int>>&matrix,int x,int y,vector<vector<int>>&visited){
    int row=matrix.size();
    int col=matrix[0].size();
    if(x<1||x>row||y<1||y>col){
        return false;
    }
    if(visited[x][y]==1||matrix[x][y]=='X'){
        return false;
    }
    return true;
}

void printsolution(vector<vector<int>>&matrix){
    int row=matrix.size();
    int col=matrix[0].size();
    for(int i =1;i<=row;i++){
        for(int j =1;j<=col;j++){
            cout<<matrix[i][j];
        }
    }
}
void ratinmaze(vector<vector<int>>&matrix,int x,int y){
    int n =matrix.size();
    vector<vector<int>>visited(n);
    visited[x][y]=1;
    if(x==n&&y==n){
        visited[x][y]=0;
        printsolution(matrix);
        return;
    }
    //upwards
    if(checkvalid(matrix,x-1,y,visited)){
        ratinmaze(matrix,x-1,y);
    }
    //downwards
    if(checkvalid(matrix,x+1,y,visited)){
        ratinmaze(matrix,x+1,y);
    }
    //left
    if(checkvalid(matrix,x,y-1,visited)){
        ratinmaze(matrix,x,y-1);
    }
    //right
    if(checkvalid(matrix,x,y+1,visited)){
        ratinmaze(matrix,x,y+1);
    }
    visited[x][y]=0;
    return;

}