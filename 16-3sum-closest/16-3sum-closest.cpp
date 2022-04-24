class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(); 
        int closest = INT_MAX;
        int minDiff = INT_MAX;
        
        for (int i = 0; i < n-2; i++) {
            int start = i + 1;
            int end = n - 1;
            
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                
                if (abs(sum - target) < minDiff) {
                    minDiff = abs(sum - target);
                    closest = sum;
                }
                
                if (sum == target) return sum;
                
                if (sum > target) end--; 
                
                else start++; 
            }
        }
        return closest;
    }

};