class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        
        vector<bool> seen(26, false);
        map<int, int> mp;
        
        for(int i = 0;i < s.length();i++) mp[s[i] - 'a']++;
        
        for(int i = 0;i < s.length();i++) {
            mp[s[i] - 'a']--;
            
            if(seen[s[i] - 'a'] == true) continue;
            
            
            while(!st.empty() && s[i] < st.top() && mp[st.top() - 'a'] > 0) {
                seen[st.top() - 'a'] = false;    
                st.pop();
            }
            
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
        
        string ans = "";
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};