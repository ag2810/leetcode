class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0;i < m;i++) {
            for(int j = n - 2;j >= 0;j--) {
                if(mat[i][j] == 1) mat[i][j] = 1 + mat[i][j + 1];
            }
        }
        
        int sum = 0;
            
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                sum += mat[i][j];
                
                int minWidth = mat[i][j];
                for(int d = i + 1;d < m;d++) {
                    if(mat[d][j] == 0) break;
                    minWidth = min(minWidth, mat[d][j]);
                    
                    sum += minWidth;
                }
            }
        }
        
        return sum;
    }
};