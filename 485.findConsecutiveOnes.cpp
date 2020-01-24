class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) {
            if (nums[0] == 1) return 1;
            else return 0;
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans = max(cnt, ans);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        ans = max(cnt, ans);

        return ans;
    }
};