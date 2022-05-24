class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int start = 0;
        int maxFreq = 0;
        
        map<int, int> mp;
        
        for(int i = 0;i < s.length();i++) {
            maxFreq = max(maxFreq, ++mp[s[i] - 'a']);
            while(i - start - maxFreq + 1 > k) {
                mp[s[start] - 'a']--;
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};