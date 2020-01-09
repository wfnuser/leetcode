/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (40.70%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 29.9K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 
 * 
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 
 * 示例 1:
 * 
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * 
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        if (ratings.size() == 0) return ans;
        if (ratings.size() == 1) return 1;
        
        int preHeight = 1;
        int acc = 1;

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                ans += preHeight;
                preHeight++;
            } else if (ratings[i] == ratings[i-1]) {
                ans += preHeight;
                preHeight = 1;
            } else {
                int acc = 0;
                while(i < ratings.size() && ratings[i] < ratings[i-1]) {
                    i++;
                    acc++;
                }
                if (i == ratings.size()) {
                    ans += (acc+2)*(acc+1)/2;
                    if (preHeight > acc + 1) ans += preHeight - acc - 1;
                    return ans;
                }
                ans += (acc+2)*(acc+1)/2 - 1;
                if (preHeight > acc + 1) ans += preHeight - acc - 1;
                preHeight = 1; 
                i--;
            }
        }

        ans += preHeight;

        return ans;
    }
};
// @lc code=end

