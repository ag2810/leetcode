class Solution {
public:
    int coinChangeUtil(int i, vector<int>& coins, int target, vector<vector<int>>& dp) {
        if(i == 0) {
            if(target % coins[i] == 0) return target / coins[i];
            else return 1e9;
        }    
        
        if(dp[i][target] != -1) return dp[i][target];
        int notTake = coinChangeUtil(i - 1, coins, target, dp);
        int take = INT_MAX;
        if(target >= coins[i])
            take = 1 + coinChangeUtil(i, coins, target - coins[i], dp);
        
        return dp[i][target] = min(take, notTake);
    }
    
    int coinChange(vector<int>& coins, int target) {
        vector<vector<int>> dp(coins.size(), vector<int>(target + 1, 0));
        int n = coins.size();
        
        for(int i = 0;i <= target;i++) {
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }
        
        for(int i = 1;i < n;i++) {
            for(int j = 0;j <= target;j++) {
                int notTake = dp[i - 1][j];
                int take = INT_MAX;
                
                if(j >= coins[i]) take = 1 + dp[i][j - coins[i]];

                dp[i][j] = min(take, notTake);
            }
        }
        
        int ans = dp[n - 1][target];
        
        return (ans == 1e9) ? -1 : ans;
    }
};