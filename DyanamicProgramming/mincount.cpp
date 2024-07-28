#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
//brute force recursion process
int mincounts(int n ){
    if(n==0){
        return 0 ;
    }
    if(n==1||n==2||n==3){
        return n ;
    }
    int x=mincounts(n -1)+1;
    int y=(n>=4)?mincounts(n-4)+1:INT_MAX;
    int z=(n>=9)?mincounts(n-9)+1:INT_MAX;
    int result=min(x,min(y,z));
    return result;
    
}
//dp
#include <vector>
#include <algorithm>
#include <climits>  // For INT_MAX

int mincounts_2(int n) {
    std::vector<int> ans(n + 1, INT_MAX); // Initialize with a large value
    ans[0] = 0; // Base case: 0 can be represented with 0 perfect squares

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            ans[i] = std::min(ans[i], ans[i - j * j] + 1);
        }
    }

    return ans[n];
}

int main(){
    int n ;
    cin>>n;
    int result=mincounts_2( n );
    cout<<result;
}