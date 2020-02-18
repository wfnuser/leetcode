class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int index = 0;
        int lastCnt = 0;

        for (int i = 0; i < data.size(); i++) {
            data[i] = data[i] & ((1<<8)-1);
        }

        while(index < data.size()) {
            int curNumber = data[index];
            int bit = 1 << 7;
            if (!(curNumber & bit)) {
                index++;
                lastCnt = 0;
                continue;
            } else {
                int cnt = 0;
                while(curNumber & bit) {
                    bit >>= 1;
                    cnt++;
                }
                if (cnt == 1) {
                    return false;
                }
                if (cnt > 4) {
                    return false;
                }
                if (index+cnt-1>=data.size()) {
                    return false;
                }
                for (int i=1; i<cnt; i++) {
                    if (!(data[index+i] & (1<<7))) return false;
                    if (data[index+i] & (1<<6)) return false;
                }
                index += cnt;
            }
        }

        return true;
    }
};