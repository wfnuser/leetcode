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
    TreeNode* findMin(TreeNode* root) {
        if (root->left == NULL) return root;
        return findMin(root->left);
    }

    TreeNode* deleteMin(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        root->left = deleteMin(root->left);
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if (root->left == NULL) {
                return root->right;
            } else if (root->right == NULL) {
                return root->left;
            } else {
                root->val = findMin(root->right)->val;
                root->right = deleteMin(root->right);
                return root;
            }
        }
        
        return root;
    }
};