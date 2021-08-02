class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0; 
        int r = 0;

        for (auto weight: weights) {
            l = max(l, weight);
            r += weight;
        }

        while(l<r) {
            int mid = (l+r)/2;
            if (isValid(weights, mid, days)) {
                r = mid;
            } else {
                l = mid+1;
            }
            
        }

        return r;
    }

    bool isValid(vector<int>& weights, int load, int days) {
        int sum = 0;
        int cnt = 0;
        for (auto weight: weights) {
            if (sum + weight <= load) {
                sum += weight;
            } else {
                sum = weight;
                cnt++;
            }
        }
        cnt++;
        return cnt <= days;
    }
};
