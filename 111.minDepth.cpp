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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> l;
        int level;
        
        if (root == NULL) return 0;

        q.push(root);
        l.push(1);

        while(!q.empty()) {
            TreeNode* root = q.front();
            level = l.front();
            q.pop();
            l.pop();

            if (root->left == NULL && root->right == NULL) {
                return level;
            }

            if (root->left != NULL) {
                q.push(root->left);
                l.push(level+1);
            }
            if (root->right != NULL) {
                q.push(root->right);
                l.push(level+1);
            }
        }

        return level;
    }
};