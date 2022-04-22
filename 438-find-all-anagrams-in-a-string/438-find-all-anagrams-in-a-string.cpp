class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slength = s.length();
        int plength = p.length();
        vector<int> res;
        
        if(slength < plength) return res;
        
        vector<int> shash(26, 0);
        vector<int> phash(26, 0);
        
        int i;
        
        for(i = 0;i < plength;i++) {
            shash[s[i] - 'a']++;
            phash[p[i] - 'a']++;
        }
        int right = i;
        int left = 0;
        
        while(right < slength) {
            if(shash == phash) res.push_back(left);
            
            shash[s[left] - 'a']--;
            left++;
            shash[s[right] - 'a']++;
            right++;
        }
        
        if(shash == phash) res.push_back(left);
        
        return res;
    }
};