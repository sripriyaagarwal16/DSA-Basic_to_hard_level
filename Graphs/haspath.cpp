#include<iostream>
#include<vector>
using namespace std;

bool haspath(vector<vector<int>>&edges,vector<bool>&visited,int v1,int v2){
    if(edges[v1][v2]==1){
        return true;
    }
    bool path=false;
    visited[v1]=true;
    int n =edges.size();
    for(int i =0;i<n;i++){
       if(edges[v1][i]==1&&!visited[i]){
       if(haspath(edges,visited,i, v2)){
        return true;
       }
       }
    }
   return false;
}
int main(){
    int n ;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>>edges(n,vector<int>(n,0));
    for(int i =0;i<e;i++){
        int f;
        int s;
        cin>>f;
        cin>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    } 
    int v1;
    cin>>v1;
    int v2;
    cin>>v2;
    vector<bool>visited(n,false);
    bool result=haspath(edges,visited,v1, v2);
    cout<<result<<endl;
}