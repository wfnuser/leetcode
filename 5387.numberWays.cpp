typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
  int numberWays(vector<vector<int>>& hats) {
    int n = hats.size();
    vector<ll> dp(1 << n);
    dp[0] = 1;
    vector<set<int>> s(41);
    for (int i = 0; i < n; ++i)
      for (int hat : hats[i])
        s[hat].insert(i);
    for (int i = 1; i <= 40; ++i) {
      vector<ll> ndp(dp);
      for (int state = (1 << n) - 1; state >= 0; --state) {
        for (int person : s[i]) {
          if (state & (1 << person))
            continue;
          int nxt = state + (1 << person);
          ndp[nxt] += dp[state];
          ndp[nxt] %= MOD;
        }
      }
      swap(dp, ndp);
    }
    return dp[(1 << n) - 1];
  }
};