class Solution {
public:
    void mark_neigbouring_lands(int i, int j, int m, int n, vector<vector<int>>& grid, int&     area) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        
        grid[i][j] = 2;
        area++;
        
        mark_neigbouring_lands(i - 1, j, m, n, grid, area);
        mark_neigbouring_lands(i, j + 1, m, n, grid, area);
        mark_neigbouring_lands(i + 1, j, m, n, grid, area);
        mark_neigbouring_lands(i, j - 1, m, n, grid, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    mark_neigbouring_lands(i, j, m, n, grid, area);
                    maxArea = max(maxArea, area);
                } 
            }
        }
        
        return maxArea;
    }
};