class Solution {
public:
    int jump(vector<int>& nums) { 
        int n = nums.size();
        vector<int> dp(n, INT_MAX - 1);
        dp[n - 1] = 0;  
        for(int i = n - 2; i >= 0; i--) {
            int mini = INT_MAX - 1;
            for(int j = i + 1;j <= min(n - 1, i + nums[i]);j++) {
                mini = min(mini, dp[j]);       
            }
            dp[i] = mini + 1;
        }
        return dp[0];
    }
};