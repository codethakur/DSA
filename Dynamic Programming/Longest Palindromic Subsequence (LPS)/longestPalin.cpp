class Solution {
  public:
   int lcs(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int table[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0) {
                    table[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    table[i][j] = 1 + table[i - 1][j - 1];
                } else {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }
        return table[m][n];
    }
    string longestPalin (string S) {
        // code here
    string s2 = S;
        std::reverse(s2.begin(), s2.end());

        int len = lcs(S, s2);

        // Reconstruct the longest palindromic subsequence
        string result;
        int i = S.length(); 
        int j = S.length();
        while (i > 0 && j > 0) {
            if (S[i - 1] == s2[j - 1]) {
                result = S[i - 1] + result;
                i--;
                j--;
            } else if (len > 0 && lcs(S.substr(0, i), s2.substr(0, j - 1)) == len) {
                j--;
            } else {
                i--;
            }
        }

        return result;    
    }
};
