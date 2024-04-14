#include<iostream>
using namespace std; 
int main(){
    int i=0;
    int x =0;
    do{
        if(i%5==0){
            cout<<x<<endl;
            x++;
        }
        ++i;

    }while(i<10);
    cout<<x;
    return 0;
}