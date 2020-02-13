class Solution {
public:
    void sort(vector<vector<int>>& intervals, int left, int right) {
        if (left>=right) return;
        int slow = left;
        vector<int> pivot = intervals[left];
        int fast = left+1;

        while(fast <= right) {
            if (intervals[fast][0] < pivot[0] || (intervals[fast][0] == pivot[0] && intervals[fast][1] > pivot[1])) {
                int tmp;
                tmp = intervals[slow+1][0];
                intervals[slow+1][0] = intervals[fast][0];
                intervals[fast][0] = tmp;
                
                tmp = intervals[slow+1][1];
                intervals[slow+1][1] = intervals[fast][1];
                intervals[fast][1] = tmp;

                slow++;
            }
            fast++;
        }

        int tmp = intervals[slow][0];
        intervals[slow][0] = intervals[left][0];
        intervals[left][0] = tmp;
        
        tmp = intervals[slow][1];
        intervals[slow][1] = intervals[left][1];
        intervals[left][1] = tmp;

        sort(intervals, left, slow-1);
        sort(intervals, slow+1, right);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals, 0, intervals.size()-1);
        int pre = 0;
        int cnt = 1;
        if (intervals.size() == 0) return 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[pre][1]) {
                pre = i;
                cnt++;
            } else {
                if (intervals[i][1] <= intervals[pre][1]) {
                    pre = i;
                }
            }
        }

        return intervals.size()-cnt;
    }
};