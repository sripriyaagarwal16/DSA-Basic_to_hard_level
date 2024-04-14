#include<iostream>
#include<stack>
using namespace std;
void reversestack(stack<int> &input,stack<int> &output){
    int capacity=input.size();
    for(int i =0;i<capacity;i++){
        int top = input.top();
        input.pop();
        output.push(top);

    }


}
int main(){
    stack<int>input;
    int size;
    cout<<"enter the size of the stack"<<endl;
    cin>>size;
    for(int i =0;i<size;i++){
        int n ;
        cout<<"enter the number"<<endl;
        cin>>n; 
        input.push(n);
    }
    stack<int>output;
    reversestack(input,output);
    cout<<"the reversed stack is "<<endl;
    for(int i =0;i<output.size();i++){
        int top = output.top();
        cout<<top<<endl;
        output.pop();
    }


}