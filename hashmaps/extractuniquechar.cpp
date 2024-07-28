#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
string uniqueChar(string str) {
    // Write your code here
    string output;
    unordered_map<char, bool> seen;

    for (int i = 0; i < str.length(); i++) {
        if (seen.count(str[i]) > 0) {
            continue;
        }

        seen[str[i]] = true;
        output.push_back(str[i]);
    }

    return output;
}
int main(){
    string str;
    cout<<"Enter the string";
    cin>>str;
    string output= uniqueChar(str);
    cout<<"The output string is : "<<output;



}