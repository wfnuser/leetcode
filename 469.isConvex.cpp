class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        if (points.size() <= 2) return false;

        vector<int> u;
        vector<int> v;
        vector<int> w;

        int i = 2;
        int flag = 0;

        while(i <= points.size()+1) {
            w = points[i % points.size()];
            v = points[(i-1) % points.size()];
            u = points[i-2];

            int nf = -(w[1]-u[1])*(v[0]-u[0])+(v[1]-u[1])*(w[0]-u[0]);

            if (nf == 0) {
                i++;
                continue;
            }

            if (flag == 0) {
                flag = nf / abs(nf);
            } else {
                if (nf * flag < 0) return false;
                flag = nf / abs(nf);
            }
            
            i++;
        }

        return true;
    }
};