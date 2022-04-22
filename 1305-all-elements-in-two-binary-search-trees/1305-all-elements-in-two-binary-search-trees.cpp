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
    void inOrder(TreeNode* root, vector<int>& res) {
        if(root == NULL) return;
        
        inOrder(root -> left, res);
        res.push_back(root -> val);
        inOrder(root -> right, res);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        
        inOrder(root1, ans);
        inOrder(root2, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};