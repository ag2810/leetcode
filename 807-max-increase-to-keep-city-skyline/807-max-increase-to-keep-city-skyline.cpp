class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int> row_maxes(n);
        vector<int> col_maxes(n);
        
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                row_maxes[i] = max(row_maxes[i], grid[i][j]);
                col_maxes[i] = max(col_maxes[i], grid[j][i]);
            }
        }
        
        for(int i =0;i < n;i++) cout<<row_maxes[i]<<" ";
        cout<<endl;
        for(int i =0;i < n;i++) cout<<col_maxes[i]<<" ";
        
        int sum = 0;
        
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                sum += min(row_maxes[i], col_maxes[j]) - grid[i][j];   
            }
        }
        
        return sum;
    }
};