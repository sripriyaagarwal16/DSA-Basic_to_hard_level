#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int balancedtrees(int n ){
    if(n<=1){
        return 1;
    }
    int x=balancedtrees(n-1);
    int y=balancedtrees(n-2);
    int temp=x*x+2*x*y;
    return temp;


}
int balancedtrees_2(int n ){
    if(n<=1){
        return 1;
    }
    vector<int>ans(n+1,0);
    ans[0]=1;
    ans[1]=1;
    for(int i =2;i<=n;i++){
        int mod=(int)(pow(10,9))+7;
        int temp1=(int)((2*(long)(ans[i-1])*ans[i-2]))%mod;
        int temp2=(int)(((long)(ans[i-1])*ans[i-1]))%mod;
        ans[i]=(temp1+temp2)%mod;

    }
    return ans[n];
}
int main(){
    int n ;
    cin>>n;
    int result=balancedtrees_2(n);
    cout<<"the numbr of balanced binary trees are:"<<" "<<result<<endl;

}