class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        
        for(int i = 0;i < s.length();i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                int top = st.top();
                st.pop();
                reverse(s.begin() + top + 1, s.begin() + i);
            }
        }
        
        string res = "";
        
        for(auto ch : s) {
            if(ch != '(' && ch != ')') res += ch;
        }
        
        return res;
    }
};