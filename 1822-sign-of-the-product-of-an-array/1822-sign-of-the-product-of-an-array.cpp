class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] == 0) return 0;
            else if(nums[i] > 0) continue;
            else neg++;
        }
        
        return (neg % 2) == 0 ? 1 : -1;
    }
};