bool canWinDFS(int bits, int distance, int maxChoosableInteger) {
    if (mem[bits] != 0) {
        return mem[bits] == 1;
    }

    bool result = false;
    for (int cur = maxChoosableInteger; cur > 0; cur--) {
        int curBit = 1 << (cur - 1);
        if ((bits & curBit) == 0) {
            if (cur >= distance || !canWin(bits | curBit, distance - cur,
                                           maxChoosableInteger, dp)) {
                result = true;
                break;
            }
        }
    }

    mem[bits] = result ? 1 : 2;
    return result;
}