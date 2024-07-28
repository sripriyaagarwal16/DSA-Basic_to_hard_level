#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (const auto& innervector : input) {
        for (int element : *innervector) {
            pq.push(element);
        }
    }

    vector<int> result;

    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

