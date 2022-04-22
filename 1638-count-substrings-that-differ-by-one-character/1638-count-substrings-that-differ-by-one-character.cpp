class Solution {
public:
    int countSubstrings(string s, string t) {
        int slength = s.length();
        int tlength = t.length();
        int ans = 0;
        
        for(int i = 0;i < slength;i++) {
            for(int j = 0;j < tlength;j++) {
                int x = i;
                int y = j;
                int d = 0;
                while(x < slength && y < tlength) {
                    if(s[x] != t[y]) d++;
                    if(d == 1) ans++;
                    if(d > 1) break;
                    x++;
                    y++;
                }
            }
        }
        
        return ans;
    }
};