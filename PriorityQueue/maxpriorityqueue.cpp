#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class max_priority_queue{
    vector<int>pq;
    public:
    bool isempty(){
        if(vector.size()==0){
            return true;
        }
        return false;
    }
    int getmax(){
        if(isempty()){
            return 0;
        }
        return pq[0];
    }
    int getsize(){
        return pq.size();
    }
    void insert(int data){
        if(isempty()){
            pq.push_back(data);
            return ;
        }
        pq.push_back(data);
        int childindex=pq.size()-1;
        while(childindex>0){
        int parentindex=(childindex-1)/2;
        if(pq[parentindex]<pq[childindex]){
            int temp=pq[parentindex];
            pq[childindex]=pq[parentindex];
            pq[parentindex]=temp;
           }
        else{
            break;
           }
           childindex=parentindex;
        }
    }
    int remove(){
        if(isempty()){
            cout<<"the queue is empty"<<endl;
            return 0;
        }
        int ans=pq[0];
        int n=pq.size()-1;
        pq[0]=pq[n];
        pq.pop_back(pq[n]);
        int parentindex=0;
        while(2*parentindex+1<pq.size()){
            int leftchildindex=2*parentindex+1;
            int rightchildindex=2*parentindex+2;
            int maxchild=0;
            int maxchildindex=0;
           if(pq[leftchildindex]<pq[rightchildindex]){
               maxchild=pq[rightchildindex];
               maxchildindex=rightchildindex;
           }
           else{
               maxchild=pq[leftchildindex];
               maxchildindex=leftchildindex;
           }
            if(pq[parentindex]<maxchild){
                int temp=pq[parentindex];
                pq[parentindex]=maxchild;
                pq[maxchildindex]=temp;
            }
            else{
                break;
            }
            parentindex=maxchildindex;
            
        }
        return ans;
    }

};