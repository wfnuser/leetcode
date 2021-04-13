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
        traverse(root, ans);
        return ans;        
    }

    void traverse(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        for (auto node: root->children) {
            traverse(node, ans);
        }

        ans.push_back(root->val);
    }
};