// 二分搜索优化

class Solution {
public:
    int range = 0;
    vector<int> weights;

    Solution(vector<int>& w) {
        for (auto w_ : w) {
            range += w_;
            weights.push_back(range);
        }
    }
    
    int pickIndex() {
        int rnd = rand() % range;

        int left = 0;
        int right = weights.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (rnd < weights[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
