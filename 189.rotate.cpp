class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1) return;
        k = k % nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }

    void reverse(vector<int>& nums, int s, int e) {
        while(s<e) {
            int tmp = nums[s];
            nums[s] = nums[e];
            nums[e] = tmp;
            s++;
            e--;
        }
    }
};