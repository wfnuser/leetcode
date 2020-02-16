class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });

        int ans = 0;
        int visited[100050];
        for (int i = 0; i < 100050; ++i) visited[i] = 0;
        
        int idx = 0;
        int cnt = 0;
        for (int i = 0; i < events.size(); ++i) {
            for (int j = events[i][0]; j <= events[i][1]; ++j) {
                if (visited[j] == 0) {
                    visited[j] = 1;
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};