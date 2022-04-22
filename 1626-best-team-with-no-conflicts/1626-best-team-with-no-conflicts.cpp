class Solution {
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        int size = s.size();
        vector<pair<int, int>> players;
        
        for(int i = 0;i < size;i++) players.push_back({a[i], s[i]});
        
        sort(players.begin(), players.end(), greater<>());
        
        vector<int> dp(size, 0);
        int ans = 0;
        
        for(int i = 0;i < size;i++) {
            dp[i] = players[i].second;
            for(int j = 0;j < i;j++) {
                if(players[i].second <= players[j].second) {
                    dp[i] =  max(dp[i], dp[j] + players[i].second);
                }
            }
            ans = max(dp[i], ans);
        }
        
        return ans;
    }
};