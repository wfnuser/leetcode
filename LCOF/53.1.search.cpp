class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        int find = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                find = mid;
                break;
            }
            if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        if (find == -1) return 0;

        int cnt = 0;
        for (int i = find; i < n; i++) {
            if (nums[i] == target) cnt++;
            else break;
        }
        for (int i = find-1; i >= 0; i--) {
            if (nums[i] == target) cnt++;
            else break;
        }

        return cnt;
    }
};