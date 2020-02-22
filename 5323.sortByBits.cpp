class Solution {
public:
    
    int cntOnes(int num) {
        int cnt = 0;
        while(num) {
            cnt++;
            // 使得最低位的1变成0，常用位运算操作
            num = num & (num-1);
        }
        return cnt;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> cnt;
        
        for (auto num: arr) {
            cnt[num] = cntOnes(num);
        }
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (cnt[a] > cnt[b]) return false;
            if (cnt[a] == cnt[b]) return a < b;
            return true;
        });
        
        return arr;
    }
};