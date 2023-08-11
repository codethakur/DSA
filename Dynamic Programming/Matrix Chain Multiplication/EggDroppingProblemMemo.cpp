#include<bits/stdc++.h>
using namespace std;

const int MAX_EGGS = 105; // Considering constraints
const int MAX_FLOORS = 10005; // Considering constraints

int dp[MAX_EGGS][MAX_FLOORS];

int solve(int egg, int floor)
{
    if (floor == 0 || floor == 1) return floor;
    if (egg == 1) return floor;
    if (dp[egg][floor] != -1) return dp[egg][floor];

    int mn = INT_MAX;

    for (int k = 1; k <= floor; k++)
    {
        int tempAns = 1 + max(solve(egg - 1, k - 1), solve(egg, floor - k));

        mn = min(mn, tempAns);
    }
    return dp[egg][floor] = mn;
}

int main()
{
    int egg, floor;
    cin >> egg >> floor;

    // Initialize dp array with -1 (indicating no calculation done yet)
    memset(dp, -1, sizeof(dp));

    cout << solve(egg, floor);
    return 0;
}
