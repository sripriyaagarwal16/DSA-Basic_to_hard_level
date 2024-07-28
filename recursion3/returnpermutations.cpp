#include<iostream>
#include<vector>
using namespace std;

int returnpermutations(string input,string output[]){
     if(input.size()==0||input.size()==1){
          output[0]="";
          return 1;
     }
     string smalloutput[1000];
     int smalloutputsize=returnpermutations(input.substr(1),smalloutput);
     int k =0;
     for(int i =0;i<smalloutputsize;i++){
        for(int j =0;j<smalloutput[i].length();j++){
            output[k]=smalloutput[i].substr(0,j)+input[0]+smalloutput[i].substr(j);
            k++;
        }
     }
     return k;


}
int main(){
    string input="adg";
    string output[1000];
    int outputsize=returnpermutations(input,output);
    for(int i =0;i<outputsize;i++){
        cout<<output[i]<<endl;
    }
}