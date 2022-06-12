class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        
        for(int i = 0;i < g.size();i++) {
            if(mp[g[i]].size() <= g[i]) mp[g[i]].push_back(i);
            if(mp[g[i]].size() == g[i]) {
                ans.push_back(mp[g[i]]);
                mp.erase(g[i]);
            }
        }
        
        return ans;
    }
};