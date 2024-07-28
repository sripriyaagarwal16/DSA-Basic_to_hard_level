#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int editdistance(string S,string T){
    //base case
    if(S.size()==0){
       return T.size();
    }
    if(T.size()==0){
        return S.size();
    }
    if(S.size()==0&&T.size()==0){
        return 0;
    }
    if(S[0]==T[0]){
        return editdistance(S.substr(1),T.substr(1));
    }
    int i=editdistance(S.substr(1),T)+1;
    int d=editdistance(S,T.substr(1))+1;
    int u=editdistance(S.substr(1),T.substr(1))+1;
    int result=min(i,min(d,u));
    return result;
}

int editdistance_helper(string& S, string& T, int m, int n, vector<vector<int>>& ans) {
    // Base cases
    if (m == 0) return n;
    if (n == 0) return m;

    if (ans[m][n] != -1) return ans[m][n];

    if (S[m-1] == T[n-1]) {
        ans[m][n] = editdistance_helper(S, T, m-1, n-1, ans);
    } else {
        int insert_op = editdistance_helper(S, T, m, n-1, ans) + 1;
        int delete_op = editdistance_helper(S, T, m-1, n, ans) + 1;
        int replace_op = editdistance_helper(S, T, m-1, n-1, ans) + 1;
        ans[m][n] = min({insert_op, delete_op, replace_op});
    }

    return ans[m][n];
}

int editdistance_2(string S, string T) {
    int m = S.size();
    int n = T.size();
    vector<vector<int>> ans(m + 1, vector<int>(n + 1, -1));
    return editdistance_helper(S, T, m, n, ans);
}
int editdistance_3(string S, string T) {
    int m = S.size();
    int n = T.size();
    vector<vector<int>> ans(m + 1, vector<int>(n + 1, 0));

    // Initialize the first column
    for (int i = 0; i <= m; i++) {
        ans[i][0] = i;
    }

    // Initialize the first row
    for (int j = 0; j <= n; j++) {
        ans[0][j] = j;
    }

    // Fill the rest of the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S[i - 1] == T[j - 1]) {
                ans[i][j] = ans[i - 1][j - 1];
            } else {
                int insert_op = ans[i][j - 1] + 1;
                int delete_op = ans[i - 1][j] + 1;
                int replace_op = ans[i - 1][j - 1] + 1;
                ans[i][j] = min({insert_op, delete_op, replace_op});
            }
        }
    }

    return ans[m][n];
}

int main() {
    string S, T;
    cin >> S >> T;
    int result = editdistance_3(S, T);
    cout << "The minimum number of operations to convert \"" << S << "\" to \"" << T << "\" is: " << result << endl;
    return 0;
}