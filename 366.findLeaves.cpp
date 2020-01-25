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
    unordered_map<int, vector<int>> m;

    int dfs(TreeNode* root) {
        int index = 0;
        int delta = 0;
        if (root->left != NULL) {
            delta = dfs(root->left);
        }
        if (root->right != NULL) {
            delta = max(delta, dfs(root->right));
        }
        index = delta + 1;
        
        if (root->left == NULL && root->right == NULL) {
            index = 0;
        }

        m[index].push_back(root->val);
        return index;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root == NULL) {
            vector<vector<int>> ans;
            return ans;
        }
        
        vector<vector<int>> ans(dfs(root)+1, vector<int>());
        
        for (auto pair: m) {
            ans[pair.first] = pair.second;
        }

        return ans;
    }
};