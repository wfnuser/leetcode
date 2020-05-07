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

    bool flag = false;

    bool check(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (t->val != s->val) return false;

        return check(s->left, t->left) && check(s->right, t->right);
    }

    void dfs(TreeNode* root, TreeNode* target) {
        if (flag) return;
        if (root == NULL) return;
        if (check(root, target)) {
            flag = true;
            return;
        }

        dfs(root->left, target);
        dfs(root->right, target);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {        
        dfs(s, t);
        return flag;
    }
};