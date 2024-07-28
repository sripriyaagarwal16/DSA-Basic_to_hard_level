#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> freqMap;


    for (int i = 0; i < n; ++i) {
        freqMap[arr1[i]]++;
    }

  
    for (int i = 0; i < m; ++i) {
        if (freqMap.find(arr2[i]) != freqMap.end() && freqMap[arr2[i]] > 0) {
            cout << arr2[i] << endl;
            freqMap[arr2[i]]--;
        }
    }
}