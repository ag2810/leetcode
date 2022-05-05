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
    int ans;
public:
    void kthSmallestUtil(TreeNode* root, int k, int& index) {
        if(root == NULL) return;
        kthSmallestUtil(root -> left, k, index);
        if(index == k) {
            index++;
            ans = root -> val;
            return;
        }
        else index++;
        kthSmallestUtil(root -> right, k, index);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int index = 1;
        kthSmallestUtil(root, k, index);
        return ans;
    }
};