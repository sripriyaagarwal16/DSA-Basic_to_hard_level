#include<iostream>
using namespace std ;
template <typename T,typename V>
class Pair{
    T x; 
    V y;
    public:
    //constructor
    Pair(T x , V y ){
        this->x=x; 
        this->y=y;
    }
    //getters 
    T getx(){
        return x;
    }
    V gety(){
        return y;
    }
    //setters
    void setx (T data){
        x= data;
    }
    void sety(V data){
        y=data;
    }

};
int main(){
    Pair<int ,bool> p1(10,true);
    cout<<"the value of x is: "<<p1.getx()<<endl;
    cout<<"the value of y is:"<<p1.gety()<<endl;

    p1.setx(20);
    p1.sety(false);
    cout<<"the value of x is: "<<p1.getx()<<endl;
    cout<<"the value of y is:"<<p1.gety()<<endl;






}

