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
    vector<Node*> nodes;

    void traverse(Node* root) {
        if (root == NULL) return;
        if (root->left) traverse(root->left);
        nodes.push_back(root);
        if (root->right) traverse(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        traverse(root);
        for (int i = 1; i < nodes.size(); i++) {
            nodes[i-1]->right = nodes[i];
            nodes[i]->left = nodes[i-1];
        }
        nodes[nodes.size()-1]->right = nodes[0];
        nodes[0]->left = nodes[nodes.size()-1];

        return nodes[0];
    }
};