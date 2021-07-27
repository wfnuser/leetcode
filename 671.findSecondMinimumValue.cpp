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
    int first = INT_MAX;
    int second = INT_MAX;
    bool flag = false;

    void dfs(TreeNode* root) {
        if (root == NULL) return;
        if (root->val < first) {
            second = first;
            first = root->val;
        } else if (root->val != first && root->val <= second) {
            flag = true;
            second = root->val;
        }
        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);

        if (!flag) return -1;
        return second;
    }
};
