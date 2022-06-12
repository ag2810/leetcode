class Solution {
public:
    long long dp[100005][2];
    
    long long solve(vector<int>& nums, int index, int sign){
        if(index >= nums.size()) return 0;
        
        if(dp[index][sign] != -1) return dp[index][sign];
         
        long long notTake = solve(nums, index + 1, sign);
        
        long long take = 0;
        
        if(sign) take = nums[index] + solve(nums, index + 1, 0);
        else take = -1 * 1LL* nums[index] + solve(nums, index + 1, 1);
        
        return dp[index][sign] = max(notTake, take);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 1);       
    }
};