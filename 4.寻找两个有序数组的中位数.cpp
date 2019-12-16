/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (l1 > l2) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = l1;
        int k = (l1 + l2 + 1) / 2;
        while(l<r) {
            int m1 = (l+r)/2;
            int m2 = k - m1;
            if (nums1[m1] < nums2[m2-1]) {
                l = m1 + 1;
            } else {
                r = m1;
            }
        }
        int m1 = l;
        int m2 = k - m1;

        int left = INT_MIN;
        int right = INT_MAX;
        if (m1 >= 1) left = nums1[m1-1];
        if (m2 >= 1 && left < nums2[m2-1]) left = nums2[m2-1];
        if (m1 < l1) right = nums1[m1];
        if (m2 < l2 && right > nums2[m2]) right = nums2[m2];
        if ((l1+l2)%2 == 0) {
            return (left + right) / 2.0;
        } else {
            return left;
        }

    }
};
// @lc code=end

