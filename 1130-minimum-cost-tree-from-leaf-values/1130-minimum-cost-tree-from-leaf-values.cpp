class Solution {
public:
    map<pair<int, int>, pair<int, int>> dp;
    
    pair<int, int> mctFromLeafValuesUtil(int start, int end, vector<int>& arr) {
        if(start == end) return {arr[start], 0};
        
        if(dp.count({start, end})) return dp[{start, end}];
        
        int maxLeaf = INT_MIN;
        int minSum = INT_MAX;
        
        for(int i = start;i < end;i++) {
            auto left = mctFromLeafValuesUtil(start, i, arr);
            auto right = mctFromLeafValuesUtil(i + 1, end, arr);
            
            maxLeaf = max(left.first, right.first);
            minSum = min(minSum, left.second + right.second + (left.first * right.first));
        }

        return dp[{start, end}] = {maxLeaf, minSum};
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        return mctFromLeafValuesUtil(0, arr.size() - 1, arr).second;
    }
};