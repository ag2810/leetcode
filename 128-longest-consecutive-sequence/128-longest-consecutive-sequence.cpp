class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int countMax = 0;
        for(int i = 0;i < nums.size();i++) mp[nums[i]]++;
        for(int i = 0;i < nums.size();i++) {
            if(mp[nums[i] - 1]) continue;
            else {
                int count = 1;
                int j = 1;
                while(mp[nums[i] + j]) {
                    count++;
                    j++;
                }
                countMax = max(countMax, count);
            }
        }
        return countMax;
    }
};