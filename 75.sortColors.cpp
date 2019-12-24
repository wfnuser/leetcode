class Solution {
public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(vector<int>& nums) {
        int size= nums.size();

        int r = size - 1;
        int l = 0;
        int cur = 0;

        while(cur <= r) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[l]);
                l++;
                cur++;
            } else if (nums[cur] == 1) {
                cur++;
            } else {
                swap(nums[r], nums[cur]);
                r--;
            }
        }
    }
};