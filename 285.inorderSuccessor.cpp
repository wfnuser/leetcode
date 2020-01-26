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

    TreeNode* next = NULL;
    int found = 0;

    void dfs(TreeNode* root, TreeNode* p) {
        if (root == NULL) {
            return;
        }
        if (found == 2) {
            return;
        }
        dfs(root->left, p);
        if (found == 1) {
            next = root;
            found = 2;
        }
        if (root == p) {
            found = 1;
        }
        dfs(root->right, p);
    }
    

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return next;
    }
};