#include<iostream>
#include<vector>
#include<string>
using namespace std;
string combinations(int n) {
    if (n == 2) return "abc";
    if (n == 3) return "def";
    if (n == 4) return "ghi";  
    if (n == 5) return "jkl";
    if (n == 6) return "mno";
    if (n == 7) return "pqrs";
    if (n == 8) return "tuv";
    if (n == 9) return "wxyz";
    return " ";
}
void printkeypad(int digits,string output){
    if(digits==0){
        cout<<output<<endl;
        return ;
    }
    int last_number=digits%10;
    int smallnumber=digits/10;
    string smallstring=combinations(last_number);
    for(char c:smallstring){
      printkeypad(smallnumber,output+c);
    }

    

}
int main() {
    int input = 234;
    printkeypad(input, "");
    return 0;
}