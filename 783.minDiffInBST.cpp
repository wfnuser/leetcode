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
    TreeNode* pre;
    int ans = INT_MAX;

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) return ans;
        minDiffInBST(root->left);
        if (pre != NULL) ans = min(ans, root->val - pre->val);
        pre = root;
        minDiffInBST(root->right);
        return ans;
    }
};