class Solution {
public:
    void mark_neigbouring_lands(int i, int j, int r, int c, vector<vector<char>>& grid) {
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '1') return;
        
        grid[i][j] = '2';
        
        mark_neigbouring_lands(i, j - 1, r, c, grid);
        mark_neigbouring_lands(i - 1, j, r, c, grid);
        mark_neigbouring_lands(i, j + 1, r, c, grid);
        mark_neigbouring_lands(i + 1, j, r, c, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        
        if(rows == 0) return 0;
        
        int cols = grid[0].size();
        int islands = 0;
        
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                if(grid[i][j] == '1') {
                    mark_neigbouring_lands(i, j, rows, cols, grid);
                    islands += 1;                   
                }
            }
        }
        
        return islands;
    }
};