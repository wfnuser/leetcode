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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> ans;

        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            Q.pop();
            if (cur == NULL) continue;
            ans.push_back(cur->val);
            Q.push(cur->left);
            Q.push(cur->right);
        }

        return ans;
    }  
};