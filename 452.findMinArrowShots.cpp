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

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points, 0, points.size()-1);
        if (points.size()<=1) return points.size();

        int start = points[0][0];
        int end = points[0][1];
        int arrows = 0;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0]>end) {
                arrows++;
                start = points[i][0];
                end = points[i][1];
            } else {
                start = points[i][0];
                if (points[i][1] <= end) {
                    end = points[i][1];
                }
            }
        }

        return arrows+1;
    }
};