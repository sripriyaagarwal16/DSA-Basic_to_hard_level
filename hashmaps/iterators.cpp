#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    //this is use of iterators in unordered_maps
    unordered_map<int,bool>ourmap;
    unordered_map<int,bool> ::iterator it=ourmap.begin();
    while(it!=ourmap.end()){
        cout<<"Key:"<<it->first<<"Value :"<<it->second<<endl;
        it++;
    }
    //use of iterators in vectors
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::iterator it1=v.begin();
    while(it1!=v.end()){
        cout<<*it1<<endl;
        it1++;
    }

}