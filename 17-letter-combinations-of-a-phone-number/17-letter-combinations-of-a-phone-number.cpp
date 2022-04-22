class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> store = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", 
        };
        
        vector<string> result;
        
        
        if(digits.length() == 0)
            return result;
        
        result.push_back("");
        vector<string> temp;
        
        for(int i = 0;i < digits.size();i++)
        {
            string letters = store[digits[i] - '0'];
            
            for(int j = 0;j < letters.length();j++)
            {
                for(int k = 0;k < result.size();k++)
                {
                    temp.push_back(result[k] + letters[j]);
                }
            }
            
            result = temp;
            temp.clear();
        }
        
        return result;
    }
};