#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void printBFS(vector<vector<int>>&edges,int sv,vector<bool>&visited){
    queue<int>pendingvertices;
    int n =edges.size();
    pendingvertices.push(sv);
    while(!pendingvertices.empty() ){
        int currentvertex=pendingvertices.front();
        pendingvertices.pop();
        cout<<currentvertex<<endl;
        for(int i =0;i<n;i++){
            if(i==sv){
                continue;
            }
            if(edges[sv][i]==1&&!visited[i]){
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }

}
void BFS(vector<vector<int>>&edges){
    int n=edges.size();
    vector<bool>visited(n,false);
    for(int i =0;i<n;i++){
        printBFS(edges, 0,visited);
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
  
    BFS(edges);
}