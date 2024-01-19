class Solution {
public:
    int lcs(int n, int m, string s1, string s2) {
        int t[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0) 
                    t[i][j] = 0;
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        return t[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int lcsLength = lcs(n, m, word1, word2);

        int minNumber = n + m - 2 * lcsLength;

        return minNumber; 
    }
};
