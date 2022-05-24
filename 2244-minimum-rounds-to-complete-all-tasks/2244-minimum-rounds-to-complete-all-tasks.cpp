class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int cnt = 0;
        map<int, int> mp;
        
        for(auto i : tasks) mp[i]++;
        
        for(auto j : mp) {
            int mini = 0;
            if(j.second == 1) return -1;
            while(j.second >= 3) {
                mini++;
                j.second -= 3;
            };
            if(j.second) mini += 1;
            cnt += mini;
        }
        return cnt;
    }
};