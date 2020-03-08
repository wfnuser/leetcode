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
    int ans = 0;
    
    int longestLeft(TreeNode* root) {
        int tmp = 0;
        if (root->left != NULL) {
            ans = max(ans, longestLeft(root->left));
            tmp = 1 + longestRight(root->left);
            ans = max(ans, tmp);
            return tmp;
        } else {
            return 0;
        }
    }    
    
    int longestRight(TreeNode* root) {
        int tmp = 0;
        if (root->right != NULL) {
            ans = max(ans, longestRight(root->right));
            tmp = 1 + longestLeft(root->right);
            ans = max(ans, tmp);
            return tmp;
        } else {
            return 0;
        }
    }
    
    int longestZigZag(TreeNode* root) {
        if (root == NULL) return 0;
        longestRight(root);
        longestLeft(root);
        
        return ans;
    }
};