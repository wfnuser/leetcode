class Solution {
public:
    unordered_map<string, int> dp;
    
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        // 最开始的dp数组为 dp[i][key]
        // 表示以i位置结尾的，只包含key中出现字母的数量
        // 由于dp[i][key]只跟dp[i-1][key]相关，简化空间复杂度
        // 略去i,用dp[key]表示当前位置，只包含key中出现字母的数量，滚动dp
        dp["abc"] = 0;
        dp["ab"] = 0;
        dp["bc"] = 0;
        dp["ca"] = 0;
        dp["a"] = 0;
        dp["b"] = 0;
        dp["c"] = 0;
        
        if (s.size() < 3) return 0;
        
        int abc = 0;

        for (int i = 0; i < s.size(); i++) {
            // 以a为例子分析
            if (s[i] == 'a') {
                // i-1位置为'a'结尾的数量，都可以加上当前的'a'
                // 'a'单独作为字符可以增加一个'a'的串
                dp["a"]++;
                // 同样以i位置结尾的只含'ab'的字符串，要么是i-1结尾字符串里只有'ab'要么只有'b'
                // 其他几个类似
                dp["ab"] = dp["b"] + dp["ab"];
                dp["ca"] = dp["c"] + dp["ca"];
                dp["abc"] = dp["bc"] + dp["abc"];
                // 这里还需要清空一下不含'a'的dp值，因为当前为'a' 所以不含a的以当前位置结尾的数量要清零
                dp["bc"] = 0;
                dp["b"] = 0;
                dp["c"] = 0;
            } else if (s[i] == 'b') {
                dp["b"]++;
                dp["bc"] = dp["c"] + dp["bc"];
                dp["ab"] = dp["a"] + dp["ab"];
                dp["abc"] = dp["ca"] + dp["abc"];
                dp["ca"] = 0;
                dp["a"] = 0;
                dp["c"] = 0;
            } else {
                dp["c"]++;
                dp["ca"] = dp["a"] + dp["ca"];
                dp["bc"] = dp["b"] + dp["bc"];
                dp["abc"] = dp["ab"] + dp["abc"];
                dp["ab"] = 0;
                dp["a"] = 0;
                dp["b"] = 0;
            }
            // 记录每个位置结尾包含abc的字符串总数
            abc += dp["abc"];
            
        }
        
        return abc;
    }
};