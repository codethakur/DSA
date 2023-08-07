//Print shortest common Supersequence
#include <bits/stdc++.h>
using namespace std;

string printSCS(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    int table[m + 1][n + 1];

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

    int i = m, j = n;
    string s = "";
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            s.push_back(text1[i - 1]);
            i--;
            j--;
        } else {
            if (table[i][j - 1] > table[i - 1][j])
                s.push_back(text2[j - 1]);
            else
                s.push_back(text1[i - 1]);
            if (table[i][j - 1] >= table[i - 1][j])
                j--;
            else
                i--;
        }
    }
    while (i > 0) {
        s.push_back(text1[i - 1]);
        i--;
    }
    while (j > 0) {
        s.push_back(text2[j - 1]);
        j--;
    }
    reverse(s.begin(), s.end());

    return s;
}

int main() {
    string text1, text2;
    cin >> text1 >> text2;

    cout << printSCS(text1, text2) << endl;

    return 0;
}
