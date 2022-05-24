class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1 || n == 2) return 1.0 / n;
        return 1.0 / 2;
    }
};