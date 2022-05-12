class Solution {
public:
    int minFallingPathSumUtil(int i, int j, vector<vector<int>>& m, vector<vector<int>>& dp) {
        if(j < 0 || j >= m[0].size()) return 1e9;
        if(i == 0) return m[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = m[i][j] + minFallingPathSumUtil(i - 1, j, m, dp);
        int left = m[i][j] + minFallingPathSumUtil(i - 1, j - 1, m, dp);
        int right = m[i][j] + minFallingPathSumUtil(i - 1, j + 1, m, dp);
        
        return dp[i][j] = min(up, min(left, right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c, -1));
        int ans = INT_MAX;
        
        for(int j = 0;j < c;j++) {
            ans = min(ans, minFallingPathSumUtil(r - 1, j, matrix, dp));
            
        }
        
        return ans;
    }
};