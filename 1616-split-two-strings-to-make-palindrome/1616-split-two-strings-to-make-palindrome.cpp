class Solution {
public:
    bool isPal(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        if(isPal(a, 0, a.length() - 1)) return true;
        if(isPal(b, 0, b.length() - 1)) return true;
        
        int alen = a.length(), blen = b.length();
        
        int i = 0, j = blen - 1;
        
        while(i < alen && j >= 0) {
            if(a[i] == b[j]) i++, j--;
            else break;
        }
        
        if(isPal(a, i, j) || isPal(b, i, j)) return true;
        
        i = 0, j = alen - 1;
        
        while(i < blen && j >= 0) {
            if(b[i] == a[j]) i++, j--;
            else break;
        }
        
        if(isPal(a, i, j) || isPal(b, i, j)) return true;
        
        return false;
    }
};