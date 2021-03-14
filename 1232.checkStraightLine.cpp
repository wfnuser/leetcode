class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) return true;
        
        vector<int> p1 = coordinates[0];
        vector<int> p2 = coordinates[1];

        if (p1[0] == p2[0]) {
            for (auto point: coordinates) {
                if (point[0] != p1[0]) return false;
            }
            return true;
        }

        for (int i = 2; i < coordinates.size(); i++) {
            vector<int> point = coordinates[i];
            if (point[0] == p1[0] || point[0] == p2[0]) {
                return false;
            }
            if ((point[1] - p1[1])*(p1[0]-p2[0]) != (point[0] - p1[0])*(p1[1]-p2[1])) {
                return false;
            }
        }

        return true;

    }
};
