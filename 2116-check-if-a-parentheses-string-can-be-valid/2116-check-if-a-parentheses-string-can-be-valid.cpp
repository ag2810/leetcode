class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length() & 1) return false;
        
        int flips = 0, open = 0, close = 0;
        
        for(int i = 0;i < s.length();i++) {
            if(locked[i] == '0') flips++;
            
            else {
                if(s[i] == '(') open++;
                else close++;
            }
            
            if(flips + open < close) return false;
        }

        flips = 0, open = 0, close = 0;
        
        for(int i = s.length() - 1;i >= 0;i--) {
            if(locked[i] == '0') flips++;
            
            else {
                if(s[i] == ')') close++;
                else open++;
            }
            
            if(flips + close < open) return false;
        }
        
        return true;
    }
};