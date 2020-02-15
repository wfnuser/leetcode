class Solution {
public:
    vector<vector<int>> rects;
    vector<int> areas;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int area = 0;
        for (auto rect: rects) {
            area += (rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
            areas.push_back(area);
        }
    }
    
    vector<int> pick() {
        int r = rand() % areas.back();
        int right = areas.size()-1;
        int left = 0;
        while(left < right) {
            int mid = left + (right-left)/2;
            if (r>=areas[mid]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        int dx;
        if (this->rects[left][2]-this->rects[left][0] == 0) {
            dx = 0;
        } else {
            dx = rand() % (this->rects[left][2]-this->rects[left][0]+1);
        }
        int dy;
        if (this->rects[left][3]-this->rects[left][1] == 0) {
            dy = 0;
        } else {
            dy = rand() % (this->rects[left][3]-this->rects[left][1]+1);
        }

        return vector<int>{this->rects[left][0]+dx, this->rects[left][1]+dy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */