class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        vector<int> extend(len+2, 0);

        for (int i = 0; i < len; i++) {
            extend[i+1] = flowerbed[i];
        }

        for (int i = 1; i <= len; i++) {
            if (extend[i-1] == 0 && extend[i] == 0 && extend[i+1] == 0) {
                extend[i] = 1;
                n--;
            }
        }

        return n <= 0;
    }
};
