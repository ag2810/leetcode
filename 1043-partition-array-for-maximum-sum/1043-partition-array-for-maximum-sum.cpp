class Solution {
public:
    int maxSumAfterPartitioningUtil(vector<int>& arr, int k, int index, vector<int>& dp) {
        int currMax = 0, sumMax = 0;
        if(dp[index] != -1) return dp[index];
        for(int i = 1;i <= k;i++) {
            if(index - i < 0) break;
            currMax = max(currMax, arr[index - i]);
            sumMax = max(sumMax, maxSumAfterPartitioningUtil(arr, k, index - i, dp) + (currMax * i));
        }    
        return dp[index] = sumMax;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size());
        for(int i = 0;i < arr.size();i++) {
            int currMax = 0;
            for(int j = 0;j < k;j++) {
                if(i - j < 0) break;
                
                currMax = max(currMax, arr[i - j]);
                
                if(i - j - 1 < 0) dp[i] = max(dp[i], currMax * (j + 1));
                else dp[i] = max(dp[i], dp[i - j - 1] + currMax * (j + 1));
            }
        }
        return dp[arr.size() - 1];
    }
};