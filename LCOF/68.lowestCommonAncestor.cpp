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
    vector<TreeNode*> p1;
    vector<TreeNode*> p2;

    bool flag = false;

    void search(TreeNode* root, TreeNode* target, vector<TreeNode*>& p) {
        if (flag) return;
        if (root == NULL) return;
        if (root == target) {
            flag = true;
            p.push_back(target);
            return;
        }

        p.push_back(root);
        search(root->left, target, p);        
        search(root->right, target, p);
        if (flag) return;
        p.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        flag = false;
        search(root, p, p1);
        flag = false;
        search(root, q, p2);

        int len = min(p1.size(), p2.size());
        TreeNode* ans;

        for (int i = 0; i < len; i++) {
            if (p1[i] == p2[i]) {
                ans = p1[i];
            } else break;
        }
        return ans;
    }
};