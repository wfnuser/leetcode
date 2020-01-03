/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        queue<int> l;
        if (root == NULL) return NULL;
        q.push(root);
        l.push(0);

        Node* pre = new Node(0);
        int preLevel = -1;

        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            int level = l.front();
            l.pop();

            if (level != preLevel) {
                pre->next = NULL;
            } else {
                pre->next = node;
            }

            if (node->left) {q.push(node->left);l.push(level+1);}
            if (node->right) {q.push(node->right);l.push(level+1);}

            pre = node;
            preLevel = level;
        }
        pre->next = NULL;

        return root;
    }
};