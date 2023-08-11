#include<bits/stdc++.h>
using namespace std;

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
    for (int k = i; k < j; k++)
    {
        int tempAns = solve(s, i, k) + solve(s, k + 1, j) + 1;

        if (tempAns < mn) {
            mn = tempAns;
        }
    }
    return mn;
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

    cout << minPalindromePartitions(s);

    return 0;
}
