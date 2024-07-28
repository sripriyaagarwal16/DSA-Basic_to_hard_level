#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Recursive function to find the closest cost to the target
int close(int n, int m, const vector<int>& basecosts, const vector<int>& flavourcosts, int target, int currentCost, int& closest) {
    // Base cases
    if (abs(target - currentCost) < abs(target - closest) || (abs(target - currentCost) == abs(target - closest) && currentCost < closest)) {
        closest = currentCost;
    }

    if (n == 0 && m == 0) {
        return abs(target - currentCost);
    }

    // Recurse without any more toppings
    for (int i = 0; i < basecosts.size(); ++i) {
        close(n - 1, m, basecosts, flavourcosts, target, currentCost + basecosts[i], closest);
    }

    // Recurse with one or two toppings
    for (int j = 0; j < flavourcosts.size(); ++j) {
        // Using one topping
        close(n, m - 1, basecosts, flavourcosts, target, currentCost + flavourcosts[j], closest);
        // Using two toppings
        close(n, m - 2, basecosts, flavourcosts, target, currentCost + 2 * flavourcosts[j], closest);
    }

    return abs(target - closest);
}

// Function to find the closest cost to the target
int closestcost(int n, int m, vector<int>& basecosts, vector<int>& flavourcosts, int target) {
    sort(basecosts.begin(), basecosts.end());
    sort(flavourcosts.begin(), flavourcosts.end());
    int closest = INT_MAX;
    for (int base : basecosts) {
        close(n - 1, m, basecosts, flavourcosts, target, base, closest);
    }
    return closest;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N;
        vector<int> basecosts(N);
        for (int i = 0; i < N; ++i) {
            cin >> basecosts[i];
        }
        cin >> M;
        vector<int> flavourcosts(M);
        for (int i = 0; i < M; ++i) {
            cin >> flavourcosts[i];
        }
        cin >> K;
        cout << closestcost(N, M, basecosts, flavourcosts, K) << endl;
    }
    return 0;
}
