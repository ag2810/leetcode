class Solution {
public:
    int longestCommonSubsequenceUtil(int i, int j, string s1, string s2,                       vector<vector<int>>& dp) {
        if(i == s1.length() || j == s2.length()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return 1 + longestCommonSubsequenceUtil(i + 1, j + 1, s1, s2,           dp);
        
        return dp[i][j] = max(longestCommonSubsequenceUtil(i + 1, j, s1, s2, dp),                                     longestCommonSubsequenceUtil(i, j + 1, s1, s2, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0;i <= m;i++) dp[i][0] = 0;
        for(int j = 0;j <= n;j++) dp[0][j] = 0;
        
        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return dp[m][n];
    }
};