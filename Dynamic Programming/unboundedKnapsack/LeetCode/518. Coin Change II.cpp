class Solution {
public:
    int unboundedknapsack(int coins[], int amount, int n) {
        int table[n + 1][amount + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < amount + 1; j++) {
                if (i == 0)
                    table[i][j] = 0;  // Set to 0 as no coins are available
                else if (j == 0)
                    table[i][j] = 1;  // Set to 1 as there's one way to make 0 amount with any number of coins
                else if (coins[i - 1] <= j)
                    table[i][j] = table[i][j - coins[i - 1]] + table[i - 1][j];
                else
                    table[i][j] = table[i - 1][j];
            }
        }
        return table[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int coinsArray[n];
        for (int i = 0; i < n; i++) {
            coinsArray[i] = coins[i];
        }
        return unboundedknapsack(coinsArray, amount, n);
    }
};
