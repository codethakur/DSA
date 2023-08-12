int table[101][101];
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n;j++)
            {
                table[i][j]= -1;
            }
        }
        return LCS(obstacleGrid, m, n);
    }
    int LCS(vector<vector<int>>& obstacleGrid, int m, int n)
    {
        if(m==0 || n==0) return 0;

         if (table[m][n] != -1) {
            return table[m][n];
        }
        if(obstacleGrid[m-1][n-1] == 1){
            return table[m][n]=0;
        }
        if(m==1 && n==1){
            return table[m][n]=1;
        }
         return table[m][n] = LCS(obstacleGrid, m-1,n) + LCS(obstacleGrid,m,n-1);
    }
};
