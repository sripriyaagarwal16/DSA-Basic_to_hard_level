#include <iostream>
#include <vector>
using namespace std;

void visiteachnode(vector<vector<int>>& edges, int sv, vector<bool>& visited) {
    visited[sv] = true;
    int n = edges.size();
    for (int i = 0; i < n; i++) {
        if (edges[sv][i] == 1 && !visited[i]) {
            visiteachnode(edges, i, visited);
        }
    }
}

bool isconnected(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<bool> visited(n, false);
    visiteachnode(edges, 0, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false; // If any node is not visited, the graph is not connected
        }
    }
    return true; // All nodes were visited
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

    if (isconnected(edges)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
