class Solution {
public:
    int canPartitionUtil(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(index == 0) {
            if(nums[index] == target) return 1;
            return 0;
        }    
        
        if(dp[index][target] != -1) return dp[index][target];
        
        bool notTake = canPartitionUtil(index - 1, target, nums, dp);
        
        bool take = 0;
        if(nums[index] <= target)
            take = canPartitionUtil(index - 1, target - nums[index], nums, dp);
        
        return dp[index][target] = take || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int i = 0;i < nums.size();i++) sum += nums[i];
        
        if(sum % 2) return false;
        
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        
        if(canPartitionUtil(nums.size() - 1, sum / 2, nums, dp)) return true;
        
        return false;
    }
};