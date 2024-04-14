#include<iostream>  
#include"student.cpp"
using namespace std; 
int main(){
    student s1; //Statically
    student *s2 =new student ;
    s1.setage(24,124);
    s2->setage(25,123);
    int age1=s1.getage();
    int  age2=s2->getage();
    cout<<"the age of s1 is"<<age1<<"the age of s2 is "<<age2<<endl;  
}