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
    TreeNode* lastLeftNode(TreeNode* root) {
        if(root -> left == NULL) return root;
        return lastLeftNode(root -> left);
    }
    
    TreeNode* deleteNodeUtil(TreeNode* root) {
        if(root -> left == NULL) return root -> right;
        if(root -> right == NULL) return root -> left;
        
        TreeNode* lastLeft = lastLeftNode(root -> right);
        
        lastLeft -> left = root -> left;
        
        return root -> right;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) return deleteNodeUtil(root);
        
        TreeNode* curr = root;
        
        while(curr) {
            if(curr -> val > key) {
                if(curr -> left != NULL && curr -> left -> val == key) 
                {
                    curr -> left = deleteNodeUtil(curr -> left);
                    break;
                }
                
                else curr = curr -> left;
            }
            else {
                if(curr -> right != NULL && curr -> right -> val == key) 
                {
                    curr -> right = deleteNodeUtil(curr -> right);
                    break;
                }
                
                else curr = curr -> right;
            }
        }
        
        return root;
    }
};