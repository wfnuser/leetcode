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
    unordered_map<TreeNode*, int> startFrom;
    int ans = 0;
    
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        dfs(root->right);
        TreeNode* cur = root;
        int pathR = 1;
        int pathL = 1;
        if (cur->right && cur->right->val == cur->val+1) {
            pathR += startFrom[cur->right];
        }
        if (cur->left && cur->left->val == cur->val+1) {
            pathL += startFrom[cur->left]; 
        }
        startFrom[cur] = max(pathL, pathR);
        ans = max(ans, startFrom[cur]);
    }


    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
};