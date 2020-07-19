func numDecodings(s string) int {
    n := len(s)
    if n == 0 {return 0}
    if s[0] == '0' {return 0}
    if n == 1 {return 1}

    dp := make([]int, n) // 解码方法数
    dp[0] = 1

    for i := 1; i < n; i++ {
        if s[i] == '0' {
            if s[i-1] == '1' || s[i-1] == '2' { // 可能有解
                if i == 1 {
                    dp[i] = 1
                } else {
                    dp[i] = dp[i-2]
                }
            } else { // 否则非法
                return 0
            }
        } else if s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6' {
            dp[i] = dp[i-1]
            if i >= 2 {
                dp[i] += dp[i-2]
            } else {
                dp[i]++
            }
        } else {
            dp[i] = dp[i-1]
        }
    }

    return dp[n-1]
}