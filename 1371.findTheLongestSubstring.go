func findTheLongestSubstring(s string) int {
    ans := 0;
    status := 0;
    pos := make([]int, 32);

    for i := 0; i < len(pos); i++ {
        pos[i] = -1;
    }
    pos[0] = 0;

    for i := 0; i < len(s); i++ {
        switch s[i] {
            case 'a':
                status ^= 1 << 0;
            case 'e':
                status ^= 1 << 1;
            case 'i':
                status ^= 1 << 2;
            case 'o':
                status ^= 1 << 3;
            case 'u':
                status ^= 1 << 4;
        }

        if pos[status] == -1 {
            pos[status] = i + 1;
        } else {
            if (i + 1 - pos[status] - ans) > 0 { ans = i + 1 - pos[status] } 
        }
    }

    return ans;
}