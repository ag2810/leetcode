class Solution {
public:
    int maxSubarraySumCircularUtil(vector<int>& nums) {
        int n = nums.size();
        int csum = 0, osum = INT_MIN;
        
        for(int i = 0;i < n;i++) {
            if(csum >= 0) csum += nums[i];
            else csum = nums[i];
            osum = max(osum, csum);
        }
        
        return osum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_normal = maxSubarraySumCircularUtil(nums);
        if(max_normal < 0) return max_normal;
        
        int n = nums.size();
        
        for(int i = 0;i < n;i++) nums[i] = (-1) * nums[i];
        
        int csum = 0, osum = INT_MIN, tsum = 0;
        
        for(int i = 0;i < n;i++) {
            tsum += nums[i];
            if(csum >= 0) csum += nums[i];
            else csum = nums[i];
            osum = max(osum, csum);
        }

        int res = (-1) * tsum - (-1) * osum;
        
        return max(max_normal, res);
    }
};