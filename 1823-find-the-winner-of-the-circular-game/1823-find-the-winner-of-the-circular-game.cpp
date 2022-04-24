class Solution {
public:
    int findTheWinnerUtil(int index, int k, vector<int>& v) {
        if(v.size() == 1) return v[0];
        
        int dead = (index + k) % v.size();
        
        v.erase(v.begin() + dead);
        
        return findTheWinnerUtil(dead, k, v);
    }
    
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        
        for(int i = 0;i < n;i++) v[i] = i + 1;
        
        return findTheWinnerUtil(0, k - 1, v);
    }
};