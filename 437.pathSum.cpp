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
    unordered_map<TreeNode*, unordered_map<int, int>> memory1;
    unordered_map<TreeNode*, unordered_map<int, int>> memory2;
    
    int pathWithMe(TreeNode* root, int sum) {
        if (memory2[root][sum] != 0) {
            int ans = memory2[root][sum];
            if (ans < 0) ans = 0;
            return ans;
        }

        if (root == NULL) return 0;
        int ans = 0;
        if (root->val == sum) {
            ans++;
        }
        ans += pathWithMe(root->left, sum-root->val);
        ans += pathWithMe(root->right, sum-root->val);
        
        memory2[root][sum] = ans;
        if (memory2[root][sum] == 0) memory2[root][sum] = -1;

        return ans;
    }

    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;

        if (memory1[root][sum] != 0) {
            int ans = memory1[root][sum];
            if (ans < 0) ans = 0;
            return ans;
        }

        int ans = pathWithMe(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);

        memory1[root][sum] = ans;
        if (memory1[root][sum] == 0) memory1[root][sum] = -1;

        return pathWithMe(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};