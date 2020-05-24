func minWindow(s string, t string) string {
    cnt := make(map[byte]int)
    remain := len(t)
    length := int(^uint(0) >> 1)
    left := 0

    start := -1
    end := 0
	
	for i := 0; i < len(t); i++ {
		cnt[t[i]]++;
	}


    for i := 0; i < len(s); i++ {
        cnt[s[i]]--;
        if cnt[s[i]] >= 0 {
            remain--;
        }
        
        for remain == 0 {
            if length > i - left + 1 {
                length = i - left + 1
                start = left
                end = i
            }

            if cnt[s[left]] == 0 {
                remain++
            }
            cnt[s[left]]++
            left++
        }
    }

    if start == -1 {return ""}
    return s[start:end+1]
}