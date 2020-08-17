func convertToBase7(num int) string {
    var ans int

    var i = 1
    for num != 0 {
        remainder := num % 7
        num = num / 7
        ans += remainder * i
        i *= 10
    }

    return strconv.Itoa(ans)
}