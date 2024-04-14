#include<iostream>
using namespace std;
class queuesusingarray{
    int *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;
    public:
    queuesusingarray(int s ){
        data=new int[s];
        nextindex=0;
        firstindex=-1;
        size=0;
        capacity=s;
    }
    //size function 
    int getsize(){
        return size;
    }
    //empty function
    bool isempty(){
        return size==0;
    }
    //insert function 
    void enqueue(int element){
         if(size==capacity){
            cout<<"the queue is full";
            return ;
            }
        if(firstindex==-1&&nextindex==0){
            data[nextindex]=element;
            nextindex=(nextindex+1)%capacity;
            firstindex=0;
            size++;
        }
        data[nextindex]=element;
        nextindex=(nextindex+1)%capacity;
        size++;


    }
    //getting front 
    int front(){
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstindex];
    }
    
    int dequeue(){
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        int ans=data[firstindex];
        firstindex=(firstindex+1)%capacity;
        size--;
        if(size==0){
            firstindex=-1;
            nextindex=0;
        }
        return ans;
    }

};