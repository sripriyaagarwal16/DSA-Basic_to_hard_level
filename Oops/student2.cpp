#include<iostream> 
using namespace std; 
#include <string.h>
class student{
    int age;
    char*name;
    student(int age,char*name){
         this->age=age;
        //shallow copy (we should avoid this )
        this->name=name;
        
        //DeepCopy(prefer this for name)
        this->name=new char(strlen(name)+1);//1 for null character
        strcpy(this->name,name);
       
        student(student &s) {
        this->age = s.age;
        this->name = s.name;
    }
    }
};