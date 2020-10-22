
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode-cn.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (72.59%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    29.1K
 * Total Submissions: 38.9K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S的长度在[1, 500]之间。
 * S只包含小写字母 'a' 到 'z' 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> pos;

        for (int i = 0; i < S.size(); i++) {
            if (pos.find(S[i]) == pos.end()) {
                pos[S[i]] = i;
            } else {
                pos[S[i]] = max(pos[S[i]], i);
            }
        }

        int border = 0;
        int last = -1;
        vector<int> ans;

        for (int i = 0; i < S.size(); i++) {
            if (pos[S[i]] == border && pos[S[i]] == i) {
                ans.push_back(i - last);
                last = i;
                border++;
            } else {
                border = max(border, pos[S[i]]);
            }
        }

        return ans;
    }
};
// @lc code=end

