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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode*> q;
        queue<int> level;
        q.push(root);
        level.push(0);
        int cur = -1;

        while(!q.empty()) {
            TreeNode* node = q.front();
            int l = level.front();
            q.pop();
            level.pop();

            if (l > cur) {
                cur = l;
                ans.push_back(vector<int>());
            }
            if (cur % 2 == 0) ans[cur].push_back(node->val);
            else ans[cur].insert(ans[cur].begin(),node->val);

            if (node->left != NULL) {
                level.push(cur+1);
                q.push(node->left);
            }
            if (node->right != NULL) {
                level.push(cur+1);
                q.push(node->right);
            }
        }

        return ans;
    }
};