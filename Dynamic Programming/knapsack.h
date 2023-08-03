#include "knapsack.h"

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
