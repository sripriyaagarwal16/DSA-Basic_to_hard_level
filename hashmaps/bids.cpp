#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

int minbidsum(vector<int> projectid, int numprojects, vector<int> bids) {
    unordered_map<int, bool> duplicate;
    vector<int> output;

    // Count distinct project IDs
    for (int i = 0; i < projectid.size(); i++) {
        if (duplicate.count(projectid[i]) == 0) {
            duplicate[projectid[i]] = true;
            output.push_back(projectid[i]);
        }
    }
    
    int distinct = output.size();
    if (distinct != numprojects) {
        return -1;
    }

    // Initialize minbids with maximum integer value
    unordered_map<int, int> minbids;
    for (int i = 0; i < numprojects; i++) {
        minbids[output[i]] = INT_MAX;
    }

    // Update minbids with actual minimum bids
    for (int i = 0; i < projectid.size(); i++) {
        int id = projectid[i];
        int bid = bids[i];
        if (bid < minbids[id]) {
            minbids[id] = bid;
        }
    }

    // Calculate sum of minimum bids
    int minsum = 0;
    for (int i = 0; i < output.size(); i++) {
        int id = output[i];
        minsum += minbids[id];
    }
    return minsum;
}

int main() {
    // Example input
    int n; 
    cout << "Enter the number of project IDs: ";
    cin >> n;
    vector<int> projectid(n);
    cout << "Enter the project IDs: ";
    for(int i = 0; i < n; i++){
        cin >> projectid[i];
    }

    int m;
    cout << "Enter the number of bids: ";
    cin >> m;
    vector<int> bids(m);
    cout << "Enter the bids: ";
    for(int i = 0; i < m; i++){
        cin >> bids[i];
    }
    int numprojects;
    cout << "Enter the number of distinct projects: ";
    cin >> numprojects;

    // Calculate and print the minimum bid sum
    cout << "Minimum bid sum: " << minbidsum(projectid, numprojects, bids) << endl;

    return 0;
}
