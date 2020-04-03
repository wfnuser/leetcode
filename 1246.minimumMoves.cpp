class Solution {
public:

    unordered_map<int, unordered_map<int, int>> mem;

    int compute(vector<int>& arr, int l, int r) {
        if (l > r) return 0;
        if (r - l == 1 && arr[l] == arr[r]) return 1;
        if (r - l == 1 && arr[l] != arr[r]) return 2;
        if (mem[l][r]) return mem[l][r];

        int res = r - l + 1;
        for (int i = l; i <= r; i++) {
            if (arr[l] == arr[i]) {
                res = min(res, max(1, compute(arr, l+1, i-1)) + compute(arr, i+1, r));
            }
        }

        mem[l][r] = res;
        return res;
    }

    int minimumMoves(vector<int>& arr) {
        return compute(arr, 0, arr.size()-1);
    }
};