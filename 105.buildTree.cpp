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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) return NULL;
        int first = preorder[0];
        TreeNode* root = new TreeNode(first);

        vector<int> left;
        vector<int> right;
        int flag = 0;
        
        for (auto num:inorder) {
            if (num == first) {flag = 1; continue;}
            if (flag == 0) left.push_back(num);
            if (flag == 1) right.push_back(num);
        }

        preorder.erase(preorder.begin());

        root->left = buildTree(preorder, left);
        root->right = buildTree(preorder, right);

        return root;
    }
};