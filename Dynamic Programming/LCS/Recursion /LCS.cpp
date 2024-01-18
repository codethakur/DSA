class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        if(n==0 || m==0)
            return 0;
        if(s1[n-1]==s2[m-1])
            return 1+ lcs(n-1, m-1, s1, s2);
        else
            return max(lcs(n-1, m, s1, s2), lcs(n, m-1, s1, s2));
    }
};
