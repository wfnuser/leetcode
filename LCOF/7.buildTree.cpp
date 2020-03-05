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
        int n = preorder.size();
        if (n == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if (n == 1) {
            return root;
        }

        vector<int> left;
        vector<int> right;

        vector<int> leftP;
        vector<int> rightP;
        int p = 1;

        for (int i = 0; i < n; i++) {
            if (inorder[i] == root->val) {
                for (int j = 0; j < i; j++) {
                    left.push_back(inorder[j]);
                    leftP.push_back(preorder[p++]);
                }
                for (int j = i+1; j < n; j++) {
                    right.push_back(inorder[j]);
                    rightP.push_back(preorder[p++]);
                }
            }
        }

        root->left = buildTree(leftP, left);
        root->right = buildTree(rightP, right);
        
        return root;
    }
};