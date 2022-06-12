class Solution {
public:
    int maxSum = 0;

    void maxSumDivThreeUtil(int index, int sum, vector<int>& nums) {
        if(index == nums.size()) return;
        
        maxSumDivThreeUtil(index + 1, sum, nums);
        
        sum += nums[index];
        
        if(sum % 3 == 0) maxSum = max(maxSum, sum);
        
        maxSumDivThreeUtil(index + 1, sum, nums);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < 3;j++) {
                if(i == 0) {
                    int index = nums[i] % 3;
                    dp[i][index] = max(dp[i][index], nums[i]);
                }
                else {
                    int index = (dp[i - 1][j] + nums[i]) % 3;
                    dp[i][index] = max(dp[i][index], dp[i-1][j] + nums[i]);
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
            }
        }
        
        return dp[n-1][0];
    }
};