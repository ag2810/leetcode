class Solution {
public:
    int fun(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int firstElementTaken = nums[i] + min(fun(i + 2, j, nums, dp),fun(i + 1, j - 1, nums, dp));
        int lastElementTaken = nums[j] + min(fun(i + 1, j - 1, nums, dp),fun(i, j - 2, nums, dp)); 

        return dp[i][j] = max(firstElementTaken,lastElementTaken);
    }

    bool PredictTheWinner(vector<int>& nums)
    {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int sum = 0;
        
        for(int i = 0;i < n;i++) sum += nums[i];
        
        int best = fun(0, n - 1, nums, dp);
        
        if(best >= sum - best) return true;
        
        return false;
    }
};