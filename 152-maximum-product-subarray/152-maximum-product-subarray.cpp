class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int ans = INT_MIN;
        
        int cprod = 1;
        
        for(int i = 0;i < n;i++) {
            cprod = cprod * nums[i];
            ans = max(ans, cprod);
            if(cprod == 0) cprod = 1;
        }
        
        cprod = 1;
        
        for(int i = n - 1;i >= 0;i--) {
            cprod = cprod * nums[i];
            ans = max(ans, cprod);
            if(cprod == 0) cprod = 1;
        }
        
        return ans;
    }
};