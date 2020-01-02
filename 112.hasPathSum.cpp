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
    bool dfs(TreeNode* root, int sum, int target) {
        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum == target;
        }
        bool left = false;
        bool right = false;
        if (root->left != NULL) {
            left = dfs(root->left, sum, target);
        }
        if (left) return left;
        if (root->right != NULL) {
            right = dfs(root->right, sum, target);
        }
        if (right) return right;

        return false;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        return dfs(root, 0, sum);
    }
};