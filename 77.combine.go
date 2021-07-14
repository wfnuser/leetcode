func combine(n int, k int) [][]int {
    ans := [][]int{}
    s := []int{}

    var findSubsets func(index int)
    findSubsets = func(index int) {
        if len(s) > k || len(s) + (n-index+1) < k{
            return 
        }
        if index == n + 1 {
            tmp := make([]int, k)
			copy(tmp, s)
			ans = append(ans, tmp)
            return
        }
        findSubsets(index+1)
        s = append(s, index)
        findSubsets(index+1)
        s = s[:len(s)-1]
    }

    findSubsets(1)
    return ans
}
