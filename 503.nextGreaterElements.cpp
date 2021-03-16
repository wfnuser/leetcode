class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<pair<int, int>> st;

        for (int i = 0; i < 2*nums.size(); i++) {
            int num = nums[i%nums.size()];
            if (st.empty() || st.top().first >= num) {
                st.push(make_pair(num, i%nums.size()));
            } else {
                while(!st.empty()) {
                    auto top = st.top();
                    if (top.first < num) {
                        st.pop();
                        ans[top.second] = num;
                    } else {
                        break;
                    }
                }
                st.push(make_pair(num, i%nums.size()));
            }
        }

        return ans;
    }
};