class Solution {
public:
    bool check(vector<int>& postorder, int l, int r) {
        if (l >= r - 1) return true;
        int root = postorder[r];

        int cur = r - 1;
        for (;cur >= l; cur--) {
            if (postorder[cur] < root) {
                break;
            }
        }
        if (cur < l) return check(postorder, l, r - 1);

        if (!check(postorder, cur + 1, r - 1)) return false;
        
        int border = cur;

        for (; cur >= l; cur--) {
            if (postorder[cur] > root) return false;
        }

        return check(postorder, l, border);
    }

    bool verifyPostorder(vector<int>& postorder) {
        int l = 0;
        int r = postorder.size() - 1;
        if (r <= 1) return true;

        return check(postorder, l, r);
    }
};