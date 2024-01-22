#include <iostream>
using namespace std;

class Solution {
public:
    void printLongestRepeatingSubsequence(string str) {
        int n = str.length();

        // Create and initialize DP table
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = 0;

        // Fill dp table (similar to LCS loops)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match and indexes are 
                // not same
                if (str[i - 1] == str[j - 1] && i != j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                // If characters do not match
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        // Find the length of the longest repeating subsequence
        int length = dp[n][n];

        // Build the longest repeating subsequence
        string repeatingSubsequence;
        int i = n, j = n;
        while (i > 0 && j > 0) {
            if (str[i - 1] == str[j - 1] && i != j) {
                repeatingSubsequence.push_back(str[i - 1]);
                i--, j--;
            } else if (dp[i][j - 1] > dp[i - 1][j]) {
                j--;
            } else {
                i--;
            }
        }

        // Reverse the string to get the correct order
        reverse(repeatingSubsequence.begin(), repeatingSubsequence.end());

        cout << "Longest Repeating Subsequence: " << repeatingSubsequence << endl;
    }
};

int main() {
    Solution solution;
    string input;
    
    cout << "Enter the string: ";
    cin >> input;

    solution.printLongestRepeatingSubsequence(input);

    return 0;
}
