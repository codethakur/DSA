class Solution{   
public:
    int LCS(int n, int m, string str1, string str2)
    {
        int table[n + 1][m + 1];
    
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    table[i][j] = 0;
            }
        }
    
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (str1[i - 1] == str2[j - 1])
                    table[i][j] = 1 + table[i - 1][j - 1];
                else
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
        return table[n][m];
    }
    int findMinInsertions(string S){    //Same for -> MinDeletion
        // code here 
        string s2 = S;
        int n = S.length();
        int m = s2.length();
        
        std::reverse(s2.begin(),s2.end());
        int LCS_length= LCS(n, m, S, s2);
        
        return n-LCS_length;
    }
};
