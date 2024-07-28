#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

char nonrepeatingchar(string str) {
    unordered_map<char, int> freq;

    for (int i = 0; i < str.size(); i++) {
        freq[str[i]]++;
    }

    for (int i = 0; i < str.size(); i++) {
        if (freq[str[i]] == 1) {
            return str[i];
        }
    }

   
    return str[0];
}


int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    char character=nonrepeatingchar(str);
    cout<<"the non-repaeating character is :"<<character<<endl;

}