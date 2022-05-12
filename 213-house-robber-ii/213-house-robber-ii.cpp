class Solution {
public:
    int robUtil1(vector<int>& nums, int index) {
        if(index < 0) return -1e9;
        
        if(index == 0) return nums[0];
        
        int notPick = robUtil1(nums, index - 1);
        
        int pick = nums[index] + robUtil1(nums, index - 2);
        
        return max(pick, notPick);
    }
    int robUtil(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        
        for(int i = 2;i < n;i++) {
            dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
        }
        
        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<int> temp1, temp2;
        
        for(int i = 0;i < n;i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }

        return max(robUtil(temp1), robUtil(temp2));
    }
};