class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams = 0;
        
        for(int i = 0;i < rating.size();i++) {
            int leftSmall = 0, leftLarge = 0, rightSmall = 0, rightLarge = 0;
            
            for(int j = 0;j < i;j++) {
                if(rating[j] < rating[i]) leftSmall++;
                else leftLarge++;
            }
            
            for(int j = i + 1;j < rating.size();j++) {
                if(rating[j] < rating[i]) rightSmall++;
                else rightLarge++;
            }
            
            teams += leftSmall * rightLarge + rightSmall * leftLarge;
        }
        return teams;
    }
};