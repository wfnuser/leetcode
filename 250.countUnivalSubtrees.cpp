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
    int ans = 0;
    bool isUnivalNode(TreeNode* root) {
        bool left = true;
        bool right = true;
        if (root->left != NULL) {
            left = isUnivalNode(root->left);
            if (root->left->val != root->val) {
                left = false;
            }
        }
        if (root->right != NULL) {
            right = isUnivalNode(root->right);
            if (root->right->val != root->val) {
                right = false;
            }
        }

        if (left && right) {
            ans++;
            return true;
        }
        return false;
    }

    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        isUnivalNode(root);
        return ans;
    }
};