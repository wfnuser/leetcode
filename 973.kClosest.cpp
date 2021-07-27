class Solution {
public:
    priority_queue<pair<int, int>> Q;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < k; i++) {
            Q.push(make_pair(points[i][0]*points[i][0]+points[i][1]*points[i][1], i));
        }
        for (int i = k; i < points.size(); i++) {
            if (points[i][0]*points[i][0]+points[i][1]*points[i][1] < Q.top().first) {
                Q.pop();
                Q.push(make_pair(points[i][0]*points[i][0]+points[i][1]*points[i][1], i));
            }
        }
        while(!Q.empty()) {
            ans.push_back(points[Q.top().second]);
            Q.pop();
        }

        return ans;
    }
};
