class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int top = 0;
        int down = m.size() - 1;
        int left = 0;
        int right = m[0].size() - 1;
        int dir = 0;
        vector<int> res;
        
        while(top <= down && left <= right) {
            if(dir == 0) {
                for(int i = top;i <= right;i++) {
                    res.push_back(m[top][i]);
                }
                top++;
            }
            
            else if(dir == 1) {
                for(int i = top;i <= down;i++) {
                    res.push_back(m[i][right]);
                }
                right--;
            }
            
            else if(dir == 2) {
                for(int i = right;i >= left;i--) {
                    res.push_back(m[down][i]);
                }
                down--;
            }
            
            else if(dir == 3) {
                for(int i = down;i >= top;i--) {
                    res.push_back(m[i][left]);
                }
                left++;
            }
            
            dir = (dir + 1) % 4;
        }
        return res;
    }
};