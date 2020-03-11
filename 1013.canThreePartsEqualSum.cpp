class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto a: A) {
            sum += a;
        }
        if (sum % 3 != 0) return false;
        int part = 0;
        if (A.size() < 3) return false;
        
        int left;
        for (left = 0; left < A.size(); left++) {
            part += A[left];
            if (part == sum / 3) break;
        }

        part = 0;
        int right;
        for (right = A.size() - 1; right >= 0; right--) {
            part += A[right];
            if (part == sum / 3) break;
        }

        if (left >= right - 1) return false;
        return true;
    }
};