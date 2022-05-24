class Solution {
public:
    int numSquaresUtil(int n, vector<int>& dp) {
        if(n <= 3) return n;
        if(dp[n] != -1) return dp[n];
        int ans = n;
        for(int i = 1;i * i <= n;i++) ans = min(ans, 1 + numSquaresUtil((n - (i * i)), dp));
        return dp[n] = ans;
    }
    int numSquares(int n) {
        if(n <= 3) return n;
        
        vector<int> dp(n + 1, 0);
        
        for(int i = 0;i <= 3;i++) dp[i] = i;
        
        for(int i = 1;i <= n;i++) {
            dp[i] = i;
            for(int j = 1;j * j <= i;j++) dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
        }
        
        return dp[n];
    }
};