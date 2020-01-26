class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res = {1, 2, 3, 4, 5};
        if (n <= 5) return res[n - 1];

        int ptr2 = 2, ptr3 = 1, ptr5 = 1;
        for (int i = 5; i < n; i++) {
            if (res[ptr2] * 2 == res.back()) ptr2++;
            if (res[ptr3] * 3 == res.back()) ptr3++;
            if (res[ptr5] * 5 == res.back()) ptr5++;
            int now1 = res[ptr2] * 2, now2 = res[ptr3] * 3, now3 = res[ptr5] * 5;
            res.push_back(min(now1, min(now2, now3)));
        }

        return res.back();
    }

};