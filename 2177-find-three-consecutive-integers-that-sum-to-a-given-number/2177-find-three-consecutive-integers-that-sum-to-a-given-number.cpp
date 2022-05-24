class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long int mid = num / 3;
        vector<long long> ans;
        if(3 * mid != num) return ans;
        ans = {mid - 1, mid, mid + 1};
        return ans;
    }
};