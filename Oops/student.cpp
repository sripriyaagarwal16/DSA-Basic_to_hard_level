#include<iostream> 
using namespace std; 
class student{
    int age; 
    int rollnumber;
    public:
    //Setters
    void setage(int age ,int password){
        if(password!=123){
            return ;
        }
        this->age=age;
    }
    void setrollnumber(int rollnumber){
        this->rollnumber=rollnumber;
    }

    //Getters
    int getage(){
        return age;
    }
    int getrollnumber(){
     return rollnumber;
    }


};