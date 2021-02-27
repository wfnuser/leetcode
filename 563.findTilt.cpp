/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int sum(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int left = sum(node->left);
        int right = sum(node->right);

        ans += abs(left-right);
        return node->val + left + right;
    }

    int findTilt(TreeNode* root) {
        sum(root);
        return ans;
    }
};