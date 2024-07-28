#include<iostream>
#include<string>
using namespace std;
void printsubsequences(string input,string output[]){
    if(input.length()==0){
        cout<<output<<endl;
    }
    printsubsequences(input.substr(1),output);
    printsubsequences(input.substr(1),output+input[0]);



}