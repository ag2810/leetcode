class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0;
        int mini = INT_MAX;
        
        while(right < n) {
            sum += nums[right];
            
            if(sum >= target) {
                while(sum >= target) {
                    sum -= nums[left];
                    left++;
                }
                
                mini = min(mini, right - left + 2);
            }
            
            right++;
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};