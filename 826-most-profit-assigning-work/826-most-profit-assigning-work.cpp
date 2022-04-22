class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> mp;
        
        int best = 0, res = 0, j = 0;
        int p = profit.size();
        int w = worker.size();
        
        for(int i = 0;i < p;i++) mp.push_back(make_pair(difficulty[i], profit[i]));
        
        sort(mp.begin(), mp.end());
        sort(worker.begin(), worker.end());
        
        for(int i = 0;i < w;i++) {
            while(j < p && worker[i] >= mp[j].first) {
                best = max(best, mp[j].second);
                j++;
            } 
            res += best;
        }
        
        return res;
    }
};