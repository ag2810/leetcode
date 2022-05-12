class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> v(rows, vector<int>(cols, 0));
        
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                if(i == 0 || j == 0) v[i][j] = matrix[i][j] - '0';
                
                else if(matrix[i][j] == '0') continue;
                
                else {
                    v[i][j] = 1 + min(v[i - 1][j - 1], min(v[i - 1][j], v[i][j - 1]));
                }
                
                ans = max(ans, v[i][j]);
            }
        }
    
        return ans * ans;
    }
};