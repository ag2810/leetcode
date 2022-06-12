class Solution {
public:
    bool findAndReplacePatternUtil(string str1, string str2) {
        int n = str1.length();
        vector<int> visited(26, 0);
        unordered_map<char, char> mp;
        
        for(int i = 0;i < n;i++) {
            char ch1 = str1[i], ch2 = str2[i];
            
            if(mp[ch1] && mp[ch1] != ch2) return false;
            if(!mp[ch1] && visited[ch2 - 'a']) return false;
            
            mp[ch1] = ch2, visited[ch2 - 'a'] = 1;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto word : words) if(findAndReplacePatternUtil(pattern, word)) ans.push_back(word);
        
        return ans;
    }
};