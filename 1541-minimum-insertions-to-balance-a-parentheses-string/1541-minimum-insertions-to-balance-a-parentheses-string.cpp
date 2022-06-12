class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0, count = 0;
        
        for(int i = 0;i < n;i++) {
            if(s[i] == '(') count++;
            
            else {
                if(i + 1 < n && s[i + 1] == ')') {
                    if(count > 0) count--;
                    else ans++;
                    
                    i++;
                }
                else {
                    if(count > 0) count--, ans++;
                    else ans += 2;
                }
            }
        }
        
        return ans + (2 * count);
    }
};