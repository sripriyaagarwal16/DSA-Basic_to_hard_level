#include<iostream>
#include<string>
using namespace std;

void printpermutations(string input,string output=""){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    for(int i =0;i<input.length();i++){
        char ch= input[i];
        string rest=input.substr(0,i)+input.substr(i+1);
        printpermutations(input,output+ch);

    }
     



}
int main(){
    string input="abc";
    string output="";
    printpermutations(input,output);

}