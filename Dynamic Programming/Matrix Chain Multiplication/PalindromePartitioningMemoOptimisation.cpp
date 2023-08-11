#include<bits/stdc++.h>
using namespace std;
static int table[501][501];
bool isPalindrome(string& s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string& s, int i, int j)
{
    if (i >= j) return 0;
    if (isPalindrome(s, i, j)) return 0;

    int mn = INT_MAX;
    
    if(table[i][j]!=-1)
        return table[i][j];
    for (int k = i; k < j; k++)
    {
        int left, right;
        //left
        if (table[i][k] != -1)
            left = table[i][k];
        else
        {
            left = solve(s, i, k);
            table[i][k] = left;
        }

        // Check if the right substring is already computed
        if (table[k + 1][j] != -1)
            right = table[k + 1][j];
        else
        {
            right = solve(s, k + 1, j);
            table[k + 1][j] = right;
        } 
        int tempAns = right + left + 1;
        mn = min(mn, tempAns);
    }
    return table[i][j]=mn;
}

int minPalindromePartitions(string& s)
{
    int i = 0;
    int j = s.length() - 1;
    return solve(s, i, j);
}

int main()
{
    string s;
    cin >> s;
    memset(table,-1,sizeof(table));
    cout << minPalindromePartitions(s);

    return 0;
}
