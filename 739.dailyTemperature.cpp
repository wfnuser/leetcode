class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> S; // (index, temperature)
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int temp = temperatures[i];
            while (!S.empty()) {
                pair<int, int> top = S.top();
                if (top.second < temp)  {
                    ans[top.first] = (i - top.first);
                    S.pop();
                } else {
                    break;
                }
            }
            S.push(make_pair(i, temp));
        }

        return ans;
    }
};