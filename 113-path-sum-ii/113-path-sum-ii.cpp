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
    vector<vector<int>> res;
    
    void pathSumUtil(int targetSum, vector<int>& temp, TreeNode* root) {
        if(root == NULL) return;
        // if(targetSum - root -> val < 0) return;
        
        
        if(root -> val - targetSum == 0 && root -> left == NULL && root -> right == NULL) {
            temp.push_back(root -> val);
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(root -> val);
        
        pathSumUtil(targetSum - root -> val, temp, root -> left);
        
        pathSumUtil(targetSum - root -> val, temp, root -> right);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        pathSumUtil(targetSum, temp, root);
        return res;
    }
};