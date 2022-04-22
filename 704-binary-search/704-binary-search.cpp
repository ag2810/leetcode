class Solution {
public:
    int bsearch(vector<int>& nums, int target, int high, int low) {
        int mid = low + (high - low) / 2;
        
        if(low <= high)
        {   
            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target) {
                return bsearch(nums, target, high, mid + 1);
            }
            else {
                return bsearch(nums, target, mid - 1, low);
            }
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        return bsearch(nums, target, high, low);
    }
};