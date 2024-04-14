#include<iostream>
using namespace std ; 
#include<iostream>
#include<climits>
using namespace std; 
//Static stack using array 
template<typename T>
class TempStacks{
    T * data;
    int nextindex;
    int capacity;
    public:
    //Constructor
    TempStacks(int totalSize){
        data=new T [totalSize];
        nextindex=0;
        capacity=totalSize;
    }
    //empty function
    bool isempty(){
        if(nextindex==0){
            return true;
        }else{
            return false;
        }
    }
    //size function 
    int size(){
        return nextindex;
    }
    //Insert Function 
    void push(int element){
        if(nextindex==capacity){
           //static stack
           cout<<"Stack Full"<<endl;
           return ;
        }
        data[nextindex]=element;
        nextindex++;
    }
    //Delete Function
    T pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        T top =data[nextindex-1];
        nextindex--;
        return top;
    }
    //Top function 
    T top (){
        if(isempty()){
           cout<<"the stack is empty"<<endl;
           return INT_MIN;
        }
        return data[nextindex-1];
    }

};
int main(){
    TempStacks<int> s1(4);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    int top= s1.pop();
    cout<<"the top value of stack is: "<<" "<<top<<endl;

}