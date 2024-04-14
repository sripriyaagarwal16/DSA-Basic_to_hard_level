#include<iostream>  
#include"Fraction.cpp"
using namespace std; 
int main(){
    fraction f1(10,4);
    fraction f2(20,5);

    fraction f4=f1+f2;
    f4.print();
    fraction f5=f1*f2;
    f5.print();
    if(f1==f2){
        cout<<"Equal"<<endl;
        
    }
    else{
        cout<<"Not Equal"<<endl;
    }
}