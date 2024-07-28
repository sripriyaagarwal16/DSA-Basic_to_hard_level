#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int longestsub_helper(vector<int>&arr,int start,int currentlength,int prevelement){
    int n =arr.size();
    if(start>=n){
        return currentlength;
    }
    //if we include the element
    int x=INT_MIN;
    if(start+1<n&&arr[start]>prevelement){
        x=longestsub_helper(arr,start+1,currentlength+1, arr[start]);
    }
    //if we will exclude the element
    int y =longestsub_helper(arr,start+1,currentlength,prevelement);
    
    int result=max(x,y);
    return result;


}
int longestsub(vector<int>&arr){
    int result=longestsub_helper(arr,0,0,INT_MIN);
    return result;
}
//memoization
int longestsub_helper_1(vector<int>&arr,int start,int currentlength,int prevelement,vector<int>&ans){
    int n =arr.size();
    if(start>=n){
        return currentlength;
    }
    //if we include the element
    if(ans[n]!=-1){
        return ans[n];
    }
    int x=INT_MIN;
    if(start+1<n&&arr[start]>prevelement){
        x=longestsub_helper(arr,start+1,currentlength+1, arr[start]);
    }
    //if we will exclude the element
    int y =longestsub_helper(arr,start+1,currentlength,prevelement);
    
    int result=max(x,y);
    ans[n]=result;
    return ans[n];


}
int longestsub_1(vector<int>&arr){
    int n =arr.size();
    vector<int>ans(n+1,-1);
    int result=longestsub_helper_1(arr,0,0,INT_MIN,ans);
    return result;
}

//DP 
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int longestsub_2(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n + 1, 0);
    ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x = INT_MIN;
        int y = INT_MIN;
        if (arr[i - 1] > arr[i - 2]) {
            x = ans[i - 1] + 1;
        } else {
            y = ans[i - 1];
        }
        ans[i] = max(x, y);
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = longestsub_2(arr);
    cout << "The length of the longest increasing subsequence is: " << result << endl;
    return 0;
}
