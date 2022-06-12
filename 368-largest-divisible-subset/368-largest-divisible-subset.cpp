class Solution {
public:
    vector<int> ans;
    void largestDivisibleSubsetUtil(int index, int prev, vector<int>& nums, vector<int>& temp) {
        if(index == nums.size()) {
            if(temp.size() > ans.size()) ans = temp;
            return;
        }
        
        largestDivisibleSubsetUtil(index + 1, prev, nums, temp);
        
        if(nums[index] % prev == 0) {
            temp.push_back(nums[index]);
            largestDivisibleSubsetUtil(index + 1, nums[index], nums, temp);
            temp.pop_back();
        }
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if(n == 1) return nums;
        
        int maxLen = 0;
        vector<int> dp(n, 1);
        
        for(int i = 1;i < n;i++) {
            for(int j = 0;j < i;j++) {
                if(nums[i] % nums[j] == 0) dp[i] = max(dp[i], 1 + dp[j]);
                maxLen = max(maxLen, dp[i]);
            }
        }
        
        vector<int> ans;
        int prev = -1;
        
        for(int i = dp.size() - 1;i >= 0;i--) {
            if(dp[i] == maxLen && (prev % nums[i] == 0 || prev == -1)) {
                maxLen--;
                ans.push_back(nums[i]);
                prev = nums[i];
            }
        }
        
        return ans;
    }
};