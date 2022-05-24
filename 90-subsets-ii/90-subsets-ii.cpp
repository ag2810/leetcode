class Solution {
public:
    void subsetsWithDupUtil(int index, bool pre, vector<int>& nums, vector<int>& ans, vector<vector<int>>& res) {
        if(index >= nums.size()) {
            res.push_back(ans);
            return;
        }
        
        subsetsWithDupUtil(index + 1, false, nums, ans, res);
        if(index > 0 && nums[index] == nums[index - 1] && !pre) return;
        ans.push_back(nums[index]);
        subsetsWithDupUtil(index + 1, true, nums, ans, res);
        ans.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        subsetsWithDupUtil(0, false, nums, ans, res);
        return res;
    }
};