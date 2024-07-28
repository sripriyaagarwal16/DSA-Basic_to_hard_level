#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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

int lettercombinationhelper(string digits, vector<string>& output) {
    if (digits == "0") {
        output.push_back("");
        return 1;
    }

    int string_digits = stoi(digits);
    int last_number = string_digits % 10;
    string smallstring = combinations(last_number);
    int smallnumber = string_digits / 10;
    string string_smallnumber = to_string(smallnumber);

    int smalloutputsize = lettercombinationhelper(string_smallnumber, output);
    int current_size = smalloutputsize * smallstring.size();
    vector<string> temp_output(current_size);

    for (int i = 0; i < smallstring.size(); i++) {
        for (int j = 0; j < smalloutputsize; j++) {
            temp_output[j + i * smalloutputsize] = output[j];
        }
    }

    int k = 0;
    for (int i = 0; i < smallstring.size(); i++) {
        for (int j = 0; j < smalloutputsize; j++) {
            temp_output[k] = temp_output[k] + smallstring[i];
            k++;
        }
    }
    output = temp_output;
    return current_size;
}

vector<string> letterCombinations(string digits) {
    vector<string> output;
    if (digits.empty()) return output;
    int output_size = lettercombinationhelper(digits, output);
    sort(output.begin(),output.end());
    return output;
}
