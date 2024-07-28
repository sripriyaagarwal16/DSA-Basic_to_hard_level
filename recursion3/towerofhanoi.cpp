#include<iostream>
#include<string>
using namespace std;

void towerofhanoi(int n,char source,char auxiliary,char destination){
    if(n==0){
        return ;
    }
    towerofhanoi(n-1,source,destination,auxiliary);
    cout<<source<<" "<<destination<<endl;
    towerofhanoi(n-1,auxiliary,source,destination);

}