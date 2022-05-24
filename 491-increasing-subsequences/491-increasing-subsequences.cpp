class Solution {
public:
    map <vector<int>, int> mp;
    void findSubsequencesUtil(int index, vector<int>& nums, vector<int> ans, vector<vector<int>>& res) {
        if(ans.size() >= 2) {
            if(mp.find(ans) == mp.end()) 
            {
                res.push_back(ans);
                mp[ans]++;
            }
        }
        if(index == nums.size()) return;
        
        for(int i = index;i < nums.size();i++) {
            if(ans.size() == 0 || nums[i] >= ans[ans.size() - 1]) {
                ans.push_back(nums[i]);
                findSubsequencesUtil(i + 1, nums, ans, res);
                ans.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        findSubsequencesUtil(0, nums, ans, res);
        return res;
    }
};