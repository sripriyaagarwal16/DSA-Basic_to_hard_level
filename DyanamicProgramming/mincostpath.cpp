#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int mincostfunction(vector<vector<int>>&matrix,int row,int column){
    int m =matrix.size();
    int n =matrix[0].size();
    if(row==m-1 &&column==n-1){
        return matrix[row][column];
    }
    int x=INT_MAX;
    int y=INT_MAX;
    int z=INT_MAX;

    if(column!=n-1){
        x=mincostfunction(matrix,row, column+1);  //exploring right
    }
    if(row!=m-1){
       y=mincostfunction(matrix,row+1, column);   //exploring down

    }
    if(row!=m-1&&column!=n-1){
       z=mincostfunction(matrix,row+1, column+1); //exploring diagonally
    }
    int result=min(x,min(y,z))+matrix[row][column];
    return result;
}
int mincostfunction_1(vector<vector<int>>&matrix){
    
    int m =matrix.size();
    int n=matrix[0].size();
    vector<vector<int>> output(m, vector<int>(n, 0));
    output[m-1][n-1]=matrix[m-1][n-1];
    //filling the last row (m-1)
    for(int j =n-2;j>=0;j--){
        output[m-1][j]=output[m-1][j+1]+matrix[m-1][j];
    }
    //filling the last column(n-1)
    for(int i =m-2;i>=0;i--){
        output[i][n-1]=output[i+1][n-1]+matrix[i][n-1];
    }
    //filling the remaining columns
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=matrix[i][j]+min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]));
        }
    }
    return output[0][0];

    
}
int main(){
    int m ;
    cin>>m;
    int n ;
    cin>>n;
    vector<vector<int>>matrix(m,vector<int>(n));
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            int input;
            cin>>input;
            matrix[i][j]=input;
        }
    }
    int result=mincostfunction_1(matrix);
    cout<<"the min cost to move from (0,0) to"<<" "<<m-1<<" and "<<" "<<n-1<<" is :"<<" "<<result<<endl;

}