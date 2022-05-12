class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 9;
        int k = 9;
        int sum = 10;
        
        for(int i = 2;i <= n;i++) {
            dp[i] = dp[i - 1] * k;
            sum += dp[i];
            k--;
        }
        
        return sum;
    }
};