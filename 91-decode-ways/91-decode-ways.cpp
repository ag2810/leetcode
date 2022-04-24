class Solution {
public:
    int numDecodingsUtil(int i, string s, vector<int> dp) {
        if(i == s.length()) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        if(s[i] - '0' == 0) return 0;
        
        int pickOne = numDecodingsUtil(i + 1, s, dp);
        
        int pickBoth = 0;
        
        if(i + 1 < s.length() && ((s[i] - '0' == 1 && s[i + 1] - '0' <= 9) || (s[i] - '0' == 2 && s[i + 1] - '0' < 7))) pickBoth = numDecodingsUtil(i + 2, s, dp);
            
        return dp[i] = pickOne + pickBoth;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        
        dp[n] = 1;
        for(int i = n - 1;i >= 0;i--) {
            if(s[i] == '0') dp[i] = 0;
            else {
                dp[i] = dp[i + 1];
                if(i < n - 1 && (s[i] - '0' == 1 || (s[i] - '0' == 2 && s[i + 1] - '0' < 7))) dp[i] += dp[i + 2];
                //if(i < n-1 && (s[i] - '0' == 1 || (s[i] - '0' == 2 && s[i + 1] - '0' < 7))) dp[i] += dp[i + 2];
            }
        }
        
        for(int i = 0;i <= n;i++) cout<<dp[i]<<" ";
        
        return dp[0];
    }
};