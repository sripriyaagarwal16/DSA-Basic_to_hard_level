#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void connectedcomponents(vector<vector<int>>&edges,int sv,vector<int>&ans,vector<bool>&visited){
     ans.push_back(sv);
     visited[sv]=true;
     int n =edges.size();
     for(int i =0;i<n;i++){
        if(i==sv){
          continue;
        }
        if(edges[sv][i]==1&&!visited[i]){
            connectedcomponents(edges, i,ans,visited);
        }
     }
}
void printcomponents(vector<vector<int>>&ans){
    for(int i =0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<endl;
        }
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
  
    
   
    int n =edges.size();
    vector<bool>visited(n,false);
    vector <vector <int> > ans;
    vector <int> temp;
    for(int i=0;i<n;i++){
        
        if(!visited[i]){
            connectedcomponents(edges,i,temp,visited);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        
    }
    
    printcomponents(ans);
    
}