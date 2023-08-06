#include<bits/stdc++.h>
using namespace std;
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        int table[m + 1][n + 1];
        for(int i=0; i<m+1; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0 ||j==0)
                table[i][j]=0;
            }
        }
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(text1[i-1]==text2[j-1]){
                    table[i][j] = 1+table[i-1][j-1];
                }else
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
        return table[m][n];
    }
int main()
{
    string text1;
    string text2;

    cin>>text1>>text2;

    cout<<longestCommonSubsequence(text1,text2);

    return 0;
}
