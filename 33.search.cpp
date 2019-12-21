class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums.size() == 0) return -1;

        int first = nums[0];
        if (target == first) return 0;

        int rotate = -1;
        while (l<r) {
            int mid=(l+r)/2;
            if (nums[mid]>=first) {
                l = mid+1;
            } else {
                r = mid;
            }
        }

        if (nums[l] > first) {
            rotate = -1;
        } else {
            rotate = l;
        }
        cout << rotate << endl;

        if (target < nums[0]) {
            l = rotate;
            if (rotate == -1) return -1;
            r = nums.size() - 1;

            while(l<r) {
                int mid = (l+r)/2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }

            if (nums[l] == target) return l;
        }

        if (target > nums[0]) {
            l = 0;
            r = rotate - 1;
            if (r<0) r = nums.size() - 1;
            while(l<r) {
                int mid = (l+r)/2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }
            if (nums[l] == target) return l;
        }

        return -1;
    }
};