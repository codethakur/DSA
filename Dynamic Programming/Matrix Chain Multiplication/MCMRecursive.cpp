#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j)
{
    if (i >= j) return 0;

    int mn = INT_MAX;
    for (int k = i; k < j; k++) // Adjusted loop condition
    {
        int tempAns = solve(arr, i, k) +
                    solve(arr, k + 1, j) +
                      arr[i - 1] * arr[k] * arr[j];

        if (tempAns < mn){
            mn = tempAns;
        }            
    }
    return mn;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int i = 1; // Start index
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = n - 1; // End index
    cout << solve(arr, i, j);
    return 0;
}
