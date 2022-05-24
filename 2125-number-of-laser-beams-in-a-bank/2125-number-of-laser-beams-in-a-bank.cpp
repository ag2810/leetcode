class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int curr = 0, prev = 0;
        int beams = 0;
        for(int i = 0;i < bank.size();i++) {
            curr = 0;
            for(int j = 0;j < bank[0].size();j++) if(bank[i][j] == '1') curr++;
            if(curr) {
                beams += curr * prev;
                prev = curr;
            }
        }
        return beams;
    }
};