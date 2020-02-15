class Solution {
public:

    double r,x,y;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double xx = x - r + uni(rng) * 2 * r;
        double yy = y - r + uni(rng) * 2 * r;

        while((xx-x)*(xx-x) + (yy-y)*(yy-y) > r*r) {
            xx = x - r + uni(rng) * 2 * r;
            yy = y - r + uni(rng) * 2 * r;
        }

        return vector<double>{xx, yy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */