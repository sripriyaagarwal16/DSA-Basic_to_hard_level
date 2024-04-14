#include <iostream>
#include <vector>
using namespace std;

vector<int> houses(vector<int> pos, vector<int> amount, vector<int> prices) {
    vector<int> results; 

    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] > prices.size()) {
            results.push_back(-1); // Invalid position
            continue;
        }

        int sum = 0;
        int n = 0;

        for (int j = pos[i] ; j <= prices.size(); j++) { // Adjust index for 0-based indexing
            sum += prices[j];
            if (sum <= amount[i]) {
                n++;
            } else {
                break; // Stop buying when budget is exceeded
            }
        }

        results.push_back(n);
    }

    return results;
}
int main() {
    int n;
    cout << "Enter the number of prices: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    vector<int> pos(q);
    cout << "Enter the positions for each query: ";
    for (int i = 0; i < q; i++) {
        cin >> pos[i];
    }

    vector<int> amount(q);
    cout << "Enter the amounts for each query: ";
    for (int i = 0; i < q; i++) {
        cin >> amount[i];
    }

    // Call the function and print results
    vector<int> result = houses(pos, amount, prices);
    cout << "Maximum products purchased: " <<endl;
    for(int i =0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
}