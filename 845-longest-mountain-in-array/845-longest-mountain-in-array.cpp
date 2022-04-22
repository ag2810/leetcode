class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i;
        int n = arr.size();
        int ans = 0;
        
        for(int i = 1;i <= n - 2;) {
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int count = 0;
                int j = i;
                while(j > 0 && arr[j] > arr[j - 1]) {
                    count++;
                    j--;
                }
                count += 1;
                while(i < n - 1 && arr[i] > arr[i + 1]) {
                    count++;
                    i++;
                }
                ans = max(ans, count);
            }
            else {
                i++;
            }
        }
        
        return ans;
    }
};