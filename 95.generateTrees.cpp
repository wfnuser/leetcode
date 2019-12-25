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
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return vector<TreeNode*>(1, NULL);
        }
        if (start == end) {
            TreeNode* root = new TreeNode(start);
            vector<TreeNode*> ans(1, root);
            return ans;
        } else {
            vector<TreeNode*> ans; 
            for (int i = start; i <= end; i++) {
                vector<TreeNode*> left = generateTrees(start, i-1);
                vector<TreeNode*> right = generateTrees(i+1, end);

                for (int l = 0; l < left.size(); l++) {
                    for (int r = 0; r < right.size(); r++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[l];
                        root->right = right[r];
                        ans.push_back(root);
                    }
                }
            }
            return ans;
        }

    }

    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return vector<TreeNode*>();
        return generateTrees(1,n);
    }
};