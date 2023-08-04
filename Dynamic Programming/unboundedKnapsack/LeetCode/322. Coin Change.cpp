class Solution {
public:
    int unboundedknapsack(int coins[], int amount, int n) {
        int table[n + 1][amount + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < amount + 1; j++) {
                if (i == 0)
                    table[i][j] = INT_MAX - 1; // Initialize with a large value
                else if (j == 0)
                    table[i][j] = 0;
                else if (coins[i - 1] <= j)
                    table[i][j] = min(table[i][j - coins[i - 1]] + 1, table[i - 1][j]);
                else
                    table[i][j] = table[i - 1][j];
            }
        }
        return table[n][amount] == INT_MAX - 1 ? -1 : table[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int coinsArray[n];
        for (int i = 0; i < n; i++) {
            coinsArray[i] = coins[i];
        }
        return unboundedknapsack(coinsArray, amount, n);
    }
};
