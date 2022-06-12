class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> open;
        stack<char> close;
        
        for(auto ch : s) {
            if(ch == '(') open.push(ch);
            else {
                if(open.empty()) close.push(ch);
                else open.pop();
            }
        }
        
        return (open.size() + close.size());
    }
};