#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_helper(vector<int>& weights, vector<int>& values, int maxweight, int start) {
    int n = weights.size();
    if (maxweight == 0 || start == n) {
        return 0;
    }

    int x = knapsack_helper(weights, values, maxweight, start + 1);

    int y = 0;
    if (weights[start] <= maxweight) {
        y = values[start] + knapsack_helper(weights, values, maxweight - weights[start], start + 1);
    }

    int result = max(x, y);
    return result;
}

int knapsack(vector<int>& weights, vector<int>& values, int maxweight) {
    return knapsack_helper(weights, values, maxweight, 0);
}
//memoization
int knapsack_helper_1(vector<int>& weights, vector<int>& values, int maxweight, int start,vector<int>&ans) {
    int n = weights.size();
    if (maxweight == 0 || start == n) {
        return 0;
    }
    if(ans[maxweight]!=-1){
        return ans[maxweight];
    }
    int x = knapsack_helper(weights, values, maxweight, start + 1);

    int y = 0;
    if (weights[start] <= maxweight) {
        y = values[start] + knapsack_helper(weights, values, maxweight - weights[start], start + 1);
    }

    int result = max(x, y);
    ans[maxweight]=result;
    return ans[maxweight];
}

int knapsack_1(vector<int>& weights, vector<int>& values, int maxweight) {
    vector<int>ans(maxweight+1,-1);
    return knapsack_helper_1(weights, values, maxweight, 0,ans);
}
//dp
int knapsack_2(vector<int>& weights, vector<int>& values, int maxweight){
    vector<int>knap(maxweight+1,0);
    int n =weights.size();
    for(int i =0;i<n;i++){
        for(int w=maxweight;w>=weights[i];w--){
           knap[w]=max(knap[w],knap[w-weights[i]]+values[i]);
        }
    }
    return knap[maxweight];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> weights(n);
    vector<int> values(n);
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    int maxweight;
    cin >> maxweight;
    
    int result = knapsack_2(weights, values, maxweight);
    cout << "The max value of knapsack can be: " << result << endl;

    return 0;
}
