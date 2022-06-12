class Solution {
public:
    int ans;
    void countArrangementUtil(int index, vector<int>& nums) {
        if(index == nums.size()) {
            ans++;
            return;
        }
        
        for(int i = index;i < nums.size();i++) {
            swap(nums[index], nums[i]);
            if((nums[index] % (index + 1) == 0) || ((index + 1) % nums[index] == 0)) 
                countArrangementUtil(index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }
    
    int countArrangement(int n) {
        ans = 0;
        vector<int> nums;
        for(int i = 0;i < n;i++) nums.push_back(i + 1);
        countArrangementUtil(0, nums);
        return ans;
    }
};