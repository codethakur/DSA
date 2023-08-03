//#include "knapsack.h"
#include<bits/stdc++.h>
using namespace std;

bool knapsack(int arr[], int sum, int n)
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
    return table[n][sum];
}

bool isSubsetSum(int arr[], int n, int sum)
{
    return knapsack(arr, sum, n);
}

int main()
{
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;

    if (isSubsetSum(arr, n, sum))
        cout << "Subset with the given sum exists." << endl;
    else
        cout << "No subset with the given sum exists." << endl;

    return 0;
}
