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
    bool isValidBST(TreeNode* root, long min, long max, bool firstMin, bool firstMax) {
        if (root == NULL) return true;
        if ((root->val >= max && !firstMax) || (root->val <= min  && !firstMin)) return false;
        if (root->left != NULL && root->val <= root->left->val) {
            return false;
        }
        if (root->right != NULL && root->val >= root->right->val) {
            return false;
        }

        return isValidBST(root->left, min, root->val, firstMin, false) && isValidBST(root->right, root->val, max, false, firstMax);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX, true, true);
    }
};