#include<bits/stdc++.h>
using namespace std;

int table[1001][1001];

int lcsSubstring(string text1, string text2, int n, int m)
{
    int maxLength = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                table[i][j] = 1 + table[i - 1][j - 1];
                maxLength = max(maxLength, table[i][j]);
            }
            else
            {
                table[i][j] = 0; // No common substring ending at these characters
            }
        }
    }

    return maxLength;
}

int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    int n = text1.length();
    int m = text2.length();

    memset(table, 0, sizeof(table));

    cout << lcsSubstring(text1, text2, n, m);

    return 0;
}
