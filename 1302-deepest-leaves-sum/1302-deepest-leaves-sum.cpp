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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0;i < size;i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            count++;
        }

        queue<TreeNode*> p;
        p.push(root);
        int val = 0;
        
        while(val < count - 1) {
            int size = p.size();
            for(int i = 0;i < size;i++) {
                TreeNode* front = p.front();
                p.pop();
                if(front -> left) p.push(front -> left);
                if(front -> right) p.push(front -> right);
            }
            val++;
        }
        
        int sum = 0;

        while(!p.empty()) {
            sum += p.front() -> val;
            p.pop();
        }
        
        return sum;
    }
};