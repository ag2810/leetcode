class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        
        int start = -n / 2;
        int end = n / 2;
        
        if(n % 2 == 0) {
            for(int i = start;i <= end;i++) {
                if(i == 0) continue;
                ans.push_back(i);
            }
        }
        
        else {
            for(int i = start;i <= end;i++) ans.push_back(i);
        }
            
        return ans;
    }
};