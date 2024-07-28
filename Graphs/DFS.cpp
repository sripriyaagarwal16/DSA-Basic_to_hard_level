#include<iostream>
#include<vector>
using namespace std;
void printDFS(vector<vector<int>>&edges,int n ,int sv,vector<bool>&visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i =0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}
void DFS(vector<vector<int>>&edges){
    int n =edges.size();
    vector<bool>visited(n,false);
    for(int i =0;i<n;i++){
        printDFS(edges,n,0,visited);
    }

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
    DFS(edges);

}
