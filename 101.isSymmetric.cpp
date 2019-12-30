/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left == NULL && right == NULL) return true;
        if (left == NULL && right != NULL) return false;
        if (left != NULL && right == NULL) return false;
        if (left->val != right->val) return false;

        queue<TreeNode*> ql;
        queue<TreeNode*> qr;        
        ql.push(left);
        qr.push(right);

        while(!ql.empty()) {
            left = ql.front();
            right = qr.front();
            ql.pop();
            qr.pop();
            if (left == NULL && right == NULL) continue;
            if (left == NULL && right != NULL) return false;
            if (left != NULL && right == NULL) return false;
            if (left->val != right->val) return false;

            if (left->left != NULL) {
                ql.push(left->left);
                qr.push(right->right);
            } else {
                if (right->right != NULL) return false;
            }
            if (left->right != NULL) {
                ql.push(left->right);
                qr.push(right->left);
            } else {
                if (right->left != NULL) return false;
            }
        }

        return true;
    }
};