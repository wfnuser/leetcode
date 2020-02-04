class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;        

        multiset<pair<int, int>> m;
        for (auto interval: intervals) {
            m.insert(make_pair(interval[0], interval[1]));
            m.insert(make_pair(interval[1], interval[0]));
        }

        multiset<int> before;
        int num = 0;
        for (auto p: m) {
            if (p.second < p.first) {
                before.erase(before.find(p.second));
                num--;
            } else {
                before.insert(p.first);
                num++;
                ans = max(num, ans);
            }
        }

        return ans;
    }
};