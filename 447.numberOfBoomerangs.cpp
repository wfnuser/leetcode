class Solution {
public:

    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int cnt = 0;

        unordered_map<int, unordered_map<int, int>> m;

        vector<vector<int>> distance(points.size(), vector<int>(points.size(), 0));
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j<points.size(); j++) {
                vector<int> point1 = points[i];
                vector<int> point2 = points[j];
                int distance = (point1[0] - point2[0])*(point1[0] - point2[0]) + (point1[1] - point2[1])*(point1[1] - point2[1]);
                m[i][distance]++;
                m[j][distance]++; 
            }
        }

        for (int i = 0; i < points.size(); i++) {
            for (auto nums: m[i]) {
                if (nums.second) {
                    cnt += nums.second*(nums.second-1);
                }
            }
        }

        return cnt;
    }
};