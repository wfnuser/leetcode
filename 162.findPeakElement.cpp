class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = (l+r)/2;
            if (nums[mid] < nums[mid+1]) {
                l = mid + 1;
                continue;
            } else {
                r = mid;
            }
        }

        return l;
    }
};