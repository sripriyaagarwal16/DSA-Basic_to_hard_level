#include<iostream>
#include<climits>
using namespace std; 

class dynamicstack{
    int *data;
    int nextindex;
    int capacity;
    public:
    //constructor
    dynamicstack(int totalsize){
        data=new int[totalsize];
        nextindex=0;
        capacity=totalsize;
    }
    //size function 
    int size(){
        return nextindex;
    }
    //empty functions 
    bool isempty(){
        if(nextindex==0){
            return true;
        }else{
            return false;
        }
    }
    //size function 
    int Size(){
        return nextindex;
    }
    //Insert Function 
    void push(int element){
        if(nextindex==capacity){
           //dynamic stack
        int *newdata=new int[2*capacity];
        for(int i =0;i<capacity;i++){
            newdata[i]=data[i];
        }
        delete[]data;
        capacity*=2;
        data=newdata;
        }
        data[nextindex]=element;
        nextindex++;
    }
    //Delete Function
    int pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        int top =data[nextindex-1];
        nextindex--;
        return top;
    }
    //Top function 
    int top (){
        if(isempty()){
            cout<<"the stack is full"<<endl;
            return INT_MIN;
        }
        return data[nextindex-1];
    }

};
int main(){
   dynamicstack s1(4);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    int top= s1.pop();
    cout<<"the top value of stack is: "<<top<<endl;

}