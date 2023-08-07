class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int table[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    table[i][j] = 0;
                else if (str1[i - 1] == str2[j - 1])
                    table[i][j] = 1 + table[i - 1][j - 1];
                else
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }

        int i = m, j = n;
        string s = "";
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                s.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (table[i][j - 1] >= table[i - 1][j]) {
                    s.push_back(str2[j - 1]);
                    j--;
                } else {
                    s.push_back(str1[i - 1]);
                    i--;
                }
            }
        }
        while (i > 0) {
            s.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            s.push_back(str2[j - 1]);
            j--;
        }
        reverse(s.begin(), s.end());

        return s;
    }
};
--------------------------------------------Solution2--------------------------------------------------------

  class Solution {
public:
string findLCS(string str1,string str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        string dp[len1+1][len2+1];
        
        for(int i=0;i<=len1;++i)
            for(int j=0;j<=len2;++j)
            {
            if(i==0 || j==0)
               dp[i][j] = "";
            else if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1]+str1[i-1];
            else
            dp[i][j] = dp[i][j-1].size() > dp[i-1][j].size() ? dp[i][j-1]:dp[i-1][j];
            }
        return dp[len1][len2];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        string lcs = findLCS(str1,str2);
        
        int p1=0,p2=0;
        for(char c: lcs)
        {
            while(str1[p1]!=c)  
                ans += str1[p1++];
            while(str2[p2]!=c)  
                ans += str2[p2++];
            
            ans += c;   
            ++p1;
            ++p2;
        }
        ans += str1.substr(p1) + str2.substr(p2);
        return ans;
    }
};
