/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct DP {
    int min;
    int max;
    int size;
};

class Solution {
public:
    unordered_map<TreeNode*, DP> dp;
    int ans = 0;

    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        dfs(root->right);

        bool isBST = true;
        
        int tmp = 1;
        int minN = root->val;
        int maxN = root->val;
        if (root->left) {
            if (dp[root->left].size == 0) {
                isBST = false;
            } else {
                if (root->val <= dp[root->left].max) {
                    isBST = false;
                } else {
                    minN = min(minN, dp[root->left].min);
                    tmp = tmp + dp[root->left].size;
                }
            }
        }
        if (root->right) {
            if (dp[root->right].size == 0) {
                isBST = false;
            } else {
                if (root->val >= dp[root->right].min) {
                    isBST = false;
                } else {
                    maxN = max(maxN, dp[root->right].max);
                    tmp = tmp + dp[root->right].size;
                }
            }
        }
        dp[root] = DP();

        if (isBST) {
            dp[root].size = tmp;
            dp[root].min = minN;
            dp[root].max = maxN;
            ans = max(ans, tmp);
        } else {
            dp[root].size = 0;
        }
    }

    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};