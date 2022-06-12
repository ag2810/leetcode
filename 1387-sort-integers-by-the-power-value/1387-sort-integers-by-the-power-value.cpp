class Solution {
public:
    static bool sortBySecond(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.second != b.second) return (a.second < b.second);
        else return (a.first < b.first);
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        unordered_map<int, int> mp;
        
        for(int i = lo;i <= hi;i++) {
            int val = i;
            int count = 0;
            
            while(val > 1) {
                if(mp[val]) {
                    count += mp[val];
                    break;
                }
                if(val % 2 == 0) val = val / 2;
                else val = 3 * val + 1;
                
                count++;
            }
            mp[i] = count;
            v.push_back(make_pair(i, count));
        }
        
        sort(v.begin(), v.end(), sortBySecond);
        
        return v[k - 1].first;
    }
};