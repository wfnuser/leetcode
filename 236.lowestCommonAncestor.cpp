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

    void dfs(vector<TreeNode*>& path, TreeNode* root, TreeNode* target) {
        if (root == NULL) return;
        path.push_back(root);
        if (root == target) {
            return;
        }
        dfs(path, root->left, target);
        dfs(path, root->right, target);
        if (path.back() == target) return;
        path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;

        dfs(pathP, root, p);
        dfs(pathQ, root, q);
        
        int i = 0;

        for (i = 0; i < pathP.size(); i++) {
            if (i >= pathQ.size() || pathP[i] != pathQ[i]) {
                break;
            }
        }

        return pathP[i-1];
    }
};