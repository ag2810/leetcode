class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        stack<string> st;
        
        for(int i = 0;i < s.length();i++) {
            if(s[i] == ' ') continue;
            while(i < s.length() && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            st.push(temp);
            temp = "";
        }
        
        string ans = "";
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
            ans += " ";
        }
        return ans.substr(0, ans.length() - 1);
    }
};