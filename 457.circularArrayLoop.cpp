class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0);
        vector<int> visitedBefore(n, 0);
        int color = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            color++;
            int slow = i;
            while(true) {
                if (visited[slow]>=1) break;
                visited[slow] = color;
                slow += nums[slow] + n*5000;
                slow %= n;
            }
            if (visited[slow] != color) continue;
            int len = 0;
            int begin = slow;
            int flag = nums[slow] > 0 ? 1 : -1;
            while(true) {
                slow += nums[slow] + n*5000;
                slow %= n;
                len++;
                if (nums[slow]*flag < 0) {break;}
                if (slow == begin) break;
            }
            if (nums[slow]*flag < 0) continue;
            if (len > 1) return true;
        }

        return false;
    }
};