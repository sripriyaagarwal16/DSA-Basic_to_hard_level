#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t hash = 0;
        for (int i : v) {
            hash ^= std::hash<int>{}(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    unordered_map<vector<int>, bool,VectorHash> seen;
    int n = nums.size();
    
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end()); 
                    result.push_back(triplet);
                }
            }
        }
    }
    
    vector<vector<int>> finalresult;
    for(int i = 0; i < result.size(); i++) {
        if(!seen[result[i]]) {
            seen[result[i]] = true;
            finalresult.push_back(result[i]);
        }
    }
    
    return finalresult;
}
int main() {
    vector<int> nums;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    vector<vector<int>> result = threeSum(nums);
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}