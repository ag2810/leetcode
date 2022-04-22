class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        
        if(x < 0) sign = -1;
        x = abs(x);
        long long int rev = 0;
        while(x > 0) {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        rev = rev * sign;
        if(rev > INT_MAX || rev < INT_MIN) return 0;
        return (int)rev;
    }
};