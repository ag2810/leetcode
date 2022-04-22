class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 0;i < n;i++) {
            int start = n - i;
            int end = i + 1;
            int total = start * end;
            int odd = total / 2;
            if(total % 2 == 1) odd += 1;
            res += arr[i] * odd;
        }
        return res;
    }
};