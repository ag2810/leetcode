class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        int len = s.length();
        
        string store[numRows];
        
        bool down = true;
        int row = 0;
        
        for(int i = 0;i < len;i++)
        {
            store[row].push_back(s[i]);
            
            if(row == 0)
                down = true;
            
            else if(row == numRows - 1)
                down = false;
            
            down ? row++ : row--;
        }
        
        string ans="";
        for(int i = 0;i < numRows;i++)
        {
            ans += store[i];
        }
        
        return ans;
    }
};