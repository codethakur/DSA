class Solution {
public:
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

    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        // Clear the table before each function call
        memset(table, 0, sizeof(table));

        // Check if there's a repeated substring that covers the entire string
        return lcsSubstring(s, s, n, n) != n;
    }
};
