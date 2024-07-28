#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void getuniquesubsethelper(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);

    for (int i = index; i < arr.size(); i++) {
       
        if (i > index && arr[i] == arr[i - 1]) {
            continue;
        }
        
        current.push_back(arr[i]);
       
        getuniquesubsethelper(arr, i + 1, current, result);
     
        current.pop_back();
    }
}

vector<vector<int>> getuniquesubset(vector<int>&arr){
    vector<int>current;
    vector<vector<int>>result;
    sort(arr.begin(),arr.end());
    getuniquesubsethelper(arr,0,current,result);
    return result;
}

vector<vector<int>>subsetsumtoK(vector<int>&arr,int k ){
    vector<vector<int>>result= getuniquesubset(arr);
    vector<vector<int>>finalresult;
    int sum;
    for(vector<int>v:result){
        sum=0;
        for(int num:v){
            sum+=num;
        }
        if(sum==k){
            finalresult.push_back(v);
        }
    }
    return finalresult;


}
int main() {
    // Example usage
    vector<int> arr = {1, 2, 2, 3, 4};
    int k = 4;

    // Get subsets with sum equal to k
    vector<vector<int>> subsetsWithSumK = subsetsumtoK(arr, k);

    // Print the subsets with sum equal to k
    cout << "Subsets with sum " << k << ":" << endl;
    for (const auto& subset : subsetsWithSumK) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}