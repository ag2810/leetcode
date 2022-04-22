class Solution {
public:
    int longestPalindromeSubseqUtil(string s1, string s2) {
        int len = s1.length(); 
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        for(int i = 0;i <= len;i++) {
            for(int j = 0;j <= len;j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len][len];
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s; 
        
        cout<<s1<<" "<<s2;
        
        return longestPalindromeSubseqUtil(s1, s2);
    }
};