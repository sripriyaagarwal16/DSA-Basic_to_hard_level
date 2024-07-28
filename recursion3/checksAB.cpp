#include<iostream>
#include<string>
using namespace std;
bool checkABhelper(char input[],int index){
    if(input[0]!='a'){
        return false;
    }
    if(input[index]=='\0'){
        return true;
    }
    //rule2:
    if(input[index]=='a'){
        if(input[index+1]=='a'||(input[index+1]=='b'&&input[index+2]=='b')||input[index+1]=='\0'){
            return checkABhelper( input, index+1);
        }
        else{
            return false;
        }
    }
    //rule3:
    if(input[index]=='b'&&input[index+1]=='b'){
        if(input[index+2]=='a'||input[index+2]=='\0'){
            return checkABhelper( input, index+2);
        }
        else{
            return false;
        }
    }
    return false;
}

bool checkAB(char input[]){
    bool check=checkABhelper(input, 0);
    return check;
}
int main(){
    char input[1000]={'a','b','b'};
    bool check=checkAB(input);
    cout<<check<<endl;


}