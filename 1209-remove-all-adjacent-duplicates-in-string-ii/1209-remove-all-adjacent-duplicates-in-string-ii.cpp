class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> st;
        for(int i = 0;i < s.length();i++) {
            if(st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            }
            else {
                auto top = st.top();
                st.pop();
                st.push({s[i], top.second + 1});
            }
            if(st.top().second == k) st.pop();
        }
        
        string ans = "";
        
        while(!st.empty()) {
            auto top = st.top();
            while(top.second > 0) {
                ans += top.first;
                top.second--;
            }
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};