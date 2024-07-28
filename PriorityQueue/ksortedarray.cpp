#include<iostream>
#include<queue>
using namespace std;
void ksortedarray(int input[],int n ,int k){
    priority_queue<int>pq;
    for(int i =0;i<k;i++){
        pq.push(input[i]);
    }
    int j =0;
    for(int i=k;i<n;i++){
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}
