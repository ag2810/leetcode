class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        
        for(int i = 0;i < s.length();i++) {
            ans.push_back(s[i]);
            if(ans.size() >= part.size() && (ans.substr(ans.size() - part.size()) == part))
            {
                int len = part.length();
                while(len--) ans.pop_back();
            }
        }
        
        return ans;
    }
};