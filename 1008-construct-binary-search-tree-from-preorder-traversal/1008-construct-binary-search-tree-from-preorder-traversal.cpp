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
    TreeNode* bstFromPreorderUtil(int& i, int bound, vector<int>& nums) {
        if(i == nums.size() || nums[i] > bound) return NULL;
        
        TreeNode* root = new TreeNode(nums[i]);
        i++;
        root -> left = bstFromPreorderUtil(i, root -> val, nums);
        root -> right = bstFromPreorderUtil(i, bound, nums);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorderUtil(i, INT_MAX, preorder);
    }
    
};