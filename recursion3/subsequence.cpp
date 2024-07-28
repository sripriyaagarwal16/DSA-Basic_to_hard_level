#include<iostream>
#include<string>
using namespace std ; 
int subsequences(string input,string output[]){
    //base case for empty string
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    string smallstring=input.substr(1);
    int smalloutput=subsequences(smallstring,output);
    for(int i =0;i<smalloutput;i++){
        output[i+smalloutput]=input[0]+output[i];

    }
return 2*smalloutput;

}
//printing the subsequences 
void printsubstr(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
     printsubstr(input.substr(1),output);
      printsubstr(input.substr(1),output+input[0]);
}
int main(){
    string input;
    cin>>input;
    string output;
    printsubstr(input,output);
    


}