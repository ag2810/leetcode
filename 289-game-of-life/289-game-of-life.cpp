class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>> dirs = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
        
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                int c = 0;
                for(auto dir : dirs) {
                    int p = i + dir[0];
                    int q = j + dir[1];
                    
                    if(p >= 0 && p < rows && q >= 0 && q < cols && (board[p][q] == 1 || board[p][q] == 2)) c++;
                }
                
                if(board[i][j] == 1) {
                    if(c < 2 || c > 3) board[i][j] = 2;
                }
                
                else {
                    if(c == 3) board[i][j] = 3;
                }
            }
        }
        
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                board[i][j] %= 2;
            }
        }
    }
};