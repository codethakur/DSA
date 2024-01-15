class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
         int mod = (int)1e9 + 7;

    int t[n + 1][sum + 1];

    for (int i = 0; i <= sum; i++) {
        t[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        t[i][0] = 1;
    }

    // Build the solution table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = (t[i - 1][j] + t[i - 1][j - arr[i - 1]]) % mod;
            } else {
                t[i][j] = (t[i - 1][j]) % mod;
            }
        }
    }

    return t[n][sum];
	}
	  
};
