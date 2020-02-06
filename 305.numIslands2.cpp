class Solution {
public:

    vector<int> father;
    vector<int> ans;

    int find(int pos) {
        if (pos != father[pos]) father[pos] = find(father[pos]);
        return father[pos];
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> graph(m, vector<int>(n, 0));
        father = vector<int>(m*n, 0);

        for (auto position: positions) {
            int i = position[0];
            int j = position[1];

            if (graph[i][j]) {
                ans.push_back(ans.back());
                continue;
            }
            graph[i][j] = 1;
            father[i*n+j] = i*n+j;

            int dx[4] = {-1,0,0,1};
            int dy[4] = {0,-1,1,0};
            set<int> parents;
            vector<int> targets;
            int root = i*n+j;
            targets.push_back(root);

            for (int d = 0; d <= 3; d++) {
                int ii = i + dx[d];
                int jj = j + dy[d];
                if (ii < 0 || jj < 0 || ii >=m || jj >= n) continue;
                if (graph[ii][jj] == 0) continue;
                int p = find(ii*n+jj);
                parents.insert(p);
                targets.push_back(ii*n+jj);
                if (p<root) root = p;
            }
            if (ans.empty()) ans.push_back(1);
            else ans.push_back(ans.back()+1-parents.size());
            
            for(auto target: targets) {
                father[find(target)] = root;
            }
        }

        return ans;
    }
};