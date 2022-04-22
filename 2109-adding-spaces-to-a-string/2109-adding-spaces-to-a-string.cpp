class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int prev = 0;
        int i;
        string res = "";
        for(i = 0;i < spaces.size();i++) {
            res += s.substr(prev, spaces[i] - prev) + " ";
            prev = spaces[i];
        }
        
        res += s.substr(prev);
        
        return res;
    }
};