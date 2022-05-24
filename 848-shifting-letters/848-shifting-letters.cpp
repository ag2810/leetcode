class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0;
        for(int i = shifts.size()- 1;i >= 0;i--) shifts[i] = shifts[i] % 26;
        for(int i = shifts.size()- 2;i >= 0;i--) shifts[i] += shifts[i + 1];
        for(int i = shifts.size()- 1;i >= 0;i--) shifts[i] = shifts[i] % 26;
        
        string ans = "";
        
        for(int i = 0;i < s.size();i++) {
            ans += ((s[i]  - 'a') + shifts[i]) % 26 + 'a';
        }
        return ans;
    }
};