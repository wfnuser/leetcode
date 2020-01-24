class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int m = houses.size();
        int n = heaters.size();
        int ans = 0;
        int r = 0;
        int i = 0;
        int j = 0;
        while( i < m && j < n) {
            if (houses[i] <= heaters[j]) {
                r = heaters[j] - houses[i];
                i += 1;
            } else if(j < n - 1) {
                r = min(heaters[j + 1] - houses[i], houses[i] - heaters[j]);
                if (houses[i] < heaters[j + 1]) {
                    i += 1;
                }
                else {
                    j += 1;
                }
            }
            else {
                r = houses[i] - heaters[j];
                i += 1;
            }
            ans = max(ans, r);
        }
        return ans;
    }
};