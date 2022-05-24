class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        map<string, int> mp;
        string ans = "", temp = "", prev = "";
        
        for(auto word : d) mp[word]++;
        
        for(int i = 0; i < s.length();i++) {
            if(s[i] != ' ') {
                temp += s[i];
                if(mp.find(temp) != mp.end()) {
                    ans = ans + temp + ' ';
                    while(i < s.length() && s[i] != ' ') i++;
                    temp = "";
                }
            }
            else {
                ans = ans + temp + ' ';
                prev = temp;
                temp = "";
            }
        }
        
        if(temp.length() > 0 && mp.find(temp) == mp.end()) {
            ans = ans + temp;
            return ans;
        }
        
        return ans.substr(0, ans.length() - 1);
    }
};