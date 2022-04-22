class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        if(len1 > len2) return false;
        
        vector<int> s1hash(26, 0);
        vector<int> s2hash(26, 0);
        
        for(int i = 0;i < len1;i++) {
            s1hash[s1[i] - 'a'] += 1;
            s2hash[s2[i] - 'a'] += 1;
        }
        
        int left = 0;
        int right = len1 - 1;
        
        while(right < len2) {
            if(s1hash == s2hash) return true;
            
            right += 1;
            if(right != len2) 
                s2hash[s2[right] - 'a'] += 1;
            
            s2hash[s2[left] - 'a'] -= 1;
            left += 1;   
        }
        
        return false;
    }
};