class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int len = s.length();
        long long int size = 0;
        string ans = "";
        
        for(int i = 0;i < len;i++) {
            if(isalpha(s[i])) size++;
            else size *= s[i] - '0';
        }
        
        for(int i = s.length() - 1;i >= 0;i--) {
            k = k % size;
            
            if(k == 0 && isalpha(s[i])) return ans + s[i];
            
            if(isdigit(s[i])) size = size / (s[i] - '0');
            else size--;
        }
        
        return "";
    }
};