class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> mp;
        
        for(int i = 0;i < s.length();i++) mp[s[i]]++;
        for(int i = 0;i < t.length();i++) mp[t[i]]--;
        
        int ans = 0;
        
        for(auto it : mp) ans += abs(it.second);
        
        return ans / 2;
    }
};