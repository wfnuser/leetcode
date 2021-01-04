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
    bool flag = false;
    int last = 0;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) return 0;
        
        getMinimumDifference(root->left);
        if (flag == true) ans = min(ans, root->val - last);
        last = root->val;
        flag = true;
        getMinimumDifference(root->right);

        return ans;
    }
};