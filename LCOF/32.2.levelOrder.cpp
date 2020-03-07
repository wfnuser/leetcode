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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        vector<vector<int>> ans;

        while(!Q.empty()) {
            queue<TreeNode*> nQ;
            vector<int> layer;
            while(!Q.empty()) {
                TreeNode* cur = Q.front();
                Q.pop();
                if (cur == NULL) continue;
                layer.push_back(cur->val);
                nQ.push(cur->left);
                nQ.push(cur->right);
            }
            if (!layer.empty()) ans.push_back(layer);
            Q = nQ;
        }

        return ans;
    }
};