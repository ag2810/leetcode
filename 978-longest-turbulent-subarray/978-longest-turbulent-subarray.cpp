class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        int ans = 1;
        vector<int> inc(size, 1), dec(size, 1);
        
        for(int i = 1;i < size;i++) {
            if(arr[i] > arr[i - 1]) inc[i] = 1 + dec[i - 1]; 
            else if(arr[i] < arr[i - 1]) dec[i] = 1 + inc[i - 1];
            int curr = max(inc[i], dec[i]);
            ans = max(curr, ans);
        }
        
        return ans;
    }
};