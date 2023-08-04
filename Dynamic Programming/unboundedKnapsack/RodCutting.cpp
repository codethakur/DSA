#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int length[], int prices[], int N)
{
    int table[N+1][N+1];
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            if(i==0 || j==0)
            {
                table[i][j] = 0;
                continue;
            }

            if(length[i-1] <= j)
            {
                table[i][j] = max(prices[i-1] + table[i][j-length[i-1]], table[i-1][j]);
            }
            else
            {
                table[i][j] = table[i-1][j];
            }
        }
    }
    return table[N][N];
}

int cutRod(int price[], int n)         //GFG Problem
{
    int length[n];
    int prices[n];
    
    // Creating lengths and prices based on input
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1; // Lengths are 1 to n
        prices[i] = price[i];
    }

    return unboundedKnapsack(length, prices, n);
}

int main()
{
    int n;
    cout << "Enter the number of prices: ";
    cin >> n;

    int price[n];
    
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++)
        cin >> price[i];

    cout << "Maximum value: " << cutRod(price, n) << endl;

    return 0;
}


// int main()
// {
//     int N;
//     cout << "Enter the number of lengths: ";
//     cin >> N;
    
//     int length[N];
//     int prices[N];
    
//     cout << "Enter lengths: ";
//     for(int i = 0; i < N; i++)
//         cin >> length[i];
    
//     cout << "Enter prices: ";
//     for(int i = 0; i < N; i++)
//         cin >> prices[i];

//     cout << "Maximum value: " << unboundedKnapsack(length, prices, N) << endl;

//     return 0;
// }
