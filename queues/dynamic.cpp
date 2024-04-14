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
            int *newdata=new int[2*capacity];
            int j =0;
             for(int i=firstindex;i<capacity;i++){
                newdata[j]=data[i];
             }
             for(int i =0;i<firstindex;i++){
                newdata[j]=data[i];
             }
             firstindex=0;
             delete[]data;
             data=newdata;
             nextindex=capacity;
             capacity*=2;

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