class Solution {
public:
    vector<int> constructRectangle(int area) {

        int s = sqrt(area);

        for (int i = s; i >= 1; i--) {
            if (area%i == 0) {
                return vector<int>{area/i, i};
            } 
        }
        return vector<int>{area, 1};
    }
};