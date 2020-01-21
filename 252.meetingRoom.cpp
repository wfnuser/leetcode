class Solution {
public:

    void quick_sort(vector<vector<int>>& intervals, int l, int r) {
        if (l >= r) return;
        int slow = l;
        int fast = l+1;
        int pivot = intervals[l][0];
        int pivot2 = intervals[l][1];
        while(fast <= r) {
            if (intervals[fast][0] <= pivot) {
                slow++;
                int tmp = intervals[fast][0];
                intervals[fast][0] = intervals[slow][0];
                intervals[slow][0] = tmp;
                tmp = intervals[fast][1];
                intervals[fast][1] = intervals[slow][1];
                intervals[slow][1] = tmp;
                fast++;
            } else {
                fast++;
            }
        }
        intervals[l][0] = intervals[slow][0];
        intervals[slow][0] = pivot;
        intervals[l][1] = intervals[slow][1];
        intervals[slow][1] = pivot2;

        quick_sort(intervals, l, slow-1);
        quick_sort(intervals, slow+1, r);
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        quick_sort(intervals, 0, intervals.size()-1);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i-1][1] > intervals[i][0]) {return false;}
        }

        return true;
    }
};