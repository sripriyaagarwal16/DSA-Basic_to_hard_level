#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int highestfreq(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int i = 0; i < arr.size(); i++) {
        if (freq.count(arr[i]) > 0) {
            freq[arr[i]]++;
        } else {
            freq[arr[i]] = 1;
        }
    }
    int maxfreq = 0;
    int freqelement = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (maxfreq < freq[arr[i]]) {
            maxfreq = freq[arr[i]];
            freqelement = arr[i];
        }
    }

   return freqelement;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++){
        cout << "Enter the " << i << "th number: ";
        cin >> arr[i];
    }
    int mostfreqelement = highestfreq(arr);
    cout << "The most frequent element in the array is: " << mostfreqelement << endl;

    return 0;
}
