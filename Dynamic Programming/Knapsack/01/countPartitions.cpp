class Solution {
  public:
        int subsetSum(std::vector<int>& arr, int sum) {
        int n = arr.size();
        // Initializing the matrix
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum + 1, 0));
        // Initializing the first value of matrix
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                // if the value is greater than the sum
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][sum];
    }

    int countPartitions(int n, int d, std::vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        int reqSum = (d + sum) / 2;
        return subsetSum(arr, reqSum);
    }
};

//`````````````````````````````````````````````---------------------------`````````````````````````
class Solution {
  public:
    int countPartitions(int n, int d, std::vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if (sum < d || (sum + d) % 2 != 0) {
            return 0;
        }

        int newSum = (d + sum) / 2;
        if (newSum < 0) {
            return 0;
        }

        const int MOD = 1000000007;
        std::vector<int> dp(newSum + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = newSum; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }

        return dp[newSum] % MOD;
    }
};
