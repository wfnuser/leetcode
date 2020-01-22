class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;

        for (auto num: nums1) {
            m1[num]++;
        }
        for (auto num: nums2) {
            m2[num]++;
        }
        vector<int> ans;
        for (auto m: m1) {
            for (int i = 0; i < min(m.second, m2[m.first]); i++) {
                ans.push_back(m.first);
            }
        }
        
        return ans;
    }
};