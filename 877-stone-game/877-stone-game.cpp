class Solution {
public:
    int stoneGameUtil(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int firstTaken = piles[i] + min(stoneGameUtil(i + 2, j, piles, dp), stoneGameUtil(i + 1, j - 1, piles, dp));
        int lastTaken = piles[j] + min(stoneGameUtil(i + 1, j - 1, piles, dp), stoneGameUtil(i, j - 2, piles, dp));
        
        return dp[i][j] = max(firstTaken, lastTaken);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        
        int sum = 0;
        for(int i = 0;i < piles.size();i++) sum += piles[i];
        
        int score = stoneGameUtil(0, piles.size() - 1, piles, dp);
        
        if(sum - score > score) return false;
        return true;
    }
};