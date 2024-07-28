
#include<iostream>
#include<queue>
uaing namespace std;

std::vector<int> kSmallest(int arr[], int n, int k) {
    
    
    // Use a max heap to keep track of the k smallest elements
    std::priority_queue<int> pq;

    // Insert the first k elements into the max heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Iterate over the remaining elements
    for (int i = k; i < n; i++) {
        // If the current element is smaller than the largest element in the heap
        if (pq.top() > arr[i]) {
            // Replace the largest element with the current element
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Create a vector to store the k smallest elements
    std::vector<int> result;

    // Pop elements from the max heap and insert them into the result vector
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    // Reverse the vector to get the elements in ascending order
    std::reverse(result.begin(), result.end());

    return result;
}