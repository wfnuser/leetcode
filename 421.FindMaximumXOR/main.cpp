class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;
        for (int i = 31; i>=0; i--) {
            mask |= 1<<i;
            unordered_set<int> s;
            for (auto num: nums) {
                s.insert(num & mask);
            }
            
            int tmp = ans | (1<<i);
            for (auto num: nums) {
                int x = (num & mask) ^ tmp;
                if (s.count(x)) {
                    ans |= (1<<i);
                    break;
                }
            }
        }

        return ans;
    }
};
