class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        queue<int> q;
        vector<int> cost(N, 65535);
        K -= 1;
        vector<vector<int>> path(N, vector<int>(N, 0));
        vector<vector<int>> next(N, vector<int>());

        for(auto it: times) {
            path[it[0]-1][it[1]-1] = it[2];
            next[it[0]-1].push_back(it[1]-1);
        }

        q.push(K);
        cost[K] = 0;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto n:next[cur]) {
                if(cost[n]>cost[cur]+path[cur][n]) {
                    cost[n] = cost[cur] + path[cur][n];
                    q.push(n);
                }
            }
        }
        int max = 0;
        for (auto it:cost) {
            if(it>=65535) return -1;
            if (max<it) max = it;
        }

        return max;
    }
};
