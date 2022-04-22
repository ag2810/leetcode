class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0, ones = 0, twos = 0;
        
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] == 0) zeroes++;
            else if(nums[i] == 1) ones++;
            else twos++;
        }
    
        nums.clear();
        
        while(zeroes > 0) {
            nums.push_back(0);
            zeroes--;
        }
        
        while(ones > 0) {
            nums.push_back(1);
            ones--;
        }
        
        while(twos > 0) {
            nums.push_back(2);
            twos--;
        }
    }
};