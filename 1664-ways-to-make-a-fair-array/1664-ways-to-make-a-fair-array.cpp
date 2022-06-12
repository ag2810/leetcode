class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> even(n, 0), odd(n, 0);
        
        int evenSum = 0, oddSum = 0;
        
        for(int i = 0;i < n;i++) {
            if(i % 2 == 0) evenSum += nums[i];
            else oddSum += nums[i];
            
            odd[i] = oddSum;
            even[i] = evenSum;
        }
        
        int count = 0;
        
        for(int i = 0;i < n;i++) {
            if(i == 0) {
                int newEvenSum = odd[n - 1] - odd[0];
                int newOddSum = even[n - 1] - even[0];
                
                if(newEvenSum == newOddSum) count++;
                
                continue;
            }
            
            int newEvenSum = even[i - 1] + (odd[n - 1] - odd[i]);
            int newOddSum = odd[i - 1] + (even[n - 1] - even[i]);
            
            if(newEvenSum == newOddSum) count++;
        }
        
        return count;
    }
};