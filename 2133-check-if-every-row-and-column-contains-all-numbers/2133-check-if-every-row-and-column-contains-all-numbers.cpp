class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i < n;i++) {
            set<int> st_row, st_col;
            for(int j = 0;j < n;j++) {
                st_row.insert(matrix[i][j]);
                st_col.insert(matrix[j][i]);
            }    
            
            if(st_row.size() != n || st_col.size() != n) return false;
        }
        return true;
    }
};