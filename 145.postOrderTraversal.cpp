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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> s;
        set<TreeNode*> appeared; 
        
        s.push(root);

        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (appeared.find(node) != appeared.end()) {
                ans.push_back(node->val);
                continue;
            }
            appeared.insert(node);
            s.push(node);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }

        return ans;
    }
};