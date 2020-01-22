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
    int search(TreeNode* root, double target) {
        int distance = INT_MAX;
        int flag = false;
        int tmp = 0;
        if (target > root->val) {
            if (root->right) {
                flag = true;
                tmp = search(root->right, target);
            }
        } else {
            if (root->left) {
                flag = true;
                tmp = search(root->left, target);
            }
        }

        if (!flag) return root->val;

        if (abs(root->val - target) < abs(target - tmp)) return root->val;
        return tmp;
    }

    int closestValue(TreeNode* root, double target) {
        if (root == NULL) return 0;
        return search(root, target);
    }
};