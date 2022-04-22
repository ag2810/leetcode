class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;
        
        string str = to_string(x);
        
        int i = 0;
        
        while(i < str.length()/2)
        {
            if(str[i] != str[str.length() - i - 1])
            {
                return false;
            }
            i++;
            continue;
        }
        
        return true;
    }
};