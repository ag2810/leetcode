class Solution {
public:
    int lcs(string &s, string  &t) {
        int len = s.length();
    
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0)); 
        
        for(int i = 0;i <= len;i++) {
            for(int j = 0;j <= len;j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[len][len];
    }
    
    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s.length() - lcs(s, s1);
    }
};