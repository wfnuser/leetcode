func maxProfit(prices []int) int {
    if len(prices) <= 1 {
        return 0;
    }

    pre := prices[0]
    ans := 0

    for _, price := range(prices) {
        if price - pre > 0 {
            ans += price - pre
        }
        pre = price
    }

    return ans
}