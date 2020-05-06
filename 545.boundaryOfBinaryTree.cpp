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
    vector<int> vl;
    vector<int> vr;
    vector<int> leaves;

    vector<int> ans;
    
    void dfsl(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL || root->right != NULL) vl.push_back(root->val);
        if (root->left) {dfsl(root->left);return;}
        if (root->right) {dfsl(root->right);return;}
        return;        
    }

    void dfsr(TreeNode* root) {
        if (root == NULL) return;
        if (root->right) {
            dfsr(root->right);
            if (root->left != NULL || root->right != NULL) vr.push_back(root->val);
            return;
        }
        if (root->left) {
            dfsr(root->left);
            if (root->left != NULL || root->right != NULL) vr.push_back(root->val);
            return;
        }
        return;        
    }

    void dfs(TreeNode* root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) leaves.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == NULL) return ans;
        vl.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            return vl;
        }

        dfsl(root->left);
        dfsr(root->right);
        dfs(root);

        vl.insert(vl.end(), leaves.begin(), leaves.end());
        vl.insert(vl.end(), vr.begin(), vr.end());

        return vl;
    }
};