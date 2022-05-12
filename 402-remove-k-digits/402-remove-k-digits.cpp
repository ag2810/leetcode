class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i = 0;i < num.length();i++) {
            while(!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            if(!st.empty() || num[i] != '0') st.push(num[i]);
        }
        
        
        
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        
        if(st.empty()) return "0";
        
        string ans = "";
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};