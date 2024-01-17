#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int minCoins(std::vector<int>& coins, int M, int V) {
        // Your code goes here
        int table[M + 1][V + 1];

        for (int i = 0; i <= M; ++i) {
            table[i][0] = 0;
        }
        for (int j = 1; j <= V; ++j) {
            table[0][j] = INT_MAX - 1;
        }

        for (int j = 1; j <= V; j++) {
            if (j % coins[0] == 0)
                table[1][j] = j / coins[0];
            else
                table[1][j] = INT_MAX - 1;
        }

        for (int i = 2; i <= M; i++) {
            for (int j = 1; j <= V; j++) {
                if (coins[i - 1] <= j)
                    table[i][j] = std::min(table[i][j - coins[i - 1]] + 1, table[i - 1][j]);
                else
                    table[i][j] = table[i - 1][j];
            }
        }

        // Check if it's possible to make change for the given value
        if (table[M][V] == INT_MAX - 1)
            return -1;

        return table[M][V];
    }
};
