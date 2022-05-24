class Solution {
public:
    map<string, int> mp;
    bool wordBreakUtil(int index, string s, vector<int>& dp) {
        if(index == s.length()) return true;
        
        if(dp[index] != -1) return dp[index];
        
        for(int i = index;i < s.length();i++) {
            if(mp[s.substr(index, i - index + 1)] && wordBreakUtil(i + 1, s, dp)) return dp[index] = true;
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& words) {
        vector<int> dp(s.length(), -1);
        for(auto word : words) mp[word]++;
        return wordBreakUtil(0, s, dp);
    }
};