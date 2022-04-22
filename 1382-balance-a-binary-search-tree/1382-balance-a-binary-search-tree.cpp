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
private: 
    vector<TreeNode*> inOrderTrav;
public:
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        
        inOrder(root -> left);
        inOrderTrav.push_back(root);
        inOrder(root -> right);
    }
    
    TreeNode* balanceBSTUtil(int start, int end) {
        if(start > end) 
            return NULL;
        
        int mid = (start + end) / 2;

        TreeNode* root = inOrderTrav[mid];

        root -> left = balanceBSTUtil(start, mid - 1);
        root -> right = balanceBSTUtil(mid + 1, end);

        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return balanceBSTUtil(0, inOrderTrav.size() - 1);
    }
};