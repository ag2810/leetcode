/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMax(int i, int j, vector<int>& nums) {
        int ans;
        int maximum = INT_MIN;
        
        for(int k = i;k <= j;k++) {
            if(maximum < nums[k]) {
                maximum = max(maximum, nums[k]);
                ans = k;
            }
        } 
        
        return ans;
    }
    
    TreeNode* solve(int i, int j, vector<int>& nums) {
        if(i < 0 || i >= nums.size() || i > j || j < 0 || j >= nums.size()) return NULL;
        
        int index = findMax(i, j, nums);
        
        TreeNode* root = new TreeNode(nums[index]);
        
        root -> left = solve(i, index - 1, nums);
        root -> right = solve(index + 1, j, nums);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }
};