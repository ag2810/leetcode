class Solution {
public:
    int uniquePathsWithObstaclesUtil(int m, int n, vector<vector<int>>& obstacleGrid,           vector<vector<int>> dp) {
        if(m > 0 && n > 0 && obstacleGrid[m][n] == 1) return 0;
        
        if(m == 0 && n == 0) return 1;
        
        if(m < 0 || n < 0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int up = uniquePathsWithObstaclesUtil(m - 1, n, obstacleGrid, dp);
        int left = uniquePathsWithObstaclesUtil(m , n - 1, obstacleGrid, dp);
        
        return dp[m][n] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 
        
        int dp[m][n];
        
        for(int i = 0;i < m;i++) {
            for(int j = 0; j < n;j++) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    
                    if(i > 0) up = dp[i - 1][j];
                    if(j > 0) left = dp[i][j - 1];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};