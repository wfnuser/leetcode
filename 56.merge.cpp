class Solution {
public:
    void sort(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) return;
        int slow = left; 
        int fast = slow+1;
        int pivot0 = intervals[slow][0];
        while(fast<=right) {
            if (intervals[fast][0] < pivot0) {
                slow++;
                int tmp = intervals[fast][0];
                intervals[fast][0] = intervals[slow][0];
                intervals[slow][0] = tmp; 
                tmp = intervals[fast][1];
                intervals[fast][1] = intervals[slow][1];
                intervals[slow][1] = tmp; 
            }                
            fast++;
        }
        int tmp = intervals[left][0];
        intervals[left][0] = intervals[slow][0];
        intervals[slow][0] = tmp; 
        tmp = intervals[left][1];
        intervals[left][1] = intervals[slow][1];
        intervals[slow][1] = tmp;

        sort(intervals, left, slow-1);
        sort(intervals, slow+1, right); 
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals; 
        sort(intervals, 0, intervals.size()-1);
        vector<vector<int>> ans;
        // [[2,3],[5,5],[2,2],[3,4],[3,4]]\n
        // [[2,3],[2,2],[3,3],[1,3],[5,7],[2,2],[4,6]]\n

        int preL = intervals[0][0];
        int preR = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int curL = intervals[i][0];
            int curR = intervals[i][1];

            if (curL > preR) {
                vector<int> v{ preL, preR }; 
                ans.push_back(v);
                preL = curL;
                preR = curR;
            } else {
                if (preR<=curR) preR = curR;
            }
        }

        vector<int> v{ preL, preR }; 
        ans.push_back(v);

        return ans;
    }
};

