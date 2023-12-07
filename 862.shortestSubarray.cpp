class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> presum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }

        deque<int> q;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
          if (nums[i] >= k) return 1;

          while (!q.empty() && presum[i+1] - presum[q.front()] >= k) {
            ans = min(ans, i - q.front() + 1);
            q.pop_front();
          }

          while (!q.empty() && presum[i] <= presum[q.back()]) q.pop_back();

          q.push_back(i);
        }

        return ans <= n ? ans : -1;
    }
};