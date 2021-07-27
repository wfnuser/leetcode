
class Solution {
private:
    unordered_map<int, int> sum2cnt;
    int maxcnt = 0;

    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);

        int sum = l + r + root->val;
        sum2cnt[sum]++;
        maxcnt = max(maxcnt, sum2cnt[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        
        dfs(root);
        for (auto iter = sum2cnt.begin(); iter != sum2cnt.end(); ++iter) {
            if (iter->second == maxcnt) {
                res.push_back(iter->first);
            }
        }

        return res;
    }
};
