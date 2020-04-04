class Solution {
public:
    
    unordered_map<int, int> cnt;
    unordered_map<int, int> group;
    
    void compute(int n) {
        int step = 0;
        
        while (n) {
            step += (n%10);
            n /= 10;
        }
        
        cnt[step]++;
    }
    
    int countLargestGroup(int n) {
        for (int i = 1; i <= n; i++) {
            compute(i);
        }
        
        int m = 0;
        for (auto e: cnt) {
            if (e.second >= m) m = e.second;
            group[e.second]++;
        }
        
        return group[m];
    }
};