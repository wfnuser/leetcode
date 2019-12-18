/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution
{
public:
    bool search(int pos, vector<int> &nums, vector<int> &remains)
    {
        if (pos >= nums.size())
            return true;

        int num = nums[pos];
        for (int i = 0; i <= 3; i++)
        {
            if (remains[i] >= num)
            {
                remains[i] -= num;
                if (search(pos + 1, nums, remains))
                    return true;
                remains[i] += num;
            }
        }

        return false;
    }

    bool makesquare(vector<int> &nums)
    {
        int sum = 0;
        if (nums.size() < 4) return false;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 4 != 0)
            return false;
        vector<int> remains(4, sum / 4);

        return search(0, nums, remains);
    }
};
// @lc code=end
