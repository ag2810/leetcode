class Solution {
public:
    string simplifyPath(string path) {
        string token, res="";
        stack<string> st;
        stringstream ss(path);
        
        while(getline(ss, token, '/')) {
            if(token == "." || token == "") continue;
            if(token != "..") st.push(token);
            else if(!st.empty()) st.pop();
        }

        if(st.empty()) return "/";
        
        while(!st.empty()) {
            res = '/' + st.top() + res;
            st.pop();
        }

        return res;
    }
   
};