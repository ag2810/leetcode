class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i, l;
        for(i = n - 2;i >= 0;i--) {
            if(nums[i + 1] > nums[i])
                break;
        }
        if(i < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for(l = n - 1;l > i;l--) {
                if(nums[i] < nums[l])
                    break;
            }
            
            swap(nums[i], nums[l]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};