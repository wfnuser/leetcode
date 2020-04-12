class Solution {
public:
    const double EPS = 1e-7;

    bool isInLine(vector<double>& p, vector<int>& s, vector<int>& e) {
        double d1 = sqrt((p[0] - s[0])*(p[0] - s[0]) + (p[1] - s[1])*(p[1] - s[1])); 
        double d2 = sqrt((p[0] - e[0])*(p[0] - e[0]) + (p[1] - e[1])*(p[1] - e[1]));
        double d3 = sqrt((s[0] - e[0])*(s[0] - e[0]) + (s[1] - e[1])*(s[1] - e[1]));
        if(abs(d1 + d2 - d3) <= EPS) {
            return true;
        }
        return false;
    }    
    bool isInLine(vector<int>& p, vector<int>& s, vector<int>& e) {
        double d1 = sqrt((p[0] - s[0])*(p[0] - s[0]) + (p[1] - s[1])*(p[1] - s[1])); 
        double d2 = sqrt((p[0] - e[0])*(p[0] - e[0]) + (p[1] - e[1])*(p[1] - e[1]));
        double d3 = sqrt((s[0] - e[0])*(s[0] - e[0]) + (s[1] - e[1])*(s[1] - e[1]));
        if(abs(d1 + d2 - d3) <= EPS) {
            return true;
        }
        return false;
    }

    vector<double> getParam(const vector<int> &point1, const vector<int> &point2) {
        // A = y2-y1, B = x1-x2, C = x2*y1 - x1*y2
        double a = point2[1] - point1[1];
        double b = point1[0] - point2[0];
        double c = point2[0]*point1[1] - point1[0]*point2[1];
        return vector<double>{a, b, c};
    }

    bool isParallel(vector<int>& s1, vector<int>& e1, vector<int>& s2, vector<int>& e2) {
        double dy1 = (e1[1] - s1[1]);
        double dx1 = (e1[0] - s1[0]);
        double dy2 = (e2[1] - s2[1]);
        double dx2 = (e2[0] - s2[0]);

        return (abs(dy1*dx2 - dy2*dx1) < EPS);
    }

    vector<double> computeIntersectionOfParallel(vector<int>& s1, vector<int>& e1, vector<int>& s2, vector<int>& e2) {
        vector<vector<double>> res;
        if(isInLine(s1, s2, e2)) {
            res.push_back(vector<double>{double(s1[0]), double(s1[1])});
        }
        if(isInLine(e1, s2, e2)) {
            res.push_back(vector<double>{double(e1[0]), double(e1[1])});
        }
        if(isInLine(s2, s1, e1)) {
            res.push_back(vector<double>{double(s2[0]), double(s2[1])});
        }
        if(isInLine(e2, s1, e1)) {
            res.push_back(vector<double>{double(e2[0]), double(e2[1])});
        }
        if(res.size() == 0) {
            return vector<double>{};
        }
        sort(res.begin(), res.end(), [](const vector<double> &l, const vector<double> &r)->bool {
            return l[0] < r[0];
        });
        return res[0];
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        if (isParallel(start1, end1, start2, end2)) {
            return computeIntersectionOfParallel(start1, end1, start2, end2);
        }

        vector<double> p1 = getParam(start1, end1);
        vector<double> p2 = getParam(start2, end2);

        double x = double(p2[2]*p1[1] - p1[2]*p2[1]) / double(p1[0]*p2[1] - p2[0]*p1[1]);
        double y = double(p1[2]*p2[0] - p2[2]*p1[0]) / double(p1[0]*p2[1] - p2[0]*p1[1]);

        vector<double> point{x, y};
        if(isInLine(point, start1, end1) && isInLine(point, start2, end2)) {
            return point;
        }


        return vector<double>{};
    }
};