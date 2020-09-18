class Solution {
public:
    vector<int> ans;
    long last = 1L + INT_MAX;
    int lastcnt = 0;
    int cnt = 1;

    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        dfs(root->left);
        int cur = root->val;

        if (last == 1L + INT_MAX) {
            last = cur;
            cnt = 1;
            dfs(root->right);
            return;
        }

        if (cur == last) {
            cnt++;
        } else {
            if (cnt > lastcnt) {
                ans = vector<int>();
                ans.push_back(last);
            }
            if (cnt == lastcnt) {
                ans.push_back(last);
            }
            cout << last << " " << cur << " " << lastcnt << endl;
            lastcnt = max(lastcnt, cnt);
            cnt = 1;
            last = cur;
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return vector<int>();
        dfs(root);
        if (cnt > lastcnt) {
            ans = vector<int>();
            ans.push_back(last);
        }
        if (cnt == lastcnt) {
            ans.push_back(last);
        }
        return ans;
    }
};
// @lc code=end

