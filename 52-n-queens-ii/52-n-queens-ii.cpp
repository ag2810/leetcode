class Solution {
public:
    vector<vector<string>> ans;
    void totalNQueensUtil(int col, vector<int>& leftRow, vector<int>& leftDia, vector<int>& rightDia, vector<string> board) {
        if(col == board[0].size()) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0;row < board.size();row++) {
            if(!leftRow[row] && !leftDia[board.size() - 1 + row - col] && !rightDia[row + col]) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                leftDia[board.size() - 1 + row - col] = 1, rightDia[row + col] = 1;
                
                totalNQueensUtil(col + 1, leftRow, leftDia, rightDia, board);
                
                board[row][col] = '.';
                leftRow[row] = 0;
                leftDia[board.size() - 1 + row - col] = 0, rightDia[row + col] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        string row(n, '.');
        vector<string> board(n);
        for(int i = 0;i < n;i++) board[i] = row;
        vector<int> leftRow(n, 0), leftDia(2 * n + 1, 0), rightDia(2 * n + 1, 0);
        totalNQueensUtil(0, leftRow, leftDia, rightDia, board);
        return ans.size();
    }
};