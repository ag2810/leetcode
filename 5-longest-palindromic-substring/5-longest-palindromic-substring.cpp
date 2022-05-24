class Solution {
private:
    int low;
    int maxLen;
public:
    void longestPalindromeUtil(string s, int i, int j) {
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;j++;
        }
        
        if(j - i - 1 > maxLen) {
            maxLen = j - i - 1;
            low = i + 1;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.length() < 2) return s;

        for(int k = 0;k < s.length();k++) {
            longestPalindromeUtil(s, k, k);
            longestPalindromeUtil(s, k, k + 1);
        }
        cout<<low<<maxLen;
        return s.substr(low, maxLen);
    }
};