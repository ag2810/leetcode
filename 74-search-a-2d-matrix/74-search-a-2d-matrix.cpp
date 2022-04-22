class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        if(m.size() == 0 || m[0].size() == 0) return false;
        
        int r = m.size();
        int c = m[0].size();
        
        int lo = 0;
        int hi = r * c - 1; 
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(m[mid / c][mid % c] == target) return true;
            else if(m[mid / c][mid % c] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return false;
    }
};