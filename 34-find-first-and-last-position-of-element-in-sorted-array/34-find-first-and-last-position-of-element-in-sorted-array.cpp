class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int len = nums.size();
        
        int low = 0, high = len - 1, res = -1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                res = mid;
                high = mid - 1;
            }
        }
        
        ans.push_back(res);
        
        low = 0; high = len - 1; res = -1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                res = mid;
                low = mid + 1;
            }
        }
        
        ans.push_back(res);
        
        return ans;
    }
};