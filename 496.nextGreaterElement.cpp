class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;

        for (auto num: nums2) {
            if (s.empty() || num <= s.top()) {
                s.push(num);
            } else {
                while(!s.empty()) {
                    if (s.top() < num) {
                        int small = s.top();
                        m[small] = num;
                        s.pop();
                    } else {
                        break;
                    }
                }
                s.push(num);
            }
        }
        vector<int> ans;

        for (auto num: nums1) {
            if (m.find(num) != m.end()) {
                ans.push_back(m[num]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};