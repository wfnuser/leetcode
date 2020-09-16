class Solution {
public:

    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a%b);
    }

    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }

        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> m;
            int duplicates = 0;
            int tmp = 0;

            for (int j = i+1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    duplicates++;
                    continue;
                }

                if (points[i][0] == points[j][0]) {
                    tmp = max(tmp, ++m["ver"]);
                    continue;
                }
                if (points[i][1] == points[j][1]) {
                    tmp = max(tmp, ++m["hor"]);
                    continue;
                }

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                if (dy < 0) {
                    dy = -dy;
                    dx = -dx;
                } 
                int g = gcd(abs(dx), abs(dy));
                tmp = max(tmp, ++m[to_string(dx/g)+"_"+to_string(dy/g)]);
            }

            ans = max(ans, tmp+duplicates+1);
        }

        return ans;
    }
};