class Solution {
public:
    bool check(string str1, string str2) {
        if(str1.length() == 0 || str2.length() == 0) return false;
        
        unordered_map<char, int> mp1, mp2;
        int dis1 = 0, dis2 = 0;
        
        for(int i = 0;i < str1.length();i++) {
            if(!mp1[str1[i]]) dis1++;
            mp1[str1[i]]++;
        }
        
        for(int i = 0;i < str2.length();i++) {
            if(!mp2[str2[i]]) dis2++;
            mp2[str2[i]]++;
        }
        
        return dis1 == dis2;
    }
    
    int numSplits(string s) {
        int count = 0;
        int n = s.length();
        vector<int> prefix(n, 0), suffix(n, 0);
        unordered_map<char, int> mp;
        
        for(int i = 0;i < n;i++) {
            mp[s[i]]++;
            prefix[i] = mp.size();
        }
        
        mp.clear();
        
        for(int i = n - 1;i >= 0;i--) {
            mp[s[i]]++;
            suffix[i] = mp.size();
        }
        
        for(int i = 0;i < n - 1;i++) if(prefix[i] == suffix[i + 1]) count++;
        
        return count;
    }
};