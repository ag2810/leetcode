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
    int maxLevelSumUtil(TreeNode* root) {
        int level = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int maxSum = INT_MIN;
        int minLevel = INT_MAX;
        
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            for(int i = 0;i < size;i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left != NULL) q.push(curr -> left);
                if(curr -> right != NULL) q.push(curr -> right);
                sum += curr -> val;
            }
            
            if(sum > maxSum) {
                maxSum = max(sum, maxSum);
                minLevel = level;
            }
            else if(sum == maxSum) {
                minLevel = min(level, minLevel);        
            }
            
            level++;
        }
        
        return minLevel;
        
    }
    int maxLevelSum(TreeNode* root) {
        return maxLevelSumUtil(root);
    }
};