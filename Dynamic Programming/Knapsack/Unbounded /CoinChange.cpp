class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        long table[N + 1][sum + 1];

        // Initializing all columns of the 0th row with 0
        for (int j = 0; j <= sum; ++j) {
            table[0][j] = 0;
        }
    
        // Initializing 0th column of rows from 1 to N with 1
        for (int i = 1; i <= N; ++i) {
            table[i][0] = 1;
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1]<=j)
                    table[i][j]= table[i][j-coins[i-1]]+table[i-1][j];
                else
                    table[i][j] = table[i-1][j];
            }
        }
        return table[N][sum];
        
    }
};
