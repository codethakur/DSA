class Solution {
public:
    int lcs(string s1, string s2)
    {
        int m=s1.length();
        int n=s2.length();
        int table[m+1][n+1];
        for(int i=0; i<m+1;i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0 || j==0){
                    table[i][j]=0;
                }
            }
        }
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s1[i-1]==s2[j-1]){
                    table[i][j]=1+table[i-1][j-1];
                }else
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
        return table[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        std::reverse(s2.begin(), s2.end());
        
        return lcs(s, s2);
    }
};
