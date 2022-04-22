class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int maxsum = 0;
        int i = 0, j = 0;
        set<int> s;
        while(i < nums.size() && j < nums.size()) {
            if(s.find(nums[j]) == s.end())
            {
                sum = sum + nums[j];
                s.insert(nums[j]);
                maxsum = max(maxsum, sum);
                j++;
            }
            else {
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
        }
        return maxsum;
    }
};