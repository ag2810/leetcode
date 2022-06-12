class Solution {
public:
    int dp[1001][1001];
    int charSum(int index, string s) {
        int sum = 0;
        for(int i = 0;i < index;i++) sum += (int)s[i];
        return sum;
    }
    
    int minimumDeleteSumUtil(int m, int n, string s1, string s2) {
        if(m == 0) return charSum(n, s2);
        if(n == 0) return charSum(m, s1);
    
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m - 1] == s2[n - 1]) return dp[m][n] = minimumDeleteSumUtil(m - 1, n - 1, s1, s2);
        
        else {
            int option1 = (int)s1[m - 1] + minimumDeleteSumUtil(m - 1, n, s1, s2);
            int option2 = (int)s2[n - 1] + minimumDeleteSumUtil(m, n - 1, s1, s2);

            return dp[m][n] = min(option1, option2);
        }
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int dp[m + 1][n + 1];
        
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0;i <= m;i++) {
            for(int j = 0;j <= n;j++) {
                if(i == 0) dp[i][j] = charSum(j, s2);
                
                else if(j == 0) dp[i][j] = charSum(i, s1);

                else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];

                else dp[i][j] = min((int)s1[i - 1] + dp[i - 1][j], (int)s2[j - 1] + dp[i][j - 1]);               
            }
        }
        
        return dp[m][n];
    }
};