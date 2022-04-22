class Solution {
public:
    bool canJumpUtil(int i, vector<int>& nums, vector<int>& dp) {
        if(i == nums.size() - 1) return dp[i] = true;
        
        if(dp[i] != -1) return dp[i];
        
        int maxReach = i + nums[i];
        
        for(int j = i + 1;j <= maxReach;j++) {
            if(canJumpUtil(j, nums, dp)) return dp[i] = true;
        }
        
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), false);
        
        dp[nums.size() - 1] = true;
        
        for(int i = nums.size() - 2;i >= 0;i--) {
            for(int k = 0;k <= nums[i];k++) {
                if(dp[i + k] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};