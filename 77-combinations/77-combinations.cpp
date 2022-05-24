class Solution {
public:
    void combineUtil(int index, int k, vector<int>& nums, vector<int>& ans, vector<vector<int>>& res) {
        if(k == 0) {
            res.push_back(ans);
            return;
        }
        
        for(int i = index;i <= nums.size() - k;i++) {
            ans.push_back(nums[i]);
            combineUtil(i + 1, k - 1, nums, ans, res);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> nums, ans;
        for(int i = 0;i < n;i++) nums.push_back(i + 1);
        combineUtil(0, k, nums, ans, res);
        return res;
    }
};