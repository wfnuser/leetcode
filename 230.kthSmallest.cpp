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
    vector<int> sortedV;

    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        sortedV.push_back(root->val);
        dfs(root->right);
    };

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);

        return sortedV[k-1];
    }
};