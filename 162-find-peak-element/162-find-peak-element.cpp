class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
        
        int mid, low = 0, high = nums.size() - 1, n = nums.size();
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            
            if((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == n - 1 && nums[n - 1] > nums[n - 2]) || (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])) return mid;
        
            else if(nums[mid] > nums[mid + 1]) high = mid - 1;
            
            else low = mid + 1;
        }
        
        return -1;
    }
};