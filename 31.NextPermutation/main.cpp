class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int pos = 0;
        int tmp = 0;
        int target = 0;

        // find the first number which is smaller than the one after
        for (int i = size - 1; i >= 1; i--) {
            if (nums[i] > nums[i-1]) {
                pos = i;
                break;
            }
        }

        // if there is no reverted pairs
        if (pos != 0) {
            for (int i = pos; i <= size - 1; i++) {
                if (nums[i] > nums[pos - 1]) target = i;
                else break;
            }
            // exchange first revert num and the smallest number larger than that
            tmp = nums[target];
            nums[target] = nums[pos - 1];
            nums[pos - 1] = tmp;
        }

        // revert all the data after pos (include pos)
        int l = pos;
        int r = size - 1;
        while (l < r) {
            tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }

    }
};

