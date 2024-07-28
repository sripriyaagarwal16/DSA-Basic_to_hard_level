#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;



vector<int> getPath(vector<vector<int>>& edges, vector<bool>& visited, int v1, int v2) {
    visited[v1] = true;
    if (v1 == v2) {
        return {v1};
    }

    int n = edges.size();
    for (int i = 0; i < n; i++) {
        if (edges[v1][i] == 1 && !visited[i]) {
            vector<int> path = getPath(edges, visited, i, v2);
            if (!path.empty()) {
                path.push_back(v1);
                return path;
            }
        }
    }
    return {};
}

int main() {
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int v1, v2;
    cin >> v1;
    cin >> v2;
    vector<bool> visited(n, false);
    vector<int> ans = getPath(edges, visited, v1, v2);
    reverse(ans.begin(),ans.end());
    if (!ans.empty()) {
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
    } 
    cout << endl;
    return 0;
}
