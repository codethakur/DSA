#include<bits/stdc++.h>
using namespace std;

int knapsack(int arr[], int sum, int n)
{
    bool table[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                table[i][j] = false;
            if (j == 0)
                table[i][j] = true;
            else if (arr[i - 1] <= j)
                table[i][j] = (table[i - 1][j - arr[i - 1]] || table[i - 1][j]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    // Find the maximum sum in the last row with value true
    int minDiff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--) {
        if (table[n][j] == true) {
            minDiff = sum - 2 * j;
            break;
        }
    }
    return minDiff;
}
int minSubsetSumDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int minDiff = knapsack(arr, sum, n);
    return minDiff;
}
int main()
{
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int minDiff = minSubsetSumDifference(arr, n);
    cout << "Minimum Subset Sum Difference: " << minDiff << endl;

    return 0;
}

