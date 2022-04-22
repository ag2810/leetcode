class Solution {
public:
    int twoEggDropUtil(int eggs, int floor) {
        if(floor == 0 || floor == 1) {
            return floor;
        }
        
        if(eggs == 1)
        {
            return floor;
        }
        
        int res = INT_MAX, maxi; 
        
        for(int i = 1;i <= floor;i++) {
            int b = twoEggDropUtil(eggs - 1, i - 1);
            int nb = twoEggDropUtil(eggs, floor - i);
            
            maxi = max(b, nb);
            res = min(res, maxi);
        }
        
        return res + 1;
    }
    
    int twoEggDropUtilDP(int eggs, int floor) {
        int dp[eggs + 1][floor + 1];
        for(int i = 1;i <= eggs;i++) {
            for(int j = 1;j <= floor;j++) {
                if(i == 1) dp[i][j] = j;
                else if(j == 1) dp[i][j] = 1;
                else {
                    int k, l, maxi, mini = INT_MAX;
                    
                    for(k = 0, l = j - 1;k < j,l >= 0;k++,l--) {
                        maxi = max(dp[i][l], dp[i - 1][k]);
                        mini = min(mini, maxi);
                    }
                    
                    dp[i][j] = mini + 1;
                }
            }
        }
        return dp[eggs][floor];
    }
    
    int twoEggDrop(int n) {
        return twoEggDropUtilDP(2, n);
    }
};