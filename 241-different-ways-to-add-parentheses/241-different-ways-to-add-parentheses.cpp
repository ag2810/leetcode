class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int len = expression.length();
        vector<int> res;
        
        for(int i = 0;i < len;i++)
        {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                for(int j = 0;j < left.size();j++) {
                    for(int k = 0;k < right.size();k++) {
                        if(expression[i] == '+') res.push_back(left[j] + right[k]);
                        else if(expression[i] == '-') res.push_back(left[j] - right[k]);
                        else if(expression[i] == '*') res.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        
        if(res.size() == 0)
            res.push_back(atoi(expression.c_str()));
        
        return res;
    }
};