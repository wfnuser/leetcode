/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:

    vector<Node*> V;

    void dfs(Node* root) {
        if (root == NULL) return;
        if (root->left) dfs(root->left);
        V.push_back(root);
        if (root->right) dfs(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        dfs(root);

        if (V.size() == 1) {
            Node* ans = V[0];
            ans->right = ans;
            ans->left = ans;
            return ans;
        }

        for (int i = 0; i < V.size(); i++) {
            V[i]->left = V[(i-1 + V.size())%V.size()];
            V[(i - 1 + V.size())%V.size()]->right = V[i];
        }

        return V[0];
    }
};