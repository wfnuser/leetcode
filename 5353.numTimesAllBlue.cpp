class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
    
        int last = 0;
        int ans = 0;
        unordered_map<int, int> cnt;
        
        for (auto pos: light) {
            if (pos > last) {
                cnt[pos] = cnt[last];
                last = pos;                
            }
            cnt[last] += 1;
            if (cnt[last] == last) ans++; 
        }
        
        return ans;
    }
};