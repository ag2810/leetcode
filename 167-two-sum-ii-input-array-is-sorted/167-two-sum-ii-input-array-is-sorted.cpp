class Solution {
public:
    int twoSumUtil(int low, int high, int val, vector<int>& nums) {
        if(low > high) return -1;
        
        int mid = low + (high - low) / 2;
        
        if(nums[mid] == val) return mid;
        
        if(nums[mid] < val) return twoSumUtil(mid + 1, high, val, nums);
        
        return twoSumUtil(low, mid - 1, val, nums);
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i < n;i++) {
            int res = twoSumUtil(i + 1, n - 1, target - nums[i], nums);
            if(res != - 1) return ans = {i + 1, res + 1};
        }
        return ans;
    }
};