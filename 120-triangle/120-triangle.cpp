class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        int len = triangle.size();
        for(int j = 0;j < len;j++)
        {
            dp[len - 1][j] = triangle[len - 1][j]; 
        }
        
        for(int i = len - 2;i >= 0;i--)
        {
            for(int j = i;j >= 0;j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                
                dp[i][j] = min(down, diagonal);
            }
        }
        
        return dp[0][0];
    }
};