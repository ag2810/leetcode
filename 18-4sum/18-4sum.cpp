class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        int n = nums.size();
        
        if(n == 0) return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                int newTarget = target - nums[i] - nums[j];
                
                int start = j + 1;
                int end = n - 1;
                
                while(start < end){
                    int twoSum = nums[start] + nums[end];
                    
                    if(twoSum < newTarget) start++;
                
                    else if(twoSum > newTarget) end--;

                    else {
                        int val1 = nums[start];
                        int val2 = nums[end];
                        
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        
                        while(start < end && nums[start] == val1) ++start;
                        while(start < end && nums[end] == val2) --end;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};