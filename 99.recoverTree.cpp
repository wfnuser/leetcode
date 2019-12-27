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
    TreeNode* traversal(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) return NULL;
        if ((max != NULL && root->val >= max->val)) {
            TreeNode* leftNode = traversal(root->left, min, max);
            if (leftNode != NULL) return leftNode;
            return root;
        }
        if ((min != NULL && root->val <= min->val)) {
            TreeNode* rightNode = traversal(root->right, min, max);
            if (rightNode != NULL) return rightNode;
            return root;
        }

        TreeNode* leftNode = traversal(root->left, min, root);
        TreeNode* rightNode = traversal(root->right, root, max);

        if (leftNode != NULL && rightNode != NULL) {
            int tmp = leftNode->val;
            leftNode->val = rightNode->val;
            rightNode->val = tmp;
            return NULL;
        }
        if (leftNode != NULL) return leftNode;
        if (rightNode != NULL) return rightNode;

        return NULL;
    }

    void recoverTree(TreeNode* root) {
        TreeNode* node = traversal(root, NULL, NULL);
        if (node != NULL) {
            int tmp = node->val;
            node->val = root->val;
            root->val = tmp;
        }
    }
};