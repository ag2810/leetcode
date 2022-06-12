class Solution {
public:
    int dp[101][201];
    int stoneGameIIUtil(int i, int m, vector<int>& p) {
        if(i >= p.size()) return 0;
        
        int total = 0;
        int ans = INT_MIN;
        
        if(dp[i][m] != -1) return dp[i][m]; 
        
        for(int j = 0;j < 2 * m;j++) {
            if(i + j < p.size()) total += p[i + j];
            ans = max(ans, total - stoneGameIIUtil(i + j + 1, max(m, j + 1), p));
        }
        
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& p) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(int i = 0;i < p.size();i++) sum += p[i];
        int diff = stoneGameIIUtil(0, 1, p);
        return (sum + diff) / 2;
    }
};