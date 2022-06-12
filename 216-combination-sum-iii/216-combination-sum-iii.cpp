class Solution {
public:
    vector<vector<int>> ans;
    void combinationSum3Util(int index, int n, int k, vector<int>& nums, vector<int>& temp) {
        if(index == nums.size()) {
            if(k == 0 && n == 0) ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        
        combinationSum3Util(index + 1, n - nums[index], k - 1, nums, temp);
        
        temp.pop_back();
        
        combinationSum3Util(index + 1, n, k, nums, temp);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        for(int i = 0;i < 9;i++) nums[i] = i + 1;
        vector<int> temp;
        combinationSum3Util(0, n, k, nums, temp);
        return ans;
    }
};