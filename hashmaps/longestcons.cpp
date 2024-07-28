#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> longestconsecutivesequence(vector<int>nums){
    unordered_map<int,bool>maps;
    for(int num:nums){
        maps[num]=true;
    }
    int startnum=0;
    int longestlength=0;
    for(int num:nums){
        if(!maps.count(num-1)){
            int currentnum=num;
            int currentlength=1;
            while(maps.count(num+1)){
                currentnum++;
                currentlength++;
            }
            if(currentlength>longestlength||currentlength==longestlength&&currentnum==num){
                      longestlength=currentlength;
                      startnum=num;
            }
        }
    }
    vector<int>output;
    output.push_back(longestlength);
    output.push_back(startnum);
    return output;

}
int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> output = longestconsecutivesequence(nums);
    cout << "Output: " << output[0] << " " << output[1] << endl;
    return 0;
}