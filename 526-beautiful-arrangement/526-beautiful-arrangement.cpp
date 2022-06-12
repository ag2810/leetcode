class Solution {
public:
    int ans;
    void countArrangementUtil(int index, vector<vector<int>>& temp, vector<int>& nums) {
        if(index == nums.size()) {
            ans++;
            temp.push_back(nums);
            return;
        }
        
        for(int i = index;i < nums.size();i++) {
            if((nums[i] % (index + 1) == 0) || ((index + 1) % nums[i] == 0)) {
                swap(nums[index], nums[i]);
                countArrangementUtil(index + 1, temp, nums);
                swap(nums[index], nums[i]);
            }
        }
    }
    
    int countArrangement(int n) {
        ans = 0;
        vector<int> nums;
        vector<vector<int>> temp;
        for(int i = 0;i < n;i++) nums.push_back(i + 1);
        countArrangementUtil(0, temp, nums);
        return ans;
    }
};