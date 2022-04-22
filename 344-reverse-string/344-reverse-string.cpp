class Solution {
public:
    void reverseStringUtil(vector<char>& s, int l, int r) {
        if(l <= r) {
            swap(s[l], s[r]);
            reverseStringUtil(s, l + 1, r - 1);
        }
    }
    
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        
        reverseStringUtil(s, l, r);
    }
};