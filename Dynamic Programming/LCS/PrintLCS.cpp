#include <bits/stdc++.h>
using namespace std;

string printLCS(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    // Create a 2D table for dynamic programming
    int table[m + 1][n + 1];

    // Fill the table using dynamic programming
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    // Retrieve the LCS using the filled table
    int i = m, j = n;
    string s = "";
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            s.push_back(text1[i - 1]);
            i--;
            j--;
        } else {
            if (table[i][j - 1] > table[i - 1][j])
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(), s.end());

    return s;
}

int main() {
    string text1;
    string text2;
    cin>>text1>>text2;

    cout << "Longest Common Subsequence: " << printLCS(text1, text2) << endl;

    return 0;
}
