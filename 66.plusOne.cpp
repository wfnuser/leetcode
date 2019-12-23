class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int size = digits.size();
        digits[size-1]++;
        int carry = 0;
        for (int i = size-1; i >= 0; i--) {
            if (digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
                if (i>=1) digits[i-1] += carry;
            } else {
                carry = 0;
            }
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};