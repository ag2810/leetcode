class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        int len1 = num1.length();
        int len2 = num2.length();
        
        vector<int> ans(len1 + len2, 0);
        
        int pf = 0;
        
        int i = len2 - 1;
        
        while(i >= 0)
        {
            int i_val = num2[i] - '0';
            int j = len1 - 1;
            int carry;
            int k = ans.size() - 1 - pf;
            
            while(j >= 0 || carry != 0)
            {
                int j_val = j >= 0 ? num1[j] - '0' : 0;
                
                int product = i_val * j_val + ans[k] + carry;
                
                ans[k] = product % 10;
                
                carry = product / 10;
                
                j--;
                k--;
            }
            pf++;
            i--;
        }
        
        bool zeroFlag = false;
        string res = "";
        
        for(int i = 0;i < ans.size();i++) {
            if(ans[i] == 0 && zeroFlag == false)
            {
                continue;
            }
            else
            {
                zeroFlag = true;
                res += to_string(ans[i]);
            }
        }
        
        return res;
    }
};