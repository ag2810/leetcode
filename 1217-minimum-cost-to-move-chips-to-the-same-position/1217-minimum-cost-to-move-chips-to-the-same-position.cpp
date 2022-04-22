class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for(auto &e : position) (e % 2 == 0) ? even++ : odd++;
        return min(odd, even);
    }
};