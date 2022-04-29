class Solution {
public:
    int countVowelStrings(int n) {
        if(n == 1) return 5;
        if(n == 2) return 15;
        
        vector<int> prev(5);
        vector<int> curr(5);
        
        for(int i = 0;i < 5;i++) prev[i] = 1;
        
        for(int i = 2;i <= n;i++) {
            curr[4] = 1;
            
            for(int j = 3;j >= 0;j--) {
                
                curr[j] = prev[j] + curr[j + 1];
            }
            
            prev = curr;
        }
        
        int sum = 0;
        for(int i = 0;i < 5;i++) sum += curr[i]; 
        
        return sum;
    }
};