class Solution {
public:
    int recursion(int index, int currHeight, int currWidth, int shelfWidth, vector<vector<int>>& books, vector<vector<int>>& dp) {
        if(currWidth > shelfWidth) return INT_MAX;
        
        if(index == books.size()) return currHeight;
        
        if(dp[index][currWidth] != -1) return dp[index][currWidth];
        
        int currBookWidth = books[index][0];
        int currBookHeight = books[index][1];
        
        int keepBookInCurrentShelf = recursion(index + 1, max(currHeight, currBookHeight), currWidth + currBookWidth, shelfWidth, books, dp);
        
        int keepBookInNextShelf = currHeight + recursion(index + 1, currBookHeight, currBookWidth, shelfWidth, books, dp);
        
        return dp[index][currWidth] = min(keepBookInCurrentShelf, keepBookInNextShelf);
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth + 1, -1));
        return recursion(0, 0, 0, shelfWidth, books, dp);
    }
};