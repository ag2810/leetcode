class Solution {
public:
    vector<int> mostCompetitiveUtil(vector<int>& nums, int k) {
        stack<int> st;
        for(int i = 0;i < nums.size();i++) {
            while(!st.empty() && st.top() > nums[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        
        vector<int> ans;
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        return mostCompetitiveUtil(nums, nums.size() - k);
    }
};