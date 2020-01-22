class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }

        unordered_map<int,int> m;
        for (int i = 0; i < nums2.size(); i++) {
            if (!m[nums2[i]]) {
                if (s.find(nums2[i]) != s.end()) {
                    m[nums2[i]] = 1;
                    ans.push_back(nums2[i]);
                }
            }
        }

        return ans;
    }
};