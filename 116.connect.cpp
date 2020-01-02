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
        if (root == NULL) return NULL;

        queue<Node*> q;
        queue<int> l;
        q.push(root);
        l.push(0);

        Node* pre = NULL;
        int preLevel = -1;

        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            int level = l.front();
            l.pop();
            
            if (pre != NULL) {
                if (preLevel == level) {
                    pre->next = node;
                }
                if (preLevel != level) {
                    pre->next = NULL;
                }
            }

            if (node->left != NULL) {
                q.push(node->left);
                l.push(level+1);
                q.push(node->right);
                l.push(level+1);
            }
            pre = node;
            preLevel = level;

            if (q.empty()) node->next = NULL;
        }

        return root;
    }
};