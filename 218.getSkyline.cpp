class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> borders;
        vector<vector<int>> ans;

        for (auto build: buildings) {
            borders.insert(make_pair(build[0], -build[2]));
            borders.insert(make_pair(build[1], build[2]));
        }

        multiset<int> heights({0});
        vector<int> last = {0, 0};
        for (auto border: borders) {
            if (border.second < 0) {
                heights.insert(-border.second);
            } else {
                heights.erase(heights.find(border.second));
            }

            auto maxHeight = *heights.rbegin();

            if (maxHeight != last[1]) {
                last[0] = border.first;
                last[1] = maxHeight;

                ans.push_back(last);
            }
        }

        return ans;
    }
};