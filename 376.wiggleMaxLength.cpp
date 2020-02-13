class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> increase(n, 1);
        vector<int> decrease(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                increase[i] = decrease[i-1]+1;
                decrease[i] = decrease[i-1];
            }
            if (nums[i] < nums[i-1]) {
                decrease[i] = increase[i-1] + 1;
                increase[i] = increase[i-1];
            }
            if (nums[i] == nums[i-1]) {
                decrease[i] = decrease[i-1];
                increase[i] = increase[i-1];
            }
        }

        return max(decrease[n-1], increase[n-1]);
    }
};