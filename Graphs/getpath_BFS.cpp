#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int>getpathBFS(vector<vector<int>>&edges,int v1,int v2,vector<bool>&visited){
    if(v1==v2){
        return {v1};
    }
    queue<int>pending;
    pending.push(v1);
    visited[v1]=true;
    vector<int>path;
    unordered_map<int,int>parent;
    parent[v1]=-1;
    int n =edges.size();
    while(!pending.empty()){
        int currentvertex=pending.front();
        pending.pop();
        for(int i=0;i<n;i++){
           if (edges[currentvertex][i]==1&&!visited[i]){
                pending.push(i);
                visited[i]=true;
                parent[i]=currentvertex;
                if(i==v2){
                  vector<int>path;
                  int end=v2;
                  path.push_back(end);
                  while(parent[end]!=-1){
                     path.push_back(parent[end]);
                     end=parent[end];
                  }
                  return path;
               }
            }

            
        }
    }

  return {};
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    vector<bool> visited(n, false);
    vector<int> ans = getpathBFS(edges, v1, v2, visited);

    if (!ans.empty()) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    return 0;
}