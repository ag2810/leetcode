class Solution {
public:
    void count(vector<int> v, set<pair<int, int>>& s) {
        int x = v[0], y = v[1], r = v[2];
        
        for(int i = x - r;i <= x + r;i++) {
            for(int j = y - r;j <= y + r;j++) {
                if(((x - i) * (x - i) + (y - j) * (y - j)) <= r * r) s.insert({i, j});
            }    
        }
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> s;
        for(auto &c : circles) count(c, s);
        return s.size();
    }
};