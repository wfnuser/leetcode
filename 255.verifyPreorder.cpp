class Solution {
public:
    bool verify(vector<int>& preorder, int start, int upper, int lower, int end) {
        int middle = preorder[start];

        if (middle > upper || middle < lower) {
            return false;
        }
        if (start >= end - 1) {
            return true;
        }

        bool right = true;
        bool left = true;

        int i;
        for (i = start + 1; i < end; i++) {
            if (preorder[i] > middle) {
                break;
            }
        }

        if (preorder[start+1] <= middle) {
            left = verify(preorder, start+1, min(upper, middle), lower, i);
        }

        if (i < end) {
            right = verify(preorder, i, upper, max(lower, middle), end);
        }

        return left && right;
    }

    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return true;
        return verify(preorder, 0, INT_MAX, INT_MIN, preorder.size());
    }
};