class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int ans = 0;
        if (A.size() <= 1) return ans;
        
        sort(A.begin(), A.end());
        int last = 0;
        
        for (int i = 1; i < A.size(); i++) {
            if (A[i]-A[last] < i - last) {
                ans += A[last] + i - last - A[i];
            } else {
                last = i;
            }
        }

        return ans;
    }
};