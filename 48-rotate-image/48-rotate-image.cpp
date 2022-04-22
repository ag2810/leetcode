class Solution {
public:
    void transpose(vector<vector<int>>& m) {
        for(int i = 0;i < m.size();i++) {
            for(int j = i + 1;j < m[0].size();j++) {
                swap(m[i][j], m[j][i]);
            }
        }
    }
    
    void reverse(vector<int>& row) {
        for(int i = 0;i < row.size() / 2;i++) {
            swap(row[i], row[row.size() - i - 1]);
        }    
    }
    
    void rotate(vector<vector<int>>& m) {
        transpose(m);
        for(int i = 0;i < m.size();i++) {
            reverse(m[i]);
        }
    }
};