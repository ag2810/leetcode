class Solution {
public:
    void letterCasePermutationUtil(int index, string s, vector<string>& res) {
        if(index == s.size()) {
            res.push_back(s);
            return;
        } 
        
        if(isalpha(s[index])) {
            char t = s[index];
            
            if(islower(s[index])) s[index] = toupper(s[index]);
            else s[index] = tolower(s[index]);
            
            letterCasePermutationUtil(index + 1, s, res);
            
            s[index] = t;
            
            letterCasePermutationUtil(index + 1, s, res);
        }
        else letterCasePermutationUtil(index + 1, s, res);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        letterCasePermutationUtil(0, s, res);
        return res;
    }
};