/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()) {
            Node* n = st.top();
            st.pop();
            ans.insert(ans.begin(), 1, n -> val);
            for(int i = 0;i < n -> children.size();i++) st.push(n -> children[i]);
        }
        
        return ans;
    }
};