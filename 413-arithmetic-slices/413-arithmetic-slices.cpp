class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1 || n == 2) return 0;
        
        vector<int> diff(n, 0);
        vector<int> res(n, 0);
        int sum = 0;
        
        for(int i = 1;i < n;i++) diff[i] = (nums[i] - nums[i - 1]);
        
        res[0] = 0, res[1] = 0;
        
        for(int i = 2;i < n;i++) {
            if(diff[i - 1] == (nums[i] - nums[i - 1])) res[i] = 1 + res[i - 1];
            else res[i] = 0;
            
            sum += res[i];
        }
        
        return sum;
    }
};