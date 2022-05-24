class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
    }
    int findBallUtil(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        
        if(i == grid.size()) return j;
        if(isValid(i, j, grid)) {
            if(grid[i][j] == 1 && isValid(i, j + 1, grid) && grid[i][j + 1] == 1) 
                if(dp[i + 1][j + 1] != -2) return dp[i + 1][j + 1];
                else return dp[i + 1][j + 1] = findBallUtil(i + 1, j + 1, grid, dp);
            
            if(grid[i][j] == -1 && isValid(i, j - 1, grid) && grid[i][j - 1] == -1)
                if(dp[i + 1][j - 1] != -2) return dp[i + 1][j - 1];
                else return dp[i + 1][j - 1] = findBallUtil(i + 1, j - 1, grid, dp);
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, -2));
        vector<int> ans(grid[0].size(), 0);
        for(int j = 0;j < grid[0].size();j++) ans[j] = findBallUtil(0, j, grid, dp);
        return ans;
    }
};