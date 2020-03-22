/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:

    void calNext(string needle, vector<int>& next) {
        next[0] = -1;
        int k = -1;

        for (int q = 1; q < needle.size(); q++) {
            while(k>-1&&needle[q]!=needle[k+1]) {
                k = next[k];
            }
            if (needle[q] == needle[k+1]) {
                k++;
            }
            next[q] = k;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        vector<int> next(needle.size(), -1);
        calNext(needle, next);

        int k = -1;
        for (int i = 0; i<haystack.size(); i++) {
            while(k>-1&&haystack[i]!=needle[k+1]) {
                k = next[k];
            }
            if (needle[k+1] == haystack[i]) {
                k++;
            }
            if(k==needle.size()-1) return i - k;
        }

        return -1;
    }
};
// @lc code=end

