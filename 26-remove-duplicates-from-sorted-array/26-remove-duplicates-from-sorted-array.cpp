class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator ptr;
        
        for(ptr = nums.begin();ptr != nums.end() - 1;ptr++)
        {
            if(*ptr == *(ptr + 1))
            {
                nums.erase(ptr + 1);
                ptr--;
            }
        }
        
        return nums.size();
    }
};