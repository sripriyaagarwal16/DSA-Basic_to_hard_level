#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

 
    priority_queue<int,vector<int>,greater<int>> pq;

   
    for (int i = 0; i < k; i++) {
        pq.push(input[i]);
    }

 
    for (int i = k; i < n; i++) {
  
        if (pq.top() < input[i]) {
         
            pq.pop();
            pq.push(input[i]);
        }
    }

    // Create a vector to store the k smallest elements
    vector<int> result;

    // Pop elements from the max heap and insert them into the result vector
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    // Reverse the vector to get the elements in ascending order
    reverse(result.begin(), result.end());

    return result;
}


