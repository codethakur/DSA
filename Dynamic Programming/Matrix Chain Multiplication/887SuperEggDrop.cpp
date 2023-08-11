#include<bits/stdc++.h>
using namespace std;

const int MAX_EGGS = 105;
const int MAX_FLOORS = 10005;

class Solution {
public:
    int dp[MAX_EGGS][MAX_FLOORS];
    
    int solve(int egg, int floor) {
        if (floor == 0 || floor == 1) return floor;
        if (egg == 1) return floor;
        if (dp[egg][floor] != -1) return dp[egg][floor];

        int mn = INT_MAX;
        for (int k = 1; k <= floor; k++) {
            int low, high;

            if (dp[egg - 1][k - 1] != -1)
                low = dp[egg - 1][k - 1];
            else
                low = solve(egg - 1, k - 1);
            dp[egg - 1][k - 1] = low;

            if (dp[egg][floor - k] != -1)
                high = dp[egg][floor - k];
            else
                high = solve(egg, floor - k);
            dp[egg][floor - k] = high;

            int tempAns = 1 + max(low, high);
            mn = min(mn, tempAns);
        }
        return dp[egg][floor] = mn;
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};
