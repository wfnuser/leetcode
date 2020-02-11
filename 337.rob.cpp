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
    unordered_map<TreeNode*, int> memT;
    unordered_map<TreeNode*, int> memF;

    int cnt(TreeNode* root, bool parent) {
        if (root == NULL) return 0;
        if (parent && memT[root]) return memT[root];
        if (!parent && memF[root]) return memF[root];

        int child = 0;
        if (parent) {
            child = cnt(root->left, false) + cnt(root->right, false);
            memT[root] = child;
        } else {
            child = root->val + cnt(root->left, true) + cnt(root->right, true);
            child = max(child, cnt(root->left, false) + cnt(root->right, false));
            memF[root] = child;
        }
        return child;
    }

    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        return max(cnt(root->left, false)+cnt(root->right, false), root->val + cnt(root->left, true) + cnt(root->right, true));
    }
};