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
    int count;
    vector<int> averageOfSubtreeUtil(TreeNode* root) {
        if(root == NULL) {
            vector<int> temp = {0, 0};
            return temp;
        }
        
        vector<int> left = averageOfSubtreeUtil(root -> left);
        vector<int> right = averageOfSubtreeUtil(root -> right);
        
        int totalSum = left[0] + right[0] + root -> val;
        int totalNodes = left[1] + right[1] + 1;
        
        if(totalSum / totalNodes == root -> val) count++;
        
        vector<int> temp = {totalSum, totalNodes};
        return temp;
    }
    
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        vector<int> value = averageOfSubtreeUtil(root);
        return count;
    }
};