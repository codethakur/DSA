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
