class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        
        vector<int> v1(26, 0), v2(26, 0), vec1(26, 0), vec2(26, 0);
        
        for(auto ch : word1) {
            v1[ch - 'a']++;
            vec1[ch - 'a'] = 1;
        }
        for(auto ch : word2) {
            v2[ch - 'a']++;
            vec2[ch - 'a'] = 1;
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return v1 == v2 && vec1 == vec2;
    }
};