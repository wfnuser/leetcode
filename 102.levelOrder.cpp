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
        queue<TreeNode*> q;
        queue<int> level;
        q.push(root);
        level.push(0);
        int cur = -1;
        vector<vector<int>> ans;

        while(!q.empty()) {
            TreeNode* node = q.front();
            int l = level.front();
            q.pop();
            level.pop();

            if (node == NULL) continue;

            if (l > cur) {
                cur = l;
                ans.push_back(vector<int>());
            }
            ans[cur].push_back(node->val);

            level.push(cur+1);
            q.push(node->left);
            level.push(cur+1);
            q.push(node->right);
        }

        return ans;
    }
};