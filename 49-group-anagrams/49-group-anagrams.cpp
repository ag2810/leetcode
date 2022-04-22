class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        
        for(int i = 0;i < strs.size();i++)
        {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            ump[strs[i]].push_back(temp);
        }
        
        vector<vector<string>> res;
        
        for(auto it = ump.begin();it != ump.end();it++)
        {
            res.push_back(it -> second);
        }
        
        return res;
    }
};