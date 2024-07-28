#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isvalid(vector<vector<char>>&matrix,int x,int y,char ch,vector<vector<int>>&visited){
    int n=matrix.size();
    int m =matrix[0].size();
    if(x<1||x>n||y<1||y>m){
        return false;
    }
    if(visited[x][y]==1||matrix[x][y]!=ch){
        return false;
    }
    return true;
}

bool wordsearch(int x,int y ,vector<vector<char>>&matrix,string word,int idx){
    bool result=false;
    int n =matrix.size();
    vector<vector<int>>visited(n);
    if(idx==matrix.size()-1){
        result=true;
        visited[x][y]=0;
        return result;
    }
    if(isvalid(matrix,x-1, y,word[idx+1],visited)){
        return wordsearch( x-1, y ,matrix, word,idx);
    }
    if(isvalid(matrix,x+1, y,word[idx+1],visited)){
        return wordsearch( x+1, y ,matrix, word,idx);
    }
    if(isvalid(matrix,x, y-1,word[idx+1],visited)){
        return wordsearch( x, y-1 ,matrix, word,idx);
    }
    if(isvalid(matrix,x, y+1,word[idx+1],visited)){
        return wordsearch( x, y+1 ,matrix, word,idx);
    }
    visited[x][y]=0;
    return false;
}

