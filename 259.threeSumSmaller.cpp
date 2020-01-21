class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() <= 2) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            ans += twoSumSmaller(nums, i+1, nums.size()-1, target-nums[i]);
        }
        return ans;
    }

    int twoSumSmaller(vector<int>& nums, int left, int right,int target) {
        int l = left;
        int r = right;
        int ans = 0;

        while(l < r) {
            if (nums[l] + nums[r] < target) {
                ans += r - l;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};