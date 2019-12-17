/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int size = height.size();
        int l = 0;
        int r = size - 1;
        int ans = 0;
        while(l<r) {
            if(height[l]<height[r]) {
                if(ans<(r-l)*height[l]) ans = (r-l)*height[l];
                l++;
            } else {
                if(ans<(r-l)*height[r]) ans = (r-l)*height[r];
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end
