class Solution {
public:
    int compute(int n) {
        int res = 0;
        while(n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        vector<int> sum = vector<int>(max(m, n), 0);
        for (int i = 0; i < max(m,n); i++) {
            sum[i] = compute(i);
        }

        int cnt = 0;
        queue<pair<int, int>> Q;
        Q.push(make_pair(0, 0));
        unordered_map<int, int> visited;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();
            if (visited[pos.first*n + pos.second]) continue;

            if (sum[pos.first] + sum[pos.second] > k) {
                continue;
            }
            cnt++;
            visited[pos.first * n + pos.second] = 1;

            for (int d = 0; d < 4; d++) {
                int i = pos.first + dx[d];
                int j = pos.second + dy[d];

                if (i < 0 || j < 0 || i >= m || j >= n) continue;
                if (visited[i*n + j]) continue;

                Q.push(make_pair(i, j));
            }
        }

        return cnt;
    }
};