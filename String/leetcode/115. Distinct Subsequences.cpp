class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<double> prev(m+1,0);
        
        prev[0] = 1;
        
        for(int i = 1;i <= n;i++)
        {
            for(int j = m;j >= 1;j--)
            {
                if(s[i-1] == t[j-1])
                {
                    prev[j] = prev[j-1] + prev[j];
                }
                else
                {
                    prev[j] = prev[j];
                }
            }
        }
        return (int)prev[m];
    }
};
/*
    class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<unsigned int>> table(m + 1, vector<unsigned int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) {
            table[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
                } else {
                    table[i][j] = table[i - 1][j];
                }
            }
        }

        return table[m][n];
    }
};
*/
