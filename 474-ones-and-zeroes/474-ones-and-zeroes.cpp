class Solution {
public:
    vector<int> countHelper(string str) {
        vector<int> count(2, 0);
        for(int i = 0;i < str.length();i++) count[str[i] - '0']++;
        return count;
    }
    
    int findMaxFormUtil(vector<string>& strs, int zeroes, int ones, int index, vector<vector<vector<int>>>& dp) {
        if(index == strs.size()) return 0;
        
        if(dp[zeroes][ones][index] != -1) return dp[zeroes][ones][index];
        
        vector<int> count = countHelper(strs[index]);
        
        int consider = 0;
        
        if(zeroes >= count[0] && ones >= count[1]) 
            consider = 1 + findMaxFormUtil(strs, zeroes - count[0], ones - count[1], index + 1, dp);
        
        int notConsider = findMaxFormUtil(strs, zeroes, ones, index + 1, dp);
        
        return dp[zeroes][ones][index] = max(consider, notConsider);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size(), -1)));
        return findMaxFormUtil(strs, m, n, 0, dp);
    }
};