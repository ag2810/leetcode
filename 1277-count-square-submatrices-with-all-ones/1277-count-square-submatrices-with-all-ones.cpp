class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int p = m.size();
        int q = m[0].size();
        
        vector<vector<int>> dp(p, vector<int>(q, 0));
        
        for(int i = 0;i < p;i++) {
            for(int j = 0;j < q;j++) {
                if(m[i][j] == 0) continue;
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
        
        int sum = 0;
        
        for(int i = 0;i < p;i++) {
            for(int j = 0;j < q;j++) {
                cout<<" "<<dp[i][j];
            }
            cout<<endl;
        }
        
        for(int i = 0;i < p;i++) {
            for(int j = 0;j < q;j++) {
                sum += dp[i][j];
            }
        }
        
        return sum;
    }
};