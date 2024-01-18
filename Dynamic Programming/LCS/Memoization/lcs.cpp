class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        static int table[1001][1001];

        // Initialize the memoization table with -1 (indicating not computed).
        memset(table, -1, sizeof(table));

        // Call the recursive helper function with the memoization table.
        return lcsHelper(n, m, s1, s2, table);
    }
    private:
    // Recursive helper function with memoization.
    int lcsHelper(int n, int m, const string& s1, const string& s2, int table[1001][1001])
    {
        // Base case: If either of the strings is empty, LCS is 0.
        if (n == 0 || m == 0)
            return 0;

        // Check if the result is already computed for this subproblem.
        if (table[n][m] != -1)
            return table[n][m];

        // If the last characters of the strings match.
        if (s1[n - 1] == s2[m - 1])
            return table[n][m] = 1 + lcsHelper(n - 1, m - 1, s1, s2, table);
        else
            // If the last characters don't match, consider two cases:
            // 1. Exclude the last character of the first string and find LCS.
            // 2. Exclude the last character of the second string and find LCS.
            return table[n][m] = max(lcsHelper(n - 1, m, s1, s2, table), lcsHelper(n, m - 1, s1, s2, table));
    }
};
