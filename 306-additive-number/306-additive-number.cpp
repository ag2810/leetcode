class Solution {
public:
    bool isAdditiveNumberUtil(long long n1, long long n2, string s, bool found) {
        if(s.length() == 0 && found) return true;
        
        string n3 = to_string(n1 + n2);
        int index = min(n3.length(), s.length());
        
        if(s.substr(0, index) == n3 && isAdditiveNumberUtil(n2, stoll(n3), s.substr(index), true)) return true;
        
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        int n = num.length();
        
        for(int i = 1;i < n - 1;i++) {
            long long n1 = stoll(num.substr(0, i));
            if(to_string(n1) != num.substr(0, i)) break;
            
            for(int j = i + 1;j < n;j++) {
                long long n2 = stoll(num.substr(i, j - i));
                if(to_string(n2) != num.substr(i, j - i)) break;
                
                if(isAdditiveNumberUtil(n1, n2, num.substr(j), false)) return true;
            }
        }
        
        return false;
    }
};