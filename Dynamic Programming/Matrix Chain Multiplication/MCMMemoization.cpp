#include <bits/stdc++.h>
using namespace std;

// Initialize a memoization table to store results
int memo[101][101]; // Adjust the size based on your requirements

int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int tempAns = solve(arr, i, k) +
                    solve(arr, k + 1, j) +
                      arr[i - 1] * arr[k] * arr[j];

        mn = min(mn, tempAns);
    }

    return memo[i][j] = mn;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int i = 1; // Start index
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = n - 1; // End index

    // Initialize the memoization table with -1
    memset(memo, -1, sizeof(memo));

    cout << solve(arr, i, j);
    return 0;
}
