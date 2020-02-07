class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size() - 1;
        if (citations.empty()) return 0;

        while(l<r) {
            int mid = l + (r-l)/2;
            int p = mid;
            if (citations.size()-p == citations[p]) return citations[p];
            if (citations.size()-p < citations[p]) {
                r = mid;
            }
            if (citations.size()-p > citations[p]) {
                l = mid + 1;
            }
        }

        if (citations[citations.size()-1] == 0) return 0;
        return citations.size()-l;
    }
};