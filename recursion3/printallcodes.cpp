#include<iostream>
#include<string>
using namespace std;

void printcodehelper(string input,string output){
    if(input[0]=='/0'){
        cout<<output<<endl;
        return ;
    }
    int num=input[0]-48;
    char ch = num+'a'-1;
    printcodehelper(input.substr(1),output+ch);
    if(input[1]!='/0'){
        num=num*10+input[1]-48;
        if(num>=10&&num<=26){
            ch=num+'a'-1;
           printcodehelper (input.substr(2), output+ch);
        }
    }
}
void printcodes(string input){
    string output="";
     printcodehelper(input,output);
}