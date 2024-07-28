#include<iostream>
#include<vector>
#include<string>
using namespace std;

int returnallcodes(string input,string output[]){
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    int size1=0;
    int size2=0;
    int first=input[0]-48;
    char secondchar='/0';
    char firstchar=first+'a'-1;
    string smalloutput1[500];
    string smalloutput2[500];
    size1=returnallcodes(input.substr(1),smalloutput1);
    if(input[1]!='/0'){
        int second=first*10+input[1]-48;
        if(second>=10&&second<=26){
            secondchar=second+'a'-1;
            size2=returnallcodes(input.substr(2),smalloutput2);
        }

    }
    int k=0;
    for(int i =0;i<size1;i++){
        output[k]=firstchar+smalloutput1[i];
        k++;
    }
    for(int i =0;i<size2;i++){
        output[k]=secondchar+smalloutput2[i];
        k++;
    }
    return k;

}