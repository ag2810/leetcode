class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        stack<char> st;
        
        for(int i = 0;i < n;i++) {
            if(s[i] == '[') st.push(s[i]);
            else {
                if(!st.empty() && st.top() == '[') st.pop();
                else st.push(s[i]);
            }
        }
        
        if(st.empty()) return 0;
        
        int ans = st.size() / 4 + (st.size() % 4 == 0 ? 0 : 1);
        
        return ans;
    }
};