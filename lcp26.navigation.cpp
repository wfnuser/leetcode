// 太难了吧...
class Solution {
public:
    bool haveNavigation(TreeNode* n, int &ans, bool &ad)
    {
        if (n == NULL) return false;
        bool lft = haveNavigation(n->left, ans, ad);
        bool rit = haveNavigation(n->right, ans, ad);
        bool navigation = lft || rit;
        if (n->left == NULL || n->right == NULL)
            return navigation;
        else
        {
            ad = lft && rit;
            if (!navigation)
                ans++;
            return true;
        }
    }

    int navigation(TreeNode* root) {
        int ans = 0;
        bool lad = true, rad = true;
        bool lft = haveNavigation(root->left, ans, lad);
        bool rit = haveNavigation(root->right, ans, rad);
        if (ans == 0)
            ans = 1;
        else if (!(lft && rit))
        {
            if (lft && !lad ||
                rit && !rad)
                ans++;
        }
        return ans;
    }
};