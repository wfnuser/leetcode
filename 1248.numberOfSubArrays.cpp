class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int n = nums.size();
        int ans = 0;

        while (r < n) {
            if (nums[r] % 2 == 1) {
                cnt++;
            }

            if (cnt == k) {
                int tmpr = r + 1;
                while (tmpr < n && nums[tmpr] % 2 != 1) {
                    tmpr++;
                }

                int tmpl = l;
                while (nums[tmpl] % 2 != 1) {
                    tmpl++;
                }

                ans += (tmpl - l + 1) * (tmpr - r);

                l = tmpl + 1;
                r = tmpr;
                cnt--;
                continue;
            }

            r++;
        }

        return ans;
    }
};