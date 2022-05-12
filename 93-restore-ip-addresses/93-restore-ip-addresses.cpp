class Solution {
public:
    void restoreIpAddressesUtil(int i, int partition, string& s, string ans, vector<string>& res) {
        if(i == s.length() || partition == 4) {
            if(i == s.length() && partition == 4) {
                cout<<"Hello";
                res.push_back(ans.substr(0, ans.length() - 1));    
            }   
            return;
        }
        
        restoreIpAddressesUtil(i + 1, partition + 1, s, ans + s.substr(i, 1) + ".", res);
        
        if(i + 2 <= s.length() && isValid(s.substr(i, 2)))
            restoreIpAddressesUtil(i + 2, partition + 1, s, ans + s.substr(i, 2) + ".", res);
        
        if(i + 3 <= s.length() && isValid(s.substr(i, 3)))
            restoreIpAddressesUtil(i + 3, partition + 1, s, ans + s.substr(i, 3) + ".", res);
    }
    
    bool isValid(string s) {
        if(s[0] == '0') return false;
        if (stoi(s) <= 255) return true;
        else return false;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restoreIpAddressesUtil(0, 0, s, "", res);
        return res;
    }
};