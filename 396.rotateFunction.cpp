class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sum = 0;

        for (auto a: A) {
            sum += a;
        }

        long delta = 0;
        long maxDelta = 0;
        for (int i = A.size()-1; i >= 0; i--) {
            delta += sum - A.size()*A[i];
            maxDelta = max(maxDelta, delta);
        }

        long ans = 0;
        for (int i = 0; i < A.size(); i++) {
            ans += i*A[i];
        }

        return ans+maxDelta;
    }
};