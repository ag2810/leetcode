class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalin(int i, int j, string s) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++,j--;
        }    
        return true;
    }
    
    void partitionUtil(int index, string s, vector<string> temp) {
        if(index >= s.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i = index;i < s.size();i++) {
            if(isPalin(index, i, s)) {
                temp.push_back(s.substr(index, i - index + 1));
                partitionUtil(i + 1, s, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        partitionUtil(0, s, temp);
        return res;
    }
};