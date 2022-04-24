class Solution {
public:
    int minPathSumUtil(int m, int n, vector<vector<int>>& grid) {
        if(m < 0 || n < 0) 
            return 1e8;
    
        if(m == 0 && n == 0)
            return grid[m][n];
        
        int left = grid[m][n] + minPathSumUtil(m, n - 1, grid);
        int up = grid[m][n] + minPathSumUtil(m - 1, n, grid);
        
        return min(left, up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int> (n, 0));
        
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else {
                    int up = grid[i][j];
                    if(i > 0) up += dp[i - 1][j];
                    else up += 1e9;
                    
                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j - 1];
                    else left += 1e9;
                    
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};