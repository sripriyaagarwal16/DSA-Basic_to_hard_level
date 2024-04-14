#include<iostream>
#include <algorithm>
using namespace std; 
void sort012(int *arr, int n)
{
    //Write your code here
    /*sort(arr,arr+n);*/
      int low = 0;            // Pointer for 0s
    int high = n - 1;       // Pointer for 2s
    int current = 0;        // Current pointer

    while (current <= high) {
        if (arr[current] == 0) {
            swap(arr[current], arr[low]);
            low++;
            current++;
        } else if (arr[current] == 2) {
            swap(arr[current], arr[high]);
            high--;
        } else {
            current++;
        }
    }
}
