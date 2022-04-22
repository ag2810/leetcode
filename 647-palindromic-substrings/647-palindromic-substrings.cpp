class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int count = 0;
        for(int c = 0;c < n;c++) {
            for(int i = 0, j = c;j < n;i++, j++) {
                if(c == 0) dp[i][j] = 1;
                else if(c == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = 1;
                        count++;
                    }
                    else dp[i][j] = 0;
                }
                else {
                    if(s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                        count++;
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        
        return count + n;
    }
};