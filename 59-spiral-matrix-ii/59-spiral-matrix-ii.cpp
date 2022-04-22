class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        int dir = 0;
        int k = 1;
        vector<vector<int>> m( n , vector<int> (n, 0));
        
        while(top <= down && left <= right) {
            if(dir == 0) {
                for(int i = left;i <= right;i++) {
                    m[top][i] = k++;
                }
                top++;
            }
            
            else if(dir == 1) {
                for(int i = top;i <= down;i++) {
                    m[i][right] = k++;
               }
                right--;
            }
            
            else if(dir == 2) {
                for(int i = right;i >= left;i--) {
                    m[down][i] = k++;
                }
                down--;
            }
            
            else if(dir == 3) {
                for(int i = down;i >= top;i--) {
                    m[i][left] = k++;
                }
                left++;
            }
            
            dir = (dir + 1) % 4;
        }
        
        return m;
    }
};