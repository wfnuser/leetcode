// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;

        while (l < r) {
            long mid = ((long)l+(long)r)/2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l;
    }
};