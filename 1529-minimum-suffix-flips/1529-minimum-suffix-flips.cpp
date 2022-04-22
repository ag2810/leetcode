class Solution {
public:
    int minFlips(string s) {
        int state = 0;
        int flips = 0;
        for(int i = 0;i < s.length();++i) {
            if(state != s[i] - '0') {
                state = s[i] - '0';
                flips += 1;
            }
        }
        return flips;
    }
};