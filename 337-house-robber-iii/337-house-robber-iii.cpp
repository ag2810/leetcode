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
    unordered_map<TreeNode*, int> mp;
    int robUtil(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(mp.find(root) != mp.end()) return mp[root];
        
        int choose = root -> val;
        
        if(root -> left) {
            choose += robUtil(root -> left -> left);
            choose += robUtil(root -> left -> right);
        }
        
        if(root -> right) {
            choose += robUtil(root -> right -> left);
            choose += robUtil(root -> right -> right);
        }
    
        int notChoose = robUtil(root -> left) + robUtil(root -> right);
        
        return mp[root] = max(choose, notChoose);
    }
    
    int rob(TreeNode* root) {
        return robUtil(root);
    }
};