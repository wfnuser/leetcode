class Solution {
public:
    int massage(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> choose = vector<int>(size, 0);
        vector<int> notchoose = vector<int>(size, 0);

        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);

        choose[0] = nums[0];
        choose[1] = nums[1];
        notchoose[0] = 0;
        notchoose[1] = nums[0];

        int ans = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            choose[i] = notchoose[i-1] + nums[i];
            ans = max(ans, choose[i]);
            notchoose[i] = max(choose[i-1], notchoose[i-1]);
        }

        return ans;
    }
};