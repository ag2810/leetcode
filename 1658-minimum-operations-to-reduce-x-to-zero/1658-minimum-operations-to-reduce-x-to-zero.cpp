class Solution {
public:
    unordered_map<string, int> dp;
    int solve(int left, int right, int x, int count, vector<int>&nums) {
        if(x == 0) return count;
        
        if(x < 0 || left > right) return 1e6;
        
        string key = to_string(left) + "*" + to_string(right) + "*" + to_string(x);
        
        if(dp.count(key)) return dp[key];
        
        int leftTaken = solve(left + 1, right, x - nums[left], count + 1, nums);
        int rightTaken = solve(left, right - 1, x - nums[right], count + 1, nums);
        
        return dp[key] = min(leftTaken, rightTaken);
    }
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        
        mp[0] = 0;
        
        for(int i = 0;i < n;i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        
        if(sum < x) return -1;
        
        mp[0] = 0;
        
        sum = sum - x;
        int longest = 0, val = 0;
        
        for(int i = 0;i < n;i++) {
            val += nums[i];
            if(mp.count(val - sum)) {
                if(val - sum == 0) longest = max(longest, i - mp[val - sum] + 1);
                else longest = max(longest, i - mp[val - sum]);
            }
        }
        
        return longest == 0 ? (sum == 0 ? n : -1) : n - longest;
    }
};