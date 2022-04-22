class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)     {
        int count = 0;
        vector<int> res;
        
        for(auto query : queries) {
            count = 0;
            for(auto point : points) {
                int dx = abs(query[0] - point[0]);
                int dy = abs(query[1] - point[1]);
                int rad = query[2];

                if(dx * dx + dy * dy <= rad * rad) count++;
            }
            res.push_back(count);
        }
        
        return res;
    }
};