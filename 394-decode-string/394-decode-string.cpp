class Solution {
public:
    string decodeString(string s) {
        stack<int> is;
        stack<string> ss;
        string res = "";
        int i = 0;
        
        while(i < s.length()) {
            if(isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i])) {
                    num = (num * 10) + (s[i] - '0');
                    i++;
                }
                is.push(num);
            }
            else if(s[i] == '[') {
                ss.push(res);
                res = "";
                i++;
            }
            else if(s[i] == ']') {
                int intTop = is.top();
                string stringTop = ss.top();
                is.pop();
                ss.pop();
                string temp = "";
                for(int j = 1;j <= intTop;j++)  stringTop += res;
                res = stringTop;
                i++;
            }
            else {
                res += s[i]; 
                i++;
            }
        }
        
        return res;
    }
};