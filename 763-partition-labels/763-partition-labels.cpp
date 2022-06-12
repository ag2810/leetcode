class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        vector<int> ans;
        
        for(int i = 0;i < s.length();i++) mp[s[i]] = i;
        
        int maxIndex = 0, prev = -1;
        
        for(int i = 0;i < s.length();i++) {
            maxIndex = max(maxIndex, mp[s[i]]);
            
            if(maxIndex == i) {
                ans.push_back(i - prev);
                prev = i;
            }
        }
        
        return ans;
    }
};