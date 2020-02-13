class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        sort(citations.begin(), citations.end());

        int left = 0;
        int right = citations.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            int h = citations[mid];

            if (h == citations.size()-mid) {
                return h;
            }
            if (h > citations.size() - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (citations[citations.size()-1] == 0) return 0;
        return citations.size() - left;
    }
};