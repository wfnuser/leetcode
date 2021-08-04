class Solution {
public:

    int search(vector<int>& nums, int sum, int start) {
        int left = start;
        int right = nums.size() - 1;
        int k = left;

        while(left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= sum) {
                right = mid - 1;
            } else {
                left = mid + 1;
                k = mid;
            }
        }

        return k;
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {
                int target = search(nums, nums[i] + nums[j], j+1);
                if (nums[target] < nums[i] + nums[j]) ans += target - j;
            }
        }

        return ans;
    }
};
