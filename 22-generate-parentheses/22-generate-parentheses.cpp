class Solution {
public:
    void generateParenthesisUtil(string current, int open, int close, int n,                   vector<string>& res) {
        if(current.length() == 2 * n) {
            res.push_back(current);
            return;
        }
        
        if(open < n) generateParenthesisUtil(current + "(", open + 1, close, n , res);
        if(close < open) generateParenthesisUtil(current + ")", open, close + 1, n , res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisUtil("", 0, 0, n, res);
        return res;
    }
};