class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            // left odd : (i + 1) / 2 
            // right odd : (n - i) / 2
            // left even : i / 2 + 1
            // right even : (n - i - 1) / 2 + 1

            sum += arr[i] * (((i+1)/2) * ((n-i)/2) + (i/2+1) * ((n-i-1)/2+1));
        }

        return sum;
    }
};
