func subarraysDivByK(A []int, K int) int {
    partialSum := 0
    cnt := make(map[int]int)
    cnt[0] = 1
    ans := 0

    for i := 1; i <= len(A); i++ {
        partialSum = ((partialSum + A[i-1]) % K + K) % K 
		_, appeared := cnt[partialSum]

        if !appeared {
            cnt[partialSum] += 1
        } else {
            ans += cnt[partialSum]
            cnt[partialSum] += 1
        }
    }

    return ans
}