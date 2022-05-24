class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0, sum = 0;
        map<int, int> mp;
        
        for(int i = 0;i < nums.size();i++) if(nums[i] == 0) nums[i] = -1;
        
        for(int i = 0;i < nums.size();i++) {
            sum += nums[i];
            
            if(sum == 0) {
                maxLen = max(maxLen, i + 1);
                continue;
            }
            
            if(mp.find(sum) == mp.end()) mp[sum] = i;
            
            else maxLen = max(maxLen, i - mp[sum]);
        }
        
        return maxLen;
    }
};