#include<iostream>
#include<stack>
#include<string>
using namespace std ;
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isparenthesis(string s) {
    stack<char> s1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            s1.push(s[i]);
        } else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (s1.empty()) {
                return false; // There's a closing parenthesis without corresponding opening parenthesis
            } else if ((s[i] == '}' && s1.top() == '{') || (s[i] == ']' && s1.top() == '[') || (s[i] == ')' && s1.top() == '(')) {
                s1.pop();
            } else {
                return false; // Mismatched parenthesis
            }
        }
    }

    return s1.empty(); // Return true if stack is empty (all parenthesis are matched)
}

int main() {
    string str = "{[()]}";
    if (isparenthesis(str)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }
    return 0;
}
