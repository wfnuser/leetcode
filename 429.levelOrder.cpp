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
    vector<vector<int>> ans;

    void dfs(Node* root, int level) {
        if (root == NULL) return;
        if (ans.size() <= level) {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);

        for (int i = 0; i < root->children.size(); i++) {
            dfs(root->children[i], level+1);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);

        return ans;
    }
};