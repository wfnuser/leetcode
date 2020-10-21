/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 *
 * https://leetcode-cn.com/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (39.79%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 67.7K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
 * 
 * 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：name = "alex", typed = "aaleex"
 * 输出：true
 * 解释：'alex' 中的 'a' 和 'e' 被长按。
 * 
 * 
 * 示例 2：
 * 
 * 输入：name = "saeed", typed = "ssaaedd"
 * 输出：false
 * 解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
 * 
 * 
 * 示例 3：
 * 
 * 输入：name = "leelee", typed = "lleeelee"
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：name = "laiden", typed = "laiden"
 * 输出：true
 * 解释：长按名字中的字符并不是必要的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * name.length <= 1000
 * typed.length <= 1000
 * name 和 typed 的字符都是小写字母。
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        if (typed.size() < name.size()) return false;
        if (name.size() == 0 && typed.size() == 0) return true;
        if (name.size() == 0) return false;
        
        for (;i < name.size() && j < typed.size();) {
            if (name[i] != typed[j]) return false;
            for (;i+1 < name.size() && name[i] == name[i+1]; i++) {
                cnt1++;
            }
            for (;j+1 < typed.size() && typed[j] == typed[j+1]; j++) {
                cnt2++;
            }
            if (cnt2 < cnt1) return false;
            cnt1 = 0;
            cnt2 = 0;
            i++;
            j++;
        }

        if (j < typed.size() || i < name.size()) return false;
        return true;
    }
};
// @lc code=end

