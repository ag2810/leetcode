class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator ptr;
        
        for(ptr = nums.begin();ptr != nums.end();ptr++)
        {
            if(*ptr == val)
            {
                nums.erase(ptr);
                ptr--;
            }
        }
        
        return nums.size();
    }
};