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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        queue<TreeNode> qn;
        queue<string> qp;
        if (root == NULL) {
            return ans;
        }
        qn.push(*root);
        qp.push(to_string(root->val));
        while(qn.size() > 0) {
            TreeNode node = qn.front();
            qn.pop();
            string path = qp.front();
            qp.pop();
            if (node.left != NULL) {
                qn.push(*node.left);
                qp.push(path + "->" + to_string(node.left->val));
            }
            if (node.right != NULL) {
                qn.push(*node.right);
                qp.push(path + "->" + to_string(node.right->val));
            }
            if (node.left == NULL && node.right == NULL) {
                ans.push_back(path);
            }
        } 
        return ans;
    }
};
