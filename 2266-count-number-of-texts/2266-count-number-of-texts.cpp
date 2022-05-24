class Solution {
public:
    int countTexts(string s) {
        int n = s.length();
        int mod = 1e9 + 7;
        
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        
        for(int i = 1;i <= n;i++) {
            char ch = s[i - 1];
            
            dp[i] = dp[i - 1];
            
            if(i >= 2 && s[i - 2] == ch) dp[i] = (dp[i] + dp[i - 2]) % mod;
            else continue;
            
            if(i >= 3 && s[i - 3] == ch) dp[i] = (dp[i] + dp[i - 3]) % mod;
            else continue;
            
            if(i >= 4 && s[i - 4] == ch && (ch == '7' || ch == '9')) dp[i] = (dp[i] + dp[i - 4]) % mod;
            else continue;
        }
        
        return dp[n];
    }
};