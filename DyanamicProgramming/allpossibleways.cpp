#include <iostream>
#include <cmath>
#include<vector>

using namespace std;
//memoization
int power(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

int getWaysHelper_1(int a, int b, int n,vector<int>ans) {
    if (a == 0) {
        return 1;
    }
    if(ans[a]!=-1){
        return ans[a];
    }
    int ways = 0;
    for (int i = n + 1; power(i, b) <= a; i++) {
        ways += getWaysHelper_1(a - power(i, b), b, i,ans);
    }
    ans[a]=ways;
    return ans[a];
}

int getWays_1(int a, int b) {
    vector<int>ans(a+1,-1);
    return getWaysHelper_1(a, b, 0,ans);
}
//brute force method
int getWaysHelper(int a, int b, int n) {
    if (a == 0) {
        return 1;
    }
    int ways = 0;
    for (int i = n + 1; power(i, b) <= a; i++) {
        ways += getWaysHelper(a - power(i, b), b, i);
    }
    return ways;
}

int getWays(int a, int b) {
    return getWaysHelper(a, b, 0);
}
//DP 
int getWays_2(int a, int b) {
    std::vector<int> dp(a + 1, 0);
    dp[0] = 1; // Base case: 1 way to make sum 0

    for (int i = 1; ; ++i) {
        int power_i_b = power(i, b);
        if (power_i_b > a) break; // Stop if i^b exceeds a

        for (int j = power_i_b; j <= a; ++j) {
            dp[j] += dp[j - power_i_b];
        }
    }

    return dp[a];
}

int main() {
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    int ways = getWays_2(a, b);
    cout << "The number of ways to get " << a << " with the sum of the numbers with powers " << b << " is: " << ways << endl;
    return 0;
}
