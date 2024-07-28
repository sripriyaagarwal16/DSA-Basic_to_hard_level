#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
bool checkperm(string str1,string str2){
  if(str1.size() != str2.size()) {
    return false;
}
 unordered_map<int,int>freq;
 for(int i =0;i<str1.size();i++){
    freq[str1[i]]++;
 }
 for(int i =0;i<str2.size();i++){
    if(--freq[str2[i]]<0){
        return false;
    }
 }
 return true;

}
int main(){
    string str1;
    cout<<"enter the string 1 :";
    cin>>str1;
     string str2;
    cout<<"enter the string 2 :";
    cin>>str2;
    bool permutation= checkperm(str1,str2);
    cout<<permutation<<endl;
}