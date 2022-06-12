class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                nums3.push_back(nums2[j]);
                j++;
            }
            else {
                nums3.push_back(nums1[i]);
                nums3.push_back(nums2[j]);
                i++, j++;
            }
        }
        
        while(i < m) {
            nums3.push_back(nums1[i]);
            i++;
        }
        
        while(j < n) {
            nums3.push_back(nums2[j]);
            j++;
        }
        
        for(int i = 0;i < m + n;i++) cout<<nums3[i]<<" ";
        
        nums1 = nums3;
    }
};