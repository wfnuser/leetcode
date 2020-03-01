class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101] = {0};
        
        for (auto num: nums) {
            cnt[num]++;
        }
        
        
        int partial[101] = {0};
        partial[0] = 0;
        for (int i = 1; i <= 100; i++) {
            partial[i] = partial[i-1] + cnt[i-1];
        }
        
        vector<int> ans;
        
        for (auto num: nums) {
            ans.push_back(partial[num]);
        }
        
        return ans;
    }
};