class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> snums = nums;
        sort(snums.begin(), snums.end());

        int left = INT_MAX;
        int right = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == snums[i]) continue;
            if (left == INT_MAX) {left = i; right = i;}
            else right = i;
        }

        if (left == INT_MAX) return 0;

        return right - left + 1;
    }
};
