class Solution {
public:
    void mark(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size()) return;
        
        if(visited[i][j] || board[i][j] == 'X') return;
        
        if(!visited[i][j] && board[i][j] == 'O')
        {
            board[i][j] = 'B';
            visited[i][j] = true;
        }

        mark(i - 1, j, board, visited);
        mark(i, j + 1, board, visited);
        mark(i + 1, j, board, visited);
        mark(i, j - 1, board, visited);
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        if(rows <= 2 || cols <= 2) return;
        
        vector< vector< bool > > visited( rows, vector<bool>( cols, false ) );
        
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                if(board[i][j] == 'O' && (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && !visited[i][j]) 
                    mark(i, j, board, visited);
            }
        }
        
        for(int i = 0;i < rows;i++) {
            for(int j = 0;j < cols;j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }
};