class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<int> primary;
        unordered_map<int, int> isPrimary;
        
        for (int i = 2; i < 100000; i++) {
            int j = 2;
            for (j = 2; j < sqrt(i); j++) {
                if (i % j == 0) break;
            }
            if (j == i || (i % j) != 0) {
                primary.push_back(i);
                isPrimary[i] = 1;
            }
        }
        
        int ans = 0;
        
        for (auto num: nums) {
            for (auto p: primary) {
                if (num % p == 0) {
                    int other = num / p;
                    if (other == p) break;
                    if (isPrimary[other] == 0 && (other != (long)p * p)) break;
                    ans += p;
                    ans += other;
                    ans += 1;
                    ans += num;
                    break;
                }
            }
        }
        
        return ans;
    }
};