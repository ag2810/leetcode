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
    TreeNode* sortedArrayToBSTUtil(int lo, int hi, vector<int>& nums) {
        if(lo > hi) return NULL;
        
        int mid = (lo + hi) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root -> left = sortedArrayToBSTUtil(lo, mid - 1, nums);
        root -> right = sortedArrayToBSTUtil(mid + 1, hi, nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(0, nums.size() - 1, nums);
    }
};