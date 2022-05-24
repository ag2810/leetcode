class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sq;
        stack<char> tq;
        
        for(auto ch : s) {
            if(ch != '#') sq.push(ch);
            else {
                if(!sq.empty()) sq.pop();
            }
        }
        
        for(auto ch : t) {
            if(ch != '#') tq.push(ch);
            else {
                if(!tq.empty()) tq.pop();
            }
        }
        
        if(sq.size() != tq.size()) return false;
        
        while(!sq.empty() && !tq.empty()) {
            if(sq.top() == tq.top()) {
                sq.pop();
                tq.pop();
            }
            else return false;
        }
        
        return true;
    }
};